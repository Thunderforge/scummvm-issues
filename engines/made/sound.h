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

#ifndef MADE_SOUND_H
#define MADE_SOUND_H

#include "common/array.h"

namespace Made {

class ManholeEgaSoundDecompressor {
public:
	void decompress(byte *source, byte *dest, uint32 size);
protected:
	byte *_source, *_dest;
	uint32 _size;
	uint16 _bitBuffer;
	int _bitsLeft;
	int32 _sample1, _sample2, _sample3, _sample4;
	bool _writeFlag;
	bool _eof;
	int _mode;
	int getBit();
	void update0();
	void update1();
	void update2();
	void update3();
};

struct SoundEnergyItem {
	uint32 position;
	byte energy;
};

typedef Common::Array<SoundEnergyItem> SoundEnergyArray;


// Persistent data for decompressSound(). When calling decompressSound()
// repeatedly (for the same stream), pass the same SoundDecoderData object to
// ensure decoding properly resumes.
class SoundDecoderData {
public:
	SoundDecoderData() {
		memset(_soundBuffer, 0x80, sizeof(_soundBuffer));
		_prevSample = 0;
	}

	byte _soundBuffer[1025];
	int16 _prevSample;
};

void decompressSound(byte *source, byte *dest, uint16 chunkSize, uint16 chunkCount, SoundEnergyArray *soundEnergyArray = NULL, SoundDecoderData *decoderData = NULL);

} // End of namespace Made

#endif /* MADE_H */
