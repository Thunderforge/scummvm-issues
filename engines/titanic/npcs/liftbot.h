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

#ifndef TITANIC_LIFTBOT_H
#define TITANIC_LIFTBOT_H

#include "titanic/npcs/true_talk_npc.h"
#include "titanic/messages/messages.h"

namespace Titanic {

class CLiftBot : public CTrueTalkNPC {
	DECLARE_MESSAGE_MAP;
	bool TextInputMsg(CTextInputMsg *msg);
	bool EnterViewMsg(CEnterViewMsg *msg);
	bool EnterRoomMsg(CEnterRoomMsg *msg);
	bool TrueTalkTriggerActionMsg(CTrueTalkTriggerActionMsg *msg);
	bool LeaveRoomMsg(CLeaveRoomMsg *msg);
	bool TurnOff(CTurnOff *msg);
	bool TurnOn(CTurnOn *msg);
	bool LeaveViewMsg(CLeaveViewMsg *msg);
	bool TrueTalkGetStateValueMsg(CTrueTalkGetStateValueMsg *msg);
	bool NPCPlayTalkingAnimationMsg(CNPCPlayTalkingAnimationMsg *msg);
	bool ActMsg(CActMsg *msg);
private:
	static bool _flag;
	static bool _enabled;
private:
	int _field108;
public:
	CLASSDEF;
	CLiftBot();

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

#endif /* TITANIC_LIFTBOT_H */
