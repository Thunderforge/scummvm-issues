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

#ifndef MUTATIONOFJB_TALKCOMMAND_H
#define MUTATIONOFJB_TALKCOMMAND_H

#include "mutationofjb/commands/seqcommand.h"
#include "common/scummsys.h"
#include "mutationofjb/tasks/task.h"

namespace MutationOfJB {

class ConversationTask;

class TalkCommandParser : public SeqCommandParser {
public:
	bool parse(const Common::String &line, ScriptParseContext &parseCtx, Command *&command) override;
};

class TalkCommand : public SeqCommand {
public:
	enum Mode {
		NORMAL_MODE,
		RAY_AND_BUTTLEG_MODE,
		CARNIVAL_TICKET_SELLER_MODE
	};

	TalkCommand(Mode mode) : _mode(mode) {}
	ExecuteResult execute(ScriptExecutionContext &scriptExecCtx) override;
	Common::String debugString() const override;

private:
	Mode _mode;
	TaskPtr _task;
};

}

#endif
