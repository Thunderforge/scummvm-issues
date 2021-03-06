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

#include "titanic/game/season_barrel.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CSeasonBarrel, CBackground)
	ON_MESSAGE(ChangeSeasonMsg)
	ON_MESSAGE(EnterViewMsg)
END_MESSAGE_MAP()

void CSeasonBarrel::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_unused, indent);
	file->writeNumberLine(_startFrame, indent);

	CBackground::save(file, indent);
}

void CSeasonBarrel::load(SimpleFile *file) {
	file->readNumber();
	_unused = file->readNumber();
	_startFrame = file->readNumber();
	CBackground::load(file);
}

bool CSeasonBarrel::ChangeSeasonMsg(CChangeSeasonMsg *msg) {
	if (_startFrame >= 28)
		_startFrame = 0;

	playMovie(_startFrame, _startFrame + 7, 0);
	_startFrame += 7;
	return true;
}

bool CSeasonBarrel::EnterViewMsg(CEnterViewMsg *msg) {
	loadFrame(_startFrame);
	return true;
}

} // End of namespace Titanic
