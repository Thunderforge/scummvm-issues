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

#ifndef TONY_MPAL_MPALUTILS
#define TONY_MPAL_MPALUTILS

#include "common/scummsys.h"
#include "tony/mpal/memory.h"

namespace Common {
	class SeekableReadStream;
}

namespace Tony {

namespace MPAL {

class RMRes {
protected:
	MpalHandle _h;
	byte *_buf;

public:
	RMRes(uint32 resID);
	virtual ~RMRes();

	// Attributes
	unsigned int size();
	const byte *dataPointer();
	bool isValid();

	// Casting for access to data
	operator const byte*();

	Common::SeekableReadStream *getReadStream();
};

class RMResRaw : public RMRes {
public:
	RMResRaw(uint32 resID);
	~RMResRaw() override;

	const byte *dataPointer();
	operator const byte*();

	int width();
	int height();
};

} // end of namespace MPAL

} // end of namespace Tony

#endif
