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

#ifndef MUTATIONOFJB_IFPIGGYCOMMAND_H
#define MUTATIONOFJB_IFPIGGYCOMMAND_H

#include "mutationofjb/commands/conditionalcommand.h"
#include "common/scummsys.h"
#include "common/str.h"

namespace MutationOfJB {

class ScriptParseContext;

class IfPiggyCommandParser : public ConditionalCommandParser {
public:
	bool parse(const Common::String &line, ScriptParseContext &parseCtx, Command *&command) override;
};

class IfPiggyCommand : public ConditionalCommand {
public:
	ExecuteResult execute(ScriptExecutionContext &scriptExecCtx) override;
	Common::String debugString() const override;

private:
};

}

#endif
