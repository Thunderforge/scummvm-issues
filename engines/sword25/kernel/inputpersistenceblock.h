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

#ifndef SWORD25_INPUTPERSISTENCEBLOCK_H
#define SWORD25_INPUTPERSISTENCEBLOCK_H

#include "common/array.h"
#include "sword25/kernel/common.h"
#include "sword25/kernel/persistenceblock.h"

namespace Sword25 {

class InputPersistenceBlock : public PersistenceBlock {
public:
	enum ErrorState {
		NONE,
		END_OF_DATA,
		OUT_OF_SYNC
	};

	InputPersistenceBlock(const void *data, uint dataLength, int version);
	virtual ~InputPersistenceBlock();

	void read(int16 &value);
	void read(int32 &value);
	void read(uint32 &value);
	void read(float &value);
	void read(bool &value);
	void readString(Common::String &value);
	void readByteArray(Common::Array<byte> &value);

	bool isGood() const {
		return _errorState == NONE;
	}
	ErrorState getErrorState() const {
		return _errorState;
	}

	int getVersion() const { return _version; }

private:
	bool checkMarker(byte marker);
	bool checkBlockSize(int size);

	Common::Array<byte> _data;
	Common::Array<byte>::const_iterator _iter;
	ErrorState _errorState;

	int _version;
};

} // End of namespace Sword25

#endif
