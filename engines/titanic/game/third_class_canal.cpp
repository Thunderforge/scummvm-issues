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

#include "titanic/game/third_class_canal.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CThirdClassCanal, CBackground)
	ON_MESSAGE(MouseButtonDownMsg)
END_MESSAGE_MAP()

void CThirdClassCanal::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	CBackground::save(file, indent);
}

void CThirdClassCanal::load(SimpleFile *file) {
	file->readNumber();
	CBackground::load(file);
}

bool CThirdClassCanal::MouseButtonDownMsg(CMouseButtonDownMsg *msg) {
	petDisplayMessage(AREA_OFF_LIMIT_TO_PASSENGERS);
	return true;
}

} // End of namespace Titanic
