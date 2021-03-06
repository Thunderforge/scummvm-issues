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

#ifndef TITANIC_DOOR_AUTO_SOUND_EVENT_H
#define TITANIC_DOOR_AUTO_SOUND_EVENT_H

#include "titanic/messages/auto_sound_event.h"

namespace Titanic {

class CDoorAutoSoundEvent : public CAutoSoundEvent {
	DECLARE_MESSAGE_MAP;
	bool PreEnterNodeMsg(CPreEnterNodeMsg *msg);
	bool LeaveNodeMsg(CLeaveNodeMsg *msg);
	bool TimerMsg(CTimerMsg *msg);
public:
	CString _string1;
	CString _string2;
	int _fieldDC;
	int _fieldE0;
public:
	CLASSDEF;
	CDoorAutoSoundEvent() : CAutoSoundEvent(),
		_string1("z#44.wav"), _string2("z#43.wav"), _fieldDC(25), _fieldE0(25) {
	}

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

#endif /* TITANIC_DOOR_AUTO_SOUND_EVENT_H */
