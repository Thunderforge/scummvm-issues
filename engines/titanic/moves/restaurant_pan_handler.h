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

#ifndef TITANIC_RESTAURANT_PAN_HANDLER_H
#define TITANIC_RESTAURANT_PAN_HANDLER_H

#include "titanic/moves/move_player_to.h"

namespace Titanic {

class CRestaurantPanHandler : public CMovePlayerTo {
	DECLARE_MESSAGE_MAP;
	bool ArmPickedUpFromTableMsg(CArmPickedUpFromTableMsg *msg);
	bool MouseButtonDownMsg(CMouseButtonDownMsg *msg);
protected:
	CString _armDestination;
	CString _armlessDestination;
public:
	static bool _armPickedUp;
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

#endif /* TITANIC_RESTAURANT_PAN_HANDLER_H */
