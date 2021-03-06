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

#ifndef PEGASUS_COMPASS_H
#define PEGASUS_COMPASS_H

#include "pegasus/fader.h"
#include "pegasus/surface.h"

namespace Pegasus {

// Compass is defined with 0 as north, 90 east, 180 south, 270 west.
// Clockwise rotation increases the angle, counterclockwise rotation decreases the angle.

class Compass : public FaderAnimation {
public:
	Compass();
	~Compass() override;

	void initCompass();
	void deallocateCompass();
	bool isCompassValid() const { return _compassImage.isSurfaceValid(); }

	void setFaderValue(const int32) override;

protected:
	void draw(const Common::Rect &) override;

	Frame _compassImage;
};

extern Compass *g_compass;

} // End of namespace Pegasus

#endif
