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

// Music class

#ifndef DRACI_MUSIC_H
#define DRACI_MUSIC_H

#include "audio/midiplayer.h"

namespace Draci {

// Taken from MADE, which took it from SAGA.

class MusicPlayer : public Audio::MidiPlayer {
public:
	MusicPlayer(const char *pathMask);

	void playSMF(int track, bool loop);
	void stop() override;

	// Overload Audio::MidiPlayer method
	void sendToChannel(byte channel, uint32 b) override;

protected:
	Common::String _pathMask;
	bool _isGM;

	int _track;
};

} // End of namespace Draci

#endif
