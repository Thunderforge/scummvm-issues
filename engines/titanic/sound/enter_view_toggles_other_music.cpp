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

#include "titanic/sound/enter_view_toggles_other_music.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CEnterViewTogglesOtherMusic, CTriggerAutoMusicPlayer)
	ON_MESSAGE(EnterViewMsg)
END_MESSAGE_MAP()

CEnterViewTogglesOtherMusic::CEnterViewTogglesOtherMusic() :
		CTriggerAutoMusicPlayer(), _value(2) {
}

void CEnterViewTogglesOtherMusic::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	file->writeNumberLine(_value, indent);

	CTriggerAutoMusicPlayer::save(file, indent);
}

void CEnterViewTogglesOtherMusic::load(SimpleFile *file) {
	file->readNumber();
	_value = file->readNumber();

	CTriggerAutoMusicPlayer::load(file);
}

bool CEnterViewTogglesOtherMusic::EnterViewMsg(CEnterViewMsg *msg) {
	CViewItem *view = findView();
	if (view == msg->_newView) {
		CTriggerAutoMusicPlayerMsg triggerMsg;
		triggerMsg._value = _value;
		triggerMsg.execute(this);
	}

	return true;
}

} // End of namespace Titanic
