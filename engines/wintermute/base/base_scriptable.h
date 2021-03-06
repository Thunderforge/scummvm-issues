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

#ifndef WINTERMUTE_BASE_SCRIPTABLE_H
#define WINTERMUTE_BASE_SCRIPTABLE_H


#include "engines/wintermute/base/base_named_object.h"
#include "engines/wintermute/persistent.h"

namespace Wintermute {

class ScValue;
class ScStack;
class ScScript;

class BaseScriptable : public BaseNamedObject {
public:
	virtual ScScript *invokeMethodThread(const char *methodName);
	DECLARE_PERSISTENT(BaseScriptable, BaseNamedObject)

	BaseScriptable(BaseGame *inGame, bool noValue = false, bool persistable = true);
	~BaseScriptable() override;

	// high level scripting interface
	virtual bool canHandleMethod(const char *eventMethod) const;
	virtual bool scSetProperty(const char *name, ScValue *value);
	virtual ScValue *scGetProperty(const Common::String &name);
	virtual bool scCallMethod(ScScript *script, ScStack *stack, ScStack *thisStack, const char *name);
	virtual const char *scToString();
	virtual void *scToMemBuffer();
	virtual int scToInt();
	virtual double scToFloat();
	virtual bool scToBool();
	virtual void scSetString(const char *val);
	virtual void scSetInt(int val);
	virtual void scSetFloat(double val);
	virtual void scSetBool(bool val);
	virtual int scCompare(BaseScriptable *val);
	virtual void scDebuggerDesc(char *buf, int bufSize);
	virtual Common::String debuggerToString() const;
	int32 _refCount;
	ScValue *_scValue;
	ScValue *_scProp;
};

// Implemented in their respective .cpp-files
BaseScriptable *makeSXArray(BaseGame *inGame, ScStack *stack);
BaseScriptable *makeSXDate(BaseGame *inGame, ScStack *stack);
BaseScriptable *makeSXFile(BaseGame *inGame, ScStack *stack);
BaseScriptable *makeSXDirectory(BaseGame *inGame);
BaseScriptable *makeSXMath(BaseGame *inGame);
BaseScriptable *makeSXMemBuffer(BaseGame *inGame, ScStack *stack);
BaseScriptable *makeSXObject(BaseGame *inGame, ScStack *stack);
BaseScriptable *makeSXStore(BaseGame *inGame);
BaseScriptable *makeSXString(BaseGame *inGame, ScStack *stack);

} // End of namespace Wintermute

#endif
