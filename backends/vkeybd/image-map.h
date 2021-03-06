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

#ifndef COMMON_IMAGEMAP_H
#define COMMON_IMAGEMAP_H

#include "common/scummsys.h"

#ifdef ENABLE_VKEYBD

#include "common/hashmap.h"
#include "common/hash-str.h"

namespace Common {

struct Polygon;

class ImageMap {
public:
	~ImageMap();

	Polygon *createArea(const String &id);
	void removeArea(const String &id);
	void removeAllAreas();
	String findMapArea(int16 x, int16 y);

protected:
	typedef HashMap<String, Polygon *> AreaMap;
	AreaMap _areas;
};


} // End of namespace Common

#endif // #ifdef ENABLE_VKEYBD

#endif // #ifndef COMMON_IMAGEMAP_H
