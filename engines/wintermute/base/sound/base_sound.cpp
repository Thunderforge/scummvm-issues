/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/*
 * This file is based on WME Lite.
 * http://dead-code.org/redir.php?target=wmelite
 * Copyright (c) 2011 Jan Nedoma
 */

#include "engines/wintermute/base/sound/base_sound.h"
#include "engines/wintermute/base/base_game.h"
#include "engines/wintermute/base/sound/base_sound_manager.h"
#include "engines/wintermute/base/sound/base_sound_buffer.h"

namespace Wintermute {

IMPLEMENT_PERSISTENT(BaseSound, false)

BaseSound::BaseSound(BaseGame *inGame) : BaseClass(inGame) {
	_sound = nullptr;
	_soundFilename = "";

	_soundType = Audio::Mixer::kSFXSoundType;
	_soundStreamed = false;
	_soundLooping = false;
	_soundPlaying = false;
	_soundPaused = false;
	_soundFreezePaused = false;
	_soundPosition = 0;
	_soundPrivateVolume = 0;
	_soundLoopStart = 0;

	_sFXType = SFX_NONE;
	_sFXParam1 = _sFXParam2 = _sFXParam3 = _sFXParam4 = 0;
}

BaseSound::~BaseSound() {
	if (_sound) {
		_gameRef->_soundMgr->removeSound(_sound);
	}
	_sound = nullptr;
}

bool BaseSound::setSound(const Common::String &filename, Audio::Mixer::SoundType type, bool streamed) {
	if (_sound) {
		_gameRef->_soundMgr->removeSound(_sound);
		_sound = nullptr;
	}
	_soundFilename = Common::String(); // Set empty

	_sound = _gameRef->_soundMgr->addSound(filename, type, streamed);
	if (_sound) {
		_soundFilename = filename;

		_soundType = type;
		_soundStreamed = streamed;

		return STATUS_OK;
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::setSoundSimple() {
	_sound = _gameRef->_soundMgr->addSound(_soundFilename, _soundType, _soundStreamed);
	if (_sound) {
		if (_soundPosition) {
			_sound->setPosition(_soundPosition);
		}
		_sound->setLooping(_soundLooping);
		_sound->setPrivateVolume(_soundPrivateVolume);
		_sound->setLoopStart(_soundLoopStart);
		_sound->setFreezePaused(_soundFreezePaused);
		if (_soundPlaying) {
			return _sound->resume();
		} else {
			return STATUS_OK;
		}
	} else {
		return STATUS_FAILED;
	}
}

uint32 BaseSound::getLength() {
	if (_sound) {
		return _sound->getLength();
	} else {
		return 0;
	}
}

bool BaseSound::play(bool looping) {
	if (_sound) {
		_soundPaused = false;
		return _sound->play(looping, _soundPosition);
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::stop() {
	if (_sound) {
		_soundPaused = false;
		return _sound->stop();
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::pause(bool freezePaused) {
	if (_sound) {
		_soundPaused = true;
		if (freezePaused) {
			_sound->setFreezePaused(true);
		}
		return _sound->pause();
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::resume() {
	if (_sound && _soundPaused) {
		_soundPaused = false;
		return _sound->resume();
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::persist(BasePersistenceManager *persistMgr) {
	if (persistMgr->getIsSaving() && _sound) {
		_soundPlaying = _sound->isPlaying();
		_soundLooping = _sound->isLooping();
		_soundPrivateVolume = _sound->getPrivateVolume();
		if (_soundPlaying) {
			_soundPosition = _sound->getPosition();
		}
		_soundLoopStart = _sound->getLoopStart();
		_soundFreezePaused = _sound->isFreezePaused();
	}

	if (persistMgr->getIsSaving()) {
		_sFXType = SFX_NONE;
		_sFXParam1 = _sFXParam2 = _sFXParam3 = _sFXParam4 = 0;
	}

	persistMgr->transferPtr(TMEMBER_PTR(_gameRef));

	persistMgr->transferString(TMEMBER(_soundFilename));
	persistMgr->transferBool(TMEMBER(_soundLooping));
	persistMgr->transferBool(TMEMBER(_soundPaused));
	persistMgr->transferBool(TMEMBER(_soundFreezePaused));
	persistMgr->transferBool(TMEMBER(_soundPlaying));
	persistMgr->transferUint32(TMEMBER(_soundPosition));
	persistMgr->transferSint32(TMEMBER(_soundPrivateVolume));
	persistMgr->transferBool(TMEMBER(_soundStreamed));
	persistMgr->transferSint32(TMEMBER_INT(_soundType));
	persistMgr->transferUint32(TMEMBER(_soundLoopStart));

	return STATUS_OK;
}

bool BaseSound::isPlaying() {
	return _sound && _sound->isPlaying();
}

bool BaseSound::isPaused() {
	return _sound && _soundPaused;
}

bool BaseSound::setPositionTime(uint32 time) {
	if (!_sound) {
		return STATUS_FAILED;
	}
	_soundPosition = time;
	bool ret = _sound->setPosition(_soundPosition);
	if (_sound->isPlaying()) {
		_soundPosition = 0;
	}
	return ret;
}

uint32 BaseSound::getPositionTime() {
	if (!_sound) {
		return 0;
	}

	if (!_sound->isPlaying()) {
		return 0;
	} else {
		return _sound->getPosition();
	}
}

bool BaseSound::setVolumePercent(int percent) {
	if (!_sound) {
		return STATUS_FAILED;
	} else {
		return _sound->setPrivateVolume(percent * 255 / 100);
	}
}

bool BaseSound::setVolume(int volume) {
	if (!_sound) {
		return STATUS_FAILED;
	} else {
		return _sound->setPrivateVolume(volume);
	}
}

bool BaseSound::setPrivateVolume(int volume) {
	if (!_sound) {
		return STATUS_FAILED;
	} else {
		_sound->setPrivateVolume(volume);
		return STATUS_OK;
	}
}

int BaseSound::getVolumePercent() {
	if (!_sound) {
		return 0;
	} else {
		return _sound->getPrivateVolume() * 100 / 255;
	}
}

int BaseSound::getVolume() {
	if (!_sound) {
		return 0;
	} else {
		return _sound->getPrivateVolume();
	}
}

bool BaseSound::setLoopStart(uint32 pos) {
	if (!_sound) {
		return STATUS_FAILED;
	} else {
		_sound->setLoopStart(pos);
		return STATUS_OK;
	}
}

bool BaseSound::setPan(float pan) {
	if (_sound) {
		return _sound->setPan(pan);
	} else {
		return STATUS_FAILED;
	}
}

bool BaseSound::applyFX(TSFXType type, float param1, float param2, float param3, float param4) {
	if (!_sound) {
		return STATUS_OK;
	}

	if (type != _sFXType || param1 != _sFXParam1 || param2 != _sFXParam2 || param3 != _sFXParam3 || param4 != _sFXParam4) {
		bool ret = _sound->applyFX(type, param1, param2, param3, param4);

		_sFXType = type;
		_sFXParam1 = param1;
		_sFXParam2 = param2;
		_sFXParam3 = param3;
		_sFXParam4 = param4;

		return ret;
	}
	return STATUS_OK;
}

} // End of namespace Wintermute
