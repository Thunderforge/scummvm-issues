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

#ifndef TITANIC_NAV_HELMET_ON_H
#define TITANIC_NAV_HELMET_ON_H

#include "titanic/game/nav_helmet.h"
#include "titanic/messages/pet_messages.h"

namespace Titanic {

class CNavHelmetOn : public CNavHelmet {
	DECLARE_MESSAGE_MAP;
	bool MouseButtonUpMsg(CMouseButtonUpMsg *msg);
private:
	CString _target;
public:
	CLASSDEF;
	CNavHelmetOn() : CNavHelmet(), _target("NULL") {}

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

#endif /* TITANIC_NAV_HELMET_ON_H */
