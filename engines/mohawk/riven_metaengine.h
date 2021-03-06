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

#ifndef MOHAWK_RIVEN_METAENGINE_H
#define MOHAWK_RIVEN_METAENGINE_H

#include "common/config-manager.h"
#include "common/language.h"

namespace Mohawk {

struct RivenLanguage {
	Common::Language language;
	const char *archiveSuffix;
};

class MohawkMetaEngine_Riven {
public:
	static void registerDefaultSettings();
	static const RivenLanguage *listLanguages();
};

} // End of namespace Mohawk

#endif // MOHAWK_RIVEN_METAENGINE_H
