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

#ifndef BLADERUNNER_AMBIENT_SOUNDS_H
#define BLADERUNNER_AMBIENT_SOUNDS_H

#include "audio/audiostream.h"
#include "audio/mixer.h"

#include "common/str.h"

namespace BladeRunner {

class BladeRunnerEngine;
class SaveFileReadStream;
class SaveFileWriteStream;

class AmbientSounds {
	static const int kNonLoopingSounds                     = 25;
	static const int kLoopingSounds                        = 3;
	static const Audio::Mixer::SoundType kAmbientSoundType = Audio::Mixer::kPlainSoundType;

	struct NonLoopingSound {
		bool           isActive;
		Common::String name;
		int32          hash;
		int            audioPlayerTrack;
		uint32         delayMin;          // milliseconds
		uint32         delayMax;          // milliseconds
		uint32         nextPlayTimeStart; // milliseconds
		uint32         nextPlayTimeDiff;  // milliseconds
		int            volumeMin;
		int            volumeMax;
		int            volume;
		int            panStartMin;
		int            panStartMax;
		int            panEndMin;
		int            panEndMax;
		int            priority;
		int32          soundType; // new - not stored in saved games
	};

	struct LoopingSound {
		bool           isActive;
		Common::String name;
		int32          hash;
		int            audioPlayerTrack;
		int            volume;
		int            pan;
		int32          soundType; // new - not stored in saved games
	};

	BladeRunnerEngine *_vm;

	NonLoopingSound *_nonLoopingSounds;
	LoopingSound    *_loopingSounds;
	int              _ambientVolume;

public:
	AmbientSounds(BladeRunnerEngine *vm);
	~AmbientSounds();

	void addSound(
		int sfxId,
		uint32 delayMinSeconds, uint32 delayMaxSeconds,
		int volumeMin, int volumeMax,
		int panStartMin, int panStartMax,
		int panEndMin, int panEndMax,
		int priority, int unk
	);
	void removeNonLoopingSound(int sfxId, bool stopPlaying);
	void removeAllNonLoopingSounds(bool stopPlaying);

	void addSpeech(
		int actorId, int sentenceId,
		uint32 delayMinSeconds, uint32 delayMaxSeconds,
		int volumeMin, int volumeMax,
		int panStartMin, int panStartMax,
		int panEndMin, int panEndMax,
		int priority, int unk);
	void playSound(int sfxId, int volume, int panStart, int panEnd, int priority, Audio::Mixer::SoundType type = kAmbientSoundType);
	void playSpeech(int actorId, int sentenceId, int volume, int panStart, int panEnd, int priority);

	void addLoopingSound(int sfxId, int volume, int pan, uint32 delaySeconds, Audio::Mixer::SoundType type = kAmbientSoundType);
	void adjustLoopingSound(int sfxId, int volume, int pan, uint32 delaySeconds);
	// it seems there is little confusion in original code about delay parameter,
	// sometimes it is used as boolean in same way as stopPlaying from non looping
	void removeLoopingSound(int sfxId, uint32 delaySeconds);
	void removeAllLoopingSounds(uint32 delaySeconds);

	void tick();

	void setVolume(int volume);
	int getVolume() const;
	void playSample();

	void save(SaveFileWriteStream &f);
	void load(SaveFileReadStream &f);

private:
	int findAvailableNonLoopingTrack() const;
	int findNonLoopingTrackByHash(int32 hash) const;

	int findAvailableLoopingTrack() const;
	int findLoopingTrackByHash(int32 hash) const;

	void addSoundByName(
		const Common::String &name,
		uint32 delayMinSeconds, uint32 delayMaxSeconds,
		int volumeMin, int volumeMax,
		int panStartMin, int panStartMax,
		int panEndMin, int panEndMax,
		int priority, int unk);

	void removeNonLoopingSoundByIndex(int index, bool stopPlaying);
	void removeLoopingSoundByIndex(int index, uint32 delaySeconds);
};

} // End of namespace BladeRunner

#endif
