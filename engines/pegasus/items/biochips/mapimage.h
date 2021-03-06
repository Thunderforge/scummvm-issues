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

#ifndef PEGASUS_ITEMS_BIOCHIPS_MAPIMAGE_H
#define PEGASUS_ITEMS_BIOCHIPS_MAPIMAGE_H

#include "pegasus/elements.h"
#include "pegasus/surface.h"
#include "pegasus/util.h"
#include "pegasus/neighborhood/mars/constants.h"

namespace Common {
	class ReadStream;
	class WriteStream;
}

namespace Pegasus {

class MapImage : public DisplayElement {
public:
	MapImage();
	~MapImage() override {}

	void writeToStream(Common::WriteStream *);
	void readFromStream(Common::ReadStream *);

	void loadGearRoomIfNecessary();
	void loadMazeIfNecessary();
	void unloadImage();
	void moveToMapLocation(const NeighborhoodID, const RoomID, const DirectionConstant);

	void draw(const Common::Rect &) override;

	bool anyFlagSet() { return _mappedRooms.anyFlagSet(); }

	static const uint32 kNumMappingRooms = (kMars39 - kMars35 + 1) + (kMars60 - kMars60 + 1) +
			(kMarsMaze200 - kMarsMaze004 + 1);
	static const uint32 kNumMappingFlags = kNumMappingRooms * 4;

protected:
	enum MapArea {
		kMapNoArea,
		kMapMaze,
		kMapGearRoom
	};

	void addFlagToMask(const int flag);
	void getRevealedRects(const uint32, Common::Rect &);
	void drawPlayer();

	MapArea _whichArea;

	FlagsArray<byte, kNumMappingFlags> _mappedRooms;

	uint32 _darkGreen, _lightGreen;

	Surface _mapImage, _mapMask;
};

} // End of namespace Pegasus

#endif
