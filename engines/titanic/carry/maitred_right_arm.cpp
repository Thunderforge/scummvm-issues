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

#include "titanic/carry/maitred_right_arm.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CMaitreDRightArm, CArm)
	ON_MESSAGE(DropZoneLostObjectMsg)
END_MESSAGE_MAP()

void CMaitreDRightArm::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	CArm::save(file, indent);
}

void CMaitreDRightArm::load(SimpleFile *file) {
	file->readNumber();
	CArm::load(file);
}

bool CMaitreDRightArm::DropZoneLostObjectMsg(CDropZoneLostObjectMsg *msg) {
	CActMsg actMsg("LoseArm");
	actMsg.execute("MaitreDBody");
	actMsg.execute("MaitreD Arm Holder");
	_canTake = true;
	return true;
}

} // End of namespace Titanic
