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

#ifndef KYRA_SOUND_DIGITAL_MR_H
#define KYRA_SOUND_DIGITAL_MR_H

#include "audio/mixer.h"

namespace Common {
class SeekableReadStream;
} // End of namespace Common

namespace Audio {
class SeekableAudioStream;
} // End of namespace Audio

namespace Kyra {

// Digital Audio
class KyraAudioStream;
class KyraEngine_MR;

/**
 * Digital audio output device.
 *
 * This is just used for Kyrandia 3.
 */
class SoundDigital_MR {
public:
	SoundDigital_MR(KyraEngine_MR *vm, Audio::Mixer *mixer);
	~SoundDigital_MR();

	/**
	 * Plays a sound.
	 *
	 * @param filename  file to be played
	 * @param priority  priority of the sound
	 * @param type      type
	 * @param volume    channel volume
	 * @param loop      true if the sound should loop (endlessly)
	 * @param channel   tell the sound player to use a specific channel for playback
	 *
	 * @return channel playing the sound
	 */
	int playSound(const char *filename, uint8 priority, Audio::Mixer::SoundType type, int volume = 255, bool loop = false, int channel = -1);

	/**
	 * Checks if a given channel is playing a sound.
	 *
	 * @param channel channel number to check
	 * @return true if playing, else false
	 */
	bool isPlaying(int channel);

	/**
	 * Stop the playback of a sound in the given
	 * channel.
	 *
	 * @param channel channel number
	 */
	void stopSound(int channel);

	/**
	 * Stops playback of all sounds.
	 */
	void stopAllSounds();

	/**
	 * Makes the sound in a given channel
	 * fading out.
	 *
	 * @param channel channel number
	 * @param ticks   fadeout time
	 */
	void beginFadeOut(int channel, int ticks);
private:
	KyraEngine_MR *_vm;
	Audio::Mixer *_mixer;

	struct Sound {
		Audio::SoundHandle handle;

		char filename[16];
		uint8 priority;
		KyraAudioStream *stream;
	} _sounds[4];

	struct AudioCodecs {
		const char *fileext;
		Audio::SeekableAudioStream *(*streamFunc)(
			Common::SeekableReadStream *stream,
			DisposeAfterUse::Flag disposeAfterUse);
	};

	static const AudioCodecs _supportedCodecs[];
};

} // End of namespace Kyra

#endif
