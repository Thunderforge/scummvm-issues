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

#ifndef BREAKPOINT_H_
#define BREAKPOINT_H_
#include "common/str.h"

namespace Wintermute {

class ScriptMonitor;
class DebuggableScript;

class Breakpoint {
	const Common::String _filename;
	const uint _line;
	uint _hits;
	bool _enabled;
	ScriptMonitor *_monitor;
	void hit(DebuggableScript *script);
public:
	Breakpoint(const Common::String &filename, uint line, ScriptMonitor *monitor);
	/**
	 * This should be called inside the interpreter; the breakpoint is evaluated
	 * in the context of script, and, if it is enabled and filename & line match,
	 * the attached ScriptMonitor is notified.
	 */
	void evaluate(DebuggableScript* script);
	Common::String getFilename() const;
	int getLine() const;
	int getHits() const;
	bool isEnabled() const;
	void enable();
	void disable();
	virtual ~Breakpoint();
};

} // End of namespace Wintermute

#endif /* BREAKPOINT_H_ */
