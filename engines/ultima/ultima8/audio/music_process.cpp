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

#include "ultima/ultima8/audio/music_process.h"

namespace Ultima {
namespace Ultima8 {

DEFINE_RUNTIME_CLASSTYPE_CODE(MusicProcess)

MusicProcess *MusicProcess::_theMusicProcess = nullptr;

MusicProcess::MusicProcess() {
	_theMusicProcess = this;
	_type = 1; // persistent
	setRunPaused();
}

MusicProcess::~MusicProcess() {
	_theMusicProcess = nullptr;
}

uint32 MusicProcess::I_stopMusic(const uint8 * /*args*/,
								 unsigned int /*argsize*/) {
	if (_theMusicProcess) _theMusicProcess->playMusic_internal(0);
	return 0;
}

uint32 MusicProcess::I_playMusic(const uint8 *args,
								 unsigned int /*argsize*/) {
	ARG_UINT8(song);
	if (_theMusicProcess) _theMusicProcess->playMusic(song & 0x7F);
	return 0;
}


uint32 MusicProcess::I_pauseMusic(const uint8 *args,
								 unsigned int /*argsize*/) {
	// This is only used in Crusader: No Regret.
	if (_theMusicProcess) _theMusicProcess->pauseMusic();
	return 0;
}

uint32 MusicProcess::I_unpauseMusic(const uint8 *args,
								 unsigned int /*argsize*/) {
	// This is only used in Crusader: No Regret.
	if (_theMusicProcess) _theMusicProcess->unpauseMusic();
	return 0;
}


} // End of namespace Ultima8
} // End of namespace Ultima
