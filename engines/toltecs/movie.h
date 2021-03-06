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

#ifndef TOLTECS_MOVIE_H
#define TOLTECS_MOVIE_H

#include "audio/mixer.h"	// for Audio::SoundHandle

namespace Audio {
class QueuingAudioStream;
}

namespace Toltecs {

class MoviePlayer {

public:
	MoviePlayer(ToltecsEngine *vm);
	~MoviePlayer();

	void playMovie(uint resIndex);

	bool isPlaying() { return _isPlaying; }

protected:
	ToltecsEngine *_vm;
	Audio::QueuingAudioStream *_audioStream;
	Audio::SoundHandle _audioStreamHandle;

	bool _isPlaying;

	uint32 _framesPerSoundChunk;
	int32 _lastPrefetchOfs, _endPos;

	void unpackPalette(byte *source, byte *dest, int elemCount, int elemSize);
	void unpackRle(byte *source, byte *dest);

	void fetchAudioChunks();

	bool handleInput();

};

} // End of namespace Toltecs

#endif /* TOLTECS_MOVIE_H */
