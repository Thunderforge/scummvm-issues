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
 * This code is based on Broken Sword 2.5 engine
 *
 * Copyright (c) Malte Thiesen, Daniel Queteschiner and Michael Elsdoerfer
 *
 * Licensed under GNU GPL v2
 *
 */

#ifndef SWORD25_LUASCRIPT_H
#define SWORD25_LUASCRIPT_H

#include "common/str.h"
#include "common/str-array.h"
#include "sword25/kernel/common.h"
#include "sword25/script/script.h"

struct lua_State;

namespace Sword25 {

class Kernel;

class LuaScriptEngine : public ScriptEngine {
public:
	LuaScriptEngine(Kernel *KernelPtr);
	~LuaScriptEngine() override;

	/**
	 * Initializes the scripting engine
	 * @return              Returns true if successful, otherwise false.
	*/
	bool init() override;

	/**
	 * Loads a script file and executes it
	 * @param FileName      The filename of the script
	 * @return              Returns true if successful, otherwise false.
	 */
	bool executeFile(const Common::String &fileName) override;

	/**
	 * Execute a string of script code
	 * @param Code          A string of script code
	 * @return              Returns true if successful, otherwise false.
	 */
	bool executeString(const Common::String &code) override;

	/**
	 * Returns a pointer to the main object of the scripting language
	 * @remark              Using this method breaks the encapsulation of the language
	 */
	void *getScriptObject() override {
		return _state;
	}

	/**
	 * Makes the command line parameters for the scripting environment available
	 * @param CommandLineParameters An array containing all the command line parameters
	 * @remark              How the command line parameters will be used by scripts is
	 * dependant on the particular implementation.
	 */
	void setCommandLine(const Common::StringArray &commandLineParameters) override;

	/**
	 * @remark              The Lua stack is cleared by this method
	 */
	bool persist(OutputPersistenceBlock &writer) override;
	/**
	 * @remark              The Lua stack is cleared by this method
	 */
	bool unpersist(InputPersistenceBlock &reader) override;

private:
	lua_State *_state;
	int _pcallErrorhandlerRegistryIndex;

	bool registerStandardLibs();
	bool registerStandardLibExtensions();
	bool executeBuffer(const byte *data, uint size, const Common::String &name) const;
};

} // End of namespace Sword25

#endif
