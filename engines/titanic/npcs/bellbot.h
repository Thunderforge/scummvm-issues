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

#ifndef TITANIC_BELLBOT_H
#define TITANIC_BELLBOT_H

#include "titanic/npcs/true_talk_npc.h"

namespace Titanic {

class CBellBot : public CTrueTalkNPC {
	DECLARE_MESSAGE_MAP;
	bool OnSummonBotMsg(COnSummonBotMsg *msg);
	bool EnterViewMsg(CEnterViewMsg *msg);
	bool LeaveViewMsg(CLeaveViewMsg *msg);
	bool MovieEndMsg(CMovieEndMsg *msg);
	bool Use(CUse *msg);
	bool DismissBotMsg(CDismissBotMsg *msg);
	bool TrueTalkTriggerActionMsg(CTrueTalkTriggerActionMsg *msg);
	bool MovieFrameMsg(CMovieFrameMsg *msg);
	bool PutBotBackInHisBoxMsg(CPutBotBackInHisBoxMsg *msg);
	bool NPCPlayIdleAnimationMsg(CNPCPlayIdleAnimationMsg *msg);
	bool NPCPlayTalkingAnimationMsg(CNPCPlayTalkingAnimationMsg *msg);
	bool TimerMsg(CTimerMsg *msg);
	bool TrueTalkGetStateValueMsg(CTrueTalkGetStateValueMsg *msg);
	bool TrueTalkNotifySpeechEndedMsg(CTrueTalkNotifySpeechEndedMsg *msg);
private:
	int _field108;
public:
	CLASSDEF;
	CBellBot();

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

#endif /* TITANIC_BELLBOT_H */
