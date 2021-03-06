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

#ifndef PINK_CURSOR_ACTOR_H
#define PINK_CURSOR_ACTOR_H

#include "common/debug.h"

#include "pink/pink.h"
#include "pink/objects/actions/action_cel.h"
#include "pink/objects/actors/actor.h"

namespace Pink {

class CursorActor : public Actor {
public:
	void toConsole() const override {
		debugC(6, kPinkDebugLoadingObjects, "CursorActor: _name = %s", _name.c_str());
		for (uint i = 0; i < _actions.size(); ++i) {
			_actions[i]->toConsole();
		}
	}

	bool isCursor() const override {
		return true;
	}

	void setCursorItem(const Common::String &name, Common::Point point) {
		if (!_action || _action->getName() != name)
			setAction(name);
		static_cast<ActionCEL*>(_action)->setCenter(point);
	}
};

} // End of namespace Pink

#endif
