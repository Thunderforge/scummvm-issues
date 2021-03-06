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

#include "titanic/sound/auto_music_player.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CAutoMusicPlayer, CAutoMusicPlayerBase)
	ON_MESSAGE(EnterRoomMsg)
	ON_MESSAGE(LeaveRoomMsg)
END_MESSAGE_MAP()

CAutoMusicPlayer::CAutoMusicPlayer() : CAutoMusicPlayerBase() {
}

void CAutoMusicPlayer::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	file->writeQuotedLine(_leaveRoomSound, indent);

	CAutoMusicPlayerBase::save(file, indent);
}

void CAutoMusicPlayer::load(SimpleFile *file) {
	file->readNumber();
	_leaveRoomSound = file->readString();

	CAutoMusicPlayerBase::load(file);
}

bool CAutoMusicPlayer::EnterRoomMsg(CEnterRoomMsg *msg) {
	if (!_isEnabled) {
		CRoomItem *room = findRoom();
		if (msg->_newRoom == room)
			addTimer(2000);
	}

	return true;
}

bool CAutoMusicPlayer::LeaveRoomMsg(CLeaveRoomMsg *msg) {
	if (_isEnabled) {
		CRoomItem *room = findRoom();
		if (msg->_oldRoom == room) {
			CChangeMusicMsg changeMsg;
			changeMsg._action = MUSIC_STOP;
			changeMsg.execute(this);
		}
	}

	if (!_leaveRoomSound.empty())
		playSound(_leaveRoomSound);

	return true;
}

} // End of namespace Titanic
