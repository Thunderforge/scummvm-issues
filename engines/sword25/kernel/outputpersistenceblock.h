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

/*
 * This code is based on Broken Sword 2.5 engine
 *
 * Copyright (c) Malte Thiesen, Daniel Queteschiner and Michael Elsdoerfer
 *
 * Licensed under GNU GPL v2
 *
 */

#ifndef SWORD25_OUTPUTPERSISTENCEBLOCK_H
#define SWORD25_OUTPUTPERSISTENCEBLOCK_H

#include "sword25/kernel/common.h"
#include "sword25/kernel/persistenceblock.h"

namespace Sword25 {

class OutputPersistenceBlock : public PersistenceBlock {
public:
	OutputPersistenceBlock();

	void write(const void *data, uint32 size);
	void write(int32 value);
	void write(uint32 value);
	void write(float value);
	void write(bool value);
	void writeString(const Common::String &string);
	void writeByteArray(Common::Array<byte> &value);

	const void *getData() const {
		return &_data[0];
	}
	uint getDataSize() const {
		return _data.size();
	}

private:
	void writeMarker(byte marker);
	void rawWrite(const void *dataPtr, size_t size);

	Common::Array<byte> _data;
};

} // End of namespace Sword25

#endif
