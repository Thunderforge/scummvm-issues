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

#include "common/debug.h"
#include "common/stream.h"
#include "common/textconsole.h"

#include "pegasus/neighborhood/turn.h"

namespace Pegasus {

void TurnTable::loadFromStream(Common::SeekableReadStream *stream) {
	uint32 count = stream->readUint32BE();
	_entries.resize(count);

	for (uint32 i = 0; i < count; i++) {
		_entries[i].room = stream->readUint16BE();
		_entries[i].direction = stream->readByte();
		_entries[i].turnDirection = stream->readByte();
		_entries[i].altCode = stream->readByte();
		stream->readByte(); // alignment
		_entries[i].endDirection = stream->readByte();
		stream->readByte(); // alignment
		debug(0, "Turn[%d]: %d %d %d %d %d", i, _entries[i].room, _entries[i].direction,
				_entries[i].turnDirection, _entries[i].altCode, _entries[i].endDirection);
	}
}

void TurnTable::clear() {
	_entries.clear();
}

TurnTable::Entry TurnTable::findEntry(RoomID room, DirectionConstant direction, TurnDirection turnDirection, AlternateID altCode) {
	for (uint32 i = 0; i < _entries.size(); i++)
		if (_entries[i].room == room && _entries[i].direction == direction && _entries[i].turnDirection == turnDirection && _entries[i].altCode == altCode)
			return _entries[i];

	return Entry();
}

} // End of namespace Pegasus
