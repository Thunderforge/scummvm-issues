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

#ifndef TITANIC_PARROT_PERCH_HOLDER_H
#define TITANIC_PARROT_PERCH_HOLDER_H

#include "titanic/core/multi_drop_target.h"

namespace Titanic {

class CParrotPerchHolder : public CMultiDropTarget {
	DECLARE_MESSAGE_MAP;
	bool MouseButtonDownMsg(CMouseButtonDownMsg *msg);
	bool StatusChangeMsg(CStatusChangeMsg *msg);
	bool DropObjectMsg(CDropObjectMsg *msg);
	bool ActMsg(CActMsg *msg);
public:
	CLASSDEF;

	/**
	 * Save the data for the class to file
	 */
	void save(SimpleFile *file, int indent) override;

	/**
	 * Load the data for the class from file
	 */
	void load(SimpleFile *file) override;
};

} // End of namespace Titanic

#endif /* TITANIC_PARROT_PERCH_HOLDER_H */
