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

#include "titanic/carry/vision_centre.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CVisionCentre, CBrain)
	ON_MESSAGE(PuzzleSolvedMsg)
	ON_MESSAGE(MouseButtonDownMsg)
	ON_MESSAGE(MouseDragStartMsg)
END_MESSAGE_MAP()

void CVisionCentre::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	CBrain::save(file, indent);
}

void CVisionCentre::load(SimpleFile *file) {
	file->readNumber();
	CBrain::load(file);
}

bool CVisionCentre::PuzzleSolvedMsg(CPuzzleSolvedMsg *msg) {
	_canTake = true;
	return true;
}

bool CVisionCentre::MouseButtonDownMsg(CMouseButtonDownMsg *msg) {
	if (_canTake) {
		return CBrain::MouseButtonDownMsg(msg);
	} else {
		petDisplayMessage(1, NICE_IF_TAKE_BUT_CANT);
		return true;
	}
}

bool CVisionCentre::MouseDragStartMsg(CMouseDragStartMsg *msg) {
	if (_canTake) {
		return CBrain::MouseDragStartMsg(msg);
	} else {
		petDisplayMessage(1, NICE_IF_TAKE_BUT_CANT);
		return true;
	}
}

} // End of namespace Titanic
