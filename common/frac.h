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

#ifndef COMMON_FRAC_H
#define COMMON_FRAC_H

#include "common/scummsys.h"

/**
 * @defgroup common_frac Fixed-point fractions
 * @ingroup common
 *
 * @brief  API for fixed-point fractions.
 *
 * @{
 */

/**
 * The precision of the fractional (fixed-point) type that is defined below.
 * Normally, you should never need to modify this value.
 */
enum {
	FRAC_BITS = 16,
	FRAC_LO_MASK = ((1L << FRAC_BITS) - 1),
	FRAC_HI_MASK = ((1L << FRAC_BITS) - 1) << FRAC_BITS,

	FRAC_ONE = (1L << FRAC_BITS),		// 1.0
	FRAC_HALF = (1L << (FRAC_BITS-1))	// 0.5
};

/**
 * Fixed-point fractions, used by the sound rate converter and other code.
 */
typedef int32 frac_t;

inline frac_t doubleToFrac(double value) { return (frac_t)(value * FRAC_ONE); }
inline double fracToDouble(frac_t value) { return ((double)value) / FRAC_ONE; }

inline frac_t intToFrac(int16 value) { return value * (1 << FRAC_BITS); }
inline int16 fracToInt(frac_t value) { return value / (1 << FRAC_BITS); }

/** @} */

#endif
