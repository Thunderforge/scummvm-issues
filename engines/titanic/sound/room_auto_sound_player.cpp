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

#include "titanic/sound/room_auto_sound_player.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CRoomAutoSoundPlayer, CAutoSoundPlayer)
	ON_MESSAGE(EnterRoomMsg)
	ON_MESSAGE(LeaveRoomMsg)
END_MESSAGE_MAP()

void CRoomAutoSoundPlayer::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	CAutoSoundPlayer::save(file, indent);
}

void CRoomAutoSoundPlayer::load(SimpleFile *file) {
	file->readNumber();
	CAutoSoundPlayer::load(file);
}

bool CRoomAutoSoundPlayer::EnterRoomMsg(CEnterRoomMsg *msg) {
	CRoomItem *room = findRoom();
	if (room == msg->_newRoom) {
		CTurnOn onMsg;
		onMsg.execute(this);
	}

	return true;
}

bool CRoomAutoSoundPlayer::LeaveRoomMsg(CLeaveRoomMsg *msg) {
	CRoomItem *room = findRoom();
	if (room == msg->_oldRoom) {
		CTurnOff offMsg;
		offMsg.execute(this);
	}

	return true;
}

} // End of namespace Titanic
