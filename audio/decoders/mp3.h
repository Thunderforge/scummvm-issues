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

/**
 * @file
 * Sound decoder used in engines:
 *  - agos
 *  - draci
 *  - glk
 *  - kyra
 *  - mohawk
 *  - queen
 *  - saga
 *  - sci
 *  - scumm
 *  - sword1
 *  - sword2
 *  - titanic
 *  - touche
 *  - tucker
 */

#ifndef AUDIO_MP3_H
#define AUDIO_MP3_H

#include "common/scummsys.h"
#include "common/types.h"

#ifdef USE_MAD

namespace Common {
class SeekableReadStream;
}

namespace Audio {

class PacketizedAudioStream;
class SeekableAudioStream;

/**
 * Create a new SeekableAudioStream from the MP3 data in the given stream.
 * Allows for seeking (which is why we require a SeekableReadStream).
 *
 * @param stream			the SeekableReadStream from which to read the MP3 data
 * @param disposeAfterUse	whether to delete the stream after use
 * @return	a new SeekableAudioStream, or NULL, if an error occurred
 */
SeekableAudioStream *makeMP3Stream(
	Common::SeekableReadStream *stream,
	DisposeAfterUse::Flag disposeAfterUse);

/**
 * Create a new PacketizedAudioStream from the first packet in the given
 * stream. It does not own the packet and must be queued again later.
 *
 * @param firstPacket		the SeekableReadStream from which to read the MP3 data
 * @return	a new PacketizedAudioStream
 */
PacketizedAudioStream *makePacketizedMP3Stream(
	Common::SeekableReadStream &firstPacket);

/**
 * Create a new PacketizedAudioStream for a given number of channels
 * and sample rate.
 *
 * @param firstPacket		the SeekableReadStream from which to read the MP3 data
 * @return	a new PacketizedAudioStream
 */
PacketizedAudioStream *makePacketizedMP3Stream(
	uint channels, uint rate);

} // End of namespace Audio

#endif // #ifdef USE_MAD
#endif // #ifndef AUDIO_MP3_H
