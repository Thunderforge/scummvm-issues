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

#ifndef MUTATIONOFJB_PLAYANIMATIONCOMMAND_H
#define MUTATIONOFJB_PLAYANIMATIONCOMMAND_H

#include "mutationofjb/commands/seqcommand.h"
#include "common/str.h"

namespace MutationOfJB {

class PlayAnimationCommandParser : public SeqCommandParser {
public:
	PlayAnimationCommandParser() {}

	bool parse(const Common::String &line, ScriptParseContext &parseCtx, Command *&command) override;
};

class PlayAnimationCommand : public SeqCommand {
public:
	PlayAnimationCommand(int fromFrame, int toFrame) : _fromFrame(fromFrame), _toFrame(toFrame) {}
	const Common::String &getName() const;

	ExecuteResult execute(ScriptExecutionContext &scriptExecCtx) override;
	Common::String debugString() const override;
private:
	int _fromFrame;
	int _toFrame;
};

}

#endif
