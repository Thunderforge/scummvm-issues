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

#ifndef WINTERMUTE_SCSTACK_H
#define WINTERMUTE_SCSTACK_H


#include "engines/wintermute/base/base.h"
#include "engines/wintermute/coll_templ.h"
#include "engines/wintermute/persistent.h"

namespace Wintermute {

class ScValue;
class BaseScriptable;

class ScStack : public BaseClass {
public:
	ScValue *getAt(int Index);
	ScValue *getPushValue();
	DECLARE_PERSISTENT(ScStack, BaseClass)
	void pushNative(BaseScriptable *val, bool persistent);
	void pushString(const char *val);
	void pushBool(bool val);
	void pushInt(int val);
	void pushFloat(double val);
	void pushNULL();
	void correctParams(uint32 expectedParams);
	ScValue *getTop();
	void push(ScValue *val);
	ScValue *pop();
	ScStack(BaseGame *inGame);
	~ScStack() override;
	BaseArray<ScValue *> _values;
	int32 _sP;

};

} // End of namespace Wintermute

#endif
