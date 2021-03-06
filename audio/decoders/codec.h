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

#ifndef AUDIO_DECODERS_CODEC_H
#define AUDIO_DECODERS_CODEC_H

namespace Common {
	class SeekableReadStream;
}

namespace Audio {

class AudioStream;

/**
 * @deprecated The old method of handling audio codecs that rely
 * on the state remaining the same between calls. This should
 * only be used for old code.
 *
 * DEPRECATED; USE PacketizedAudioStream INSTEAD!
 */
class Codec {
public:
	Codec() {}
	virtual ~Codec() {}

	virtual AudioStream *decodeFrame(Common::SeekableReadStream &data) = 0;
};

} // End of namespace Audio

#endif
