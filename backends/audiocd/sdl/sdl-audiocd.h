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

#ifndef BACKENDS_AUDIOCD_SDL_H
#define BACKENDS_AUDIOCD_SDL_H

#include "backends/audiocd/default/default-audiocd.h"

#include "backends/platform/sdl/sdl-sys.h"

#if !SDL_VERSION_ATLEAST(2, 0, 0)

/**
 * The SDL audio cd manager. Implements real audio cd playback.
 */
class SdlAudioCDManager : public DefaultAudioCDManager {
public:
	SdlAudioCDManager();
	virtual ~SdlAudioCDManager();

	bool open() override;
	void close() override;
	bool play(int track, int numLoops, int startFrame, int duration, bool onlyEmulate,
			Audio::Mixer::SoundType soundType) override;
	void stop() override;
	bool isPlaying() const override;
	void update() override;

protected:
	bool openCD(int drive) override;

	SDL_CD *_cdrom;
	int _cdTrack, _cdNumLoops, _cdStartFrame, _cdDuration;
	uint32 _cdEndTime, _cdStopTime;
};

#endif // !SDL_VERSION_ATLEAST(2, 0, 0)

#endif
