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

#ifndef ULTIMA_SHARED_ACTIONS_PASS_H
#define ULTIMA_SHARED_ACTIONS_PASS_H

#include "ultima/shared/actions/action.h"
#include "ultima/shared/engine/messages.h"

namespace Ultima {
namespace Shared {
namespace Actions {

class Pass : public Action {
	DECLARE_MESSAGE_MAP;
	bool PassMsg(CPassMsg *msg);
private:
	const char *&_text;
public:
	CLASSDEF;

	/**
	 * Constructor
	 */
	Pass(TreeItem *parent, const char *&text) : Action(parent), _text(text) {}

	/**
	 * Destructor
	 */
	~Pass() override {}
};

} // End of namespace Actions
} // End of namespace Shared
} // End of namespace Ultima

#endif
