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

#ifndef WINTERMUTE_SXARRAY_H
#define WINTERMUTE_SXARRAY_H

#include "engines/wintermute/base/base_scriptable.h"

namespace Wintermute {

class SXArray : public BaseScriptable {
public:
	bool push(ScValue *val);
	bool validNumber(const char *origStr, char *outStr);
	DECLARE_PERSISTENT(SXArray, BaseScriptable)
	SXArray(BaseGame *inGame, ScStack *stack);
	SXArray(BaseGame *inGame);
	~SXArray() override;
	ScValue *scGetProperty(const Common::String &name) override;
	bool scSetProperty(const char *name, ScValue *value) override;
	bool scCallMethod(ScScript *script, ScStack *stack, ScStack *thisStack, const char *name) override;
	const char *scToString() override;
private:
	int32 _length;
	ScValue *_values;
	Common::String _strRep;
};

} // End of namespace Wintermute

#endif
