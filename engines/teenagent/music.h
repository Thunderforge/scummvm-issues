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

#ifndef TEEN_MUSIC_H
#define TEEN_MUSIC_H

#include "audio/mods/paula.h"
#include "common/array.h"

namespace TeenAgent {

class TeenAgentEngine;

class MusicPlayer : public Audio::Paula {
public:
	MusicPlayer(TeenAgentEngine *vm);
	~MusicPlayer() override;

	bool load(int id);
	int getId() const { return _id; }

	void start();
	void stop();

private:
	TeenAgentEngine *_vm;

	int _id;

	struct Row {
		struct Channel {
			byte sample;
			byte volume;
			byte note;
			Channel(): sample(0), volume(0x40), note(0) {}
		} channels[3];
	};

	struct Sample {
		byte *data;
		uint size;
		Sample(): data(0), size(0) {}
		~Sample() { delete[] data; }

		void resize(uint s) {
			if (s != size) {
				delete[] data;
				data = new byte[s];
				size = s;
			}
		}
		void clear() {
			delete[] data;
			data = 0;
			size = 0;
		}
	} _samples[256];

	Common::Array<Row> _rows;
	uint _currRow;

	void interrupt() override;
};

} // End of namespace Teen

#endif // TEEN_MUSIC_H
