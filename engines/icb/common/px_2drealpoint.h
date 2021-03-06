/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
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

#ifndef ICB_PX_2DREALPOINT_H_INCLUDED
#define ICB_PX_2DREALPOINT_H_INCLUDED

#include "engines/icb/common/px_rcutypes.h"
#include "engines/icb/common/px_common.h"

namespace ICB {

// A 2D point on a plane with endpoints stored as floating point.
class px2DRealPoint {
public:
	// Default constructor and destructor.
	px2DRealPoint() {
		m_fX = REAL_ZERO;
		m_fY = REAL_ZERO;
	}
	~px2DRealPoint() { ; }

	// Alternative constructor that allows the point to be initialized.
	px2DRealPoint(PXreal fX, PXreal fY) {
		m_fX = fX;
		m_fY = fY;
	}

	// Gets and sets.
	void SetX(PXreal fX) { m_fX = fX; }
	void SetY(PXreal fY) { m_fY = fY; }
	PXreal GetX() const { return m_fX; }
	PXreal GetY() const { return m_fY; }

	// This allows the values of a point to be set after it has been created.
	void Set(PXreal fX, PXreal fY) {
		m_fX = fX;
		m_fY = fY;
	}

private:
	PXreal m_fX, m_fY; // The point.
};

} // End of namespace ICB

#endif // #ifndef PX_2DREALPOINT_H_INCLUDED
