/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1995-1997 Presto Studios, Inc.
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

#ifndef PEGASUS_FADER_H
#define PEGASUS_FADER_H

#include "pegasus/elements.h"
#include "pegasus/timers.h"

namespace Pegasus {

class Fader;

class FaderMoveSpec {
friend class Fader;
public:
	FaderMoveSpec() {
		_faderScale = kDefaultTimeScale;
		_numKnots = 0;
	}

	FaderMoveSpec(const TimeScale scale) {
		_faderScale = scale;
		_numKnots = 0;
	}

	void setFaderScale(const TimeScale scale) { _faderScale = scale; }
	TimeScale getFaderScale() const { return _faderScale; }

	void makeOneKnotFaderSpec(const int32);
	void makeTwoKnotFaderSpec(const TimeScale, const TimeValue, const int32, const TimeValue, const int32);

	void insertFaderKnot(const TimeValue, const int32);

	uint32 getNumKnots() const { return _numKnots; }
	TimeValue getNthKnotTime(const uint32 index) const { return _knots[index].knotTime; }
	int32 getNthKnotValue(const uint32 index) const { return _knots[index].knotValue; }

protected:
	struct FaderKnot {
		TimeValue knotTime;
		int32 knotValue;
	};

	TimeScale _faderScale;
	uint32 _numKnots;

	static const uint32 kMaxFaderKnots = 20;
	FaderKnot _knots[kMaxFaderKnots];
};

class Fader : public IdlerTimeBase {
public:
	Fader();
	~Fader() override {}

	virtual void setFaderValue(const int32);
	int32 getFaderValue() const { return _currentValue; }
	virtual void startFader(const FaderMoveSpec &);
	virtual void startFaderSync(const FaderMoveSpec &);
	virtual void loopFader(const FaderMoveSpec &);
	virtual void stopFader();
	virtual bool isFading() { return isRunning(); }

	void pauseFader();
	void continueFader();

	void getCurrentFaderMove(FaderMoveSpec &spec) { spec = _currentFaderMove; }

protected:
	bool initFaderMove(const FaderMoveSpec &);
	void timeChanged(const TimeValue) override;

	int32 _currentValue;
	FaderMoveSpec _currentFaderMove;
};

class FaderAnimation : public DisplayElement, public Fader {
public:
	FaderAnimation(const DisplayElementID id) : DisplayElement(id) {}
	~FaderAnimation() override {}

	void setFaderValue(const int32) override;
};

class Sound;

class SoundFader : public Fader {
friend class Sound;
public:
	SoundFader();
	~SoundFader() override {}

	void setFaderValue(const int32) override;

	void setMasterVolume(const uint16);
	uint16 getMasterVolume() const { return _masterVolume; }

protected:
	void attachSound(Sound *);

	Sound *_sound;
	uint16 _masterVolume;
};

} // End of namespace Pegasus

#endif
