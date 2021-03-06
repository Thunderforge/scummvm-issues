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

#ifndef SCUMM_HELP_H
#define SCUMM_HELP_H

#include "common/str.h"
#include "common/ustr.h"
#include "common/platform.h"

namespace Scumm {

#define HELP_NUM_LINES 15

class ScummHelp {
protected:
	typedef Common::String String;
	typedef Common::U32String U32String;

public:
	static int numPages(byte gameId);
	static void updateStrings(byte gameId, byte version, Common::Platform platform,
			int page, U32String &title, U32String *&key, U32String *&dsc);
};

} // End of namespace Scumm

#endif
