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

#ifndef TOWNS_AUDIO_H
#define TOWNS_AUDIO_H

namespace Audio {
class Mixer;
}

class TownsAudioInterfaceInternal;

class TownsAudioInterfacePluginDriver {
public:
	virtual ~TownsAudioInterfacePluginDriver() {}
	virtual void timerCallback(int timerId) = 0;
};

class TownsAudioInterface {
public:
	TownsAudioInterface(Audio::Mixer *mixer, TownsAudioInterfacePluginDriver *driver, bool externalMutex = false);
	~TownsAudioInterface();

	enum ErrorCode {
		kSuccess = 0,
		kInvalidChannel,
		kUnavailable,
		kArgumentOutOfRange,
		kNotImplemented,
		kOutOfWaveMemory,
		kInvalidWaveTable,
		kChannelNotReserved,
		kNoteOutOfRangeForInstrument,
		kNoMatchingWaveTable,
		kDuplicateWaveTable
	};

	bool init();

	ErrorCode callback(int command, ...);

	void setMusicVolume(int volume);
	void setSoundEffectVolume(int volume);
	// Defines the channels used as sound effect channels for the purpose of ScummVM GUI volume control.
	// The first 6 bits are the 6 fm channels. The next 8 bits are pcm channels.
	void setSoundEffectChanMask(int mask);

private:
	TownsAudioInterfaceInternal *_intf;
};

#endif
