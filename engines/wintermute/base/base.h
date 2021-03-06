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

#ifndef WINTERMUTE_BASE_BASE_H
#define WINTERMUTE_BASE_BASE_H

#include "engines/wintermute/wintypes.h"
#include "engines/wintermute/dctypes.h"
#include "common/str.h"
#include "common/hashmap.h"
#include "common/hash-str.h"

namespace Wintermute {

class BaseGame;
class BaseDynamicBuffer;
class BasePersistenceManager;

class BaseClass {
public:
	bool _persistable;
	bool setEditorProp(const Common::String &propName, const Common::String &propValue);
	Common::String getEditorProp(const Common::String &propName, const Common::String &initVal = Common::String());
	BaseClass(TDynamicConstructor, TDynamicConstructor) {}
	bool parseEditorProperty(char *buffer, bool complete = true);
	virtual bool saveAsText(BaseDynamicBuffer *buffer, int indent = 0);
	BaseClass();
	BaseClass(BaseGame *GameOwner);
	virtual ~BaseClass();
	BaseGame *_gameRef;

	virtual const char *getClassName() { return ""; }
	virtual bool persist(BasePersistenceManager *persistMgr) { return true; }
protected:
	Common::HashMap<Common::String, Common::String> _editorProps;
	Common::HashMap<Common::String, Common::String>::iterator _editorPropsIter;
};

} // End of namespace Wintermute

#endif
