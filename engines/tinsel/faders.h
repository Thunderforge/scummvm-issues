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
 * Data structures used by the fader and flasher processes
 */

#ifndef TINSEL_FADERS_H		// prevent multiple includes
#define TINSEL_FADERS_H

#include "tinsel/dw.h"	// for SCNHANDLE
#include "tinsel/tinsel.h"

namespace Tinsel {

/**
 * Number of iterations in a fade out.
 */
// FIXME: There seems to be some confusion in Tinsel 2 whether this should be 9 or 6
#define COUNTOUT_COUNT 6

/*----------------------------------------------------------------------*\
|*                      Fader Function Prototypes                       *|
\*----------------------------------------------------------------------*/

void FadeOutMedium();
void FadeOutFast();
void FadeInMedium();
void FadeInFast();
void PokeInTagColor();

} // End of namespace Tinsel

#endif		// TINSEL_FADERS_H
