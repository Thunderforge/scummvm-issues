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

#ifndef PEGASUS_NEIGHBORHOOD_MARS_SHUTTLEENERGYMETER_H
#define PEGASUS_NEIGHBORHOOD_MARS_SHUTTLEENERGYMETER_H

#include "pegasus/fader.h"
#include "pegasus/surface.h"

namespace Pegasus {

static const int32 kFullShuttleEnergy = 100;
// Low is 20 percent
static const int32 kLowShuttleEnergy = kFullShuttleEnergy * 20 / 100;

static const int32 kMinDampingEnergy = 15;
static const int32 kMinGravitonEnergy = 63;

static const TimeScale kTractorBeamScale = kFifteenTicksPerSecond;
static const TimeValue kTractorBeamTime = kFiveSeconds * kTractorBeamScale;
static const int32 kTractorBeamEnergy = kLowShuttleEnergy;

class ShuttleEnergyMeter : public FaderAnimation {
public:
	ShuttleEnergyMeter();
	~ShuttleEnergyMeter() override {}

	void initShuttleEnergyMeter();
	void disposeShuttleEnergyMeter();

	void powerUpMeter();

	void setEnergyValue(const int32);
	int32 getEnergyValue() const;

	void dropEnergyValue(const int32);

	void drainForTractorBeam();

	bool enoughEnergyForTractorBeam() const;

	void draw(const Common::Rect &) override;

protected:
	Surface _meterImage;
	Surface _lowWarning;
};

} // End of namespace Pegasus

#endif
