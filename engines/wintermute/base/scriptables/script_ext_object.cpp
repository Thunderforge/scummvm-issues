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

/*
 * This file is based on WME Lite.
 * http://dead-code.org/redir.php?target=wmelite
 * Copyright (c) 2011 Jan Nedoma
 */

#include "engines/wintermute/base/scriptables/script_ext_object.h"
#include "engines/wintermute/base/scriptables/script_value.h"
#include "engines/wintermute/base/scriptables/script_stack.h"

namespace Wintermute {

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_PERSISTENT(SXObject, false)

BaseScriptable *makeSXObject(BaseGame *inGame, ScStack *stack) {
	return new SXObject(inGame, stack);
}

//////////////////////////////////////////////////////////////////////////
SXObject::SXObject(BaseGame *inGame, ScStack *stack) : BaseObject(inGame) {
	int numParams = stack->pop()->getInt(0);
	for (int i = 0; i < numParams; i++) {
		addScript(stack->pop()->getString());
	}
}


//////////////////////////////////////////////////////////////////////////
SXObject::~SXObject() {

}


//////////////////////////////////////////////////////////////////////////
bool SXObject::persist(BasePersistenceManager *persistMgr) {
	BaseObject::persist(persistMgr);

	return STATUS_OK;
}

} // End of namespace Wintermute
