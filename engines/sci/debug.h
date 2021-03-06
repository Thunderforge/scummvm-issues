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

#ifndef SCI_DEBUG_H
#define SCI_DEBUG_H

#include "common/list.h"
#include "sci/engine/vm_types.h"	// for StackPtr

namespace Sci {

// These types are used both as identifiers and as elements of bitfields
enum BreakpointType {
	/**
	 * Break when a selector is executed. Data contains selector name
	 * (in the format Object::Method)
	 */
	BREAK_SELECTOREXEC  = 1 << 0, // break when a function selector is executed
	BREAK_SELECTORREAD  = 1 << 1, // break when a variable selector is read
	BREAK_SELECTORWRITE = 1 << 2, // break when a variable selector is written

	/**
	 * Break when an exported function is called. _address contains
	 * script_no << 16 | export_no.
	 */
	BREAK_EXPORT        = 1 << 3,
	BREAK_ADDRESS       = 1 << 4, // break when pc is at _regAddress
	BREAK_KERNEL        = 1 << 5  // break on named kernel call
};

enum BreakpointAction {
	BREAK_NONE,      // ignore breakpoint
	BREAK_BREAK,     // break into debugger when breakpoint is triggered
	BREAK_LOG,       // log the breakpoint, and don't break into debugger
	BREAK_BACKTRACE, // show a backtrace, and don't break into debugger
	BREAK_INSPECT    // show object, and don't break into debugger
};

struct Breakpoint {
	BreakpointType _type;
	uint32 _address;     ///< Breakpoints on exports
	reg_t _regAddress; ///< Breakpoints on addresses
	Common::String _name; ///< Breakpoints on selector names
	BreakpointAction _action;
};

enum DebugSeeking {
	kDebugSeekNothing = 0,
	kDebugSeekCallk = 1,        // Step forward until callk is found
	kDebugSeekLevelRet = 2,     // Step forward until returned from this level
	kDebugSeekSpecialCallk = 3, // Step forward until a /special/ callk is found
	kDebugSeekGlobal = 4,       // Step forward until one specified global variable is modified
	kDebugSeekStepOver = 5      // Step forward until we reach same stack-level again
};

struct DebugState {
	bool debugging;
	bool breakpointWasHit;
	bool stopOnEvent;
	DebugSeeking seeking;		// Stepping forward until some special condition is met
	int runningStep;			// Set to > 0 to allow multiple stepping
	int seekLevel;				// Used for seekers that want to check their exec stack depth
	int seekSpecial;			// Used for special seeks
	int old_pc_offset;
	StackPtr old_sp;
	Common::List<Breakpoint> _breakpoints;   //< List of breakpoints
	int _activeBreakpointTypes;  //< Bit mask specifying which types of breakpoints are active

	void updateActiveBreakpointTypes();
};

// Various global variables used for debugging are declared here
extern int g_debug_sleeptime_factor;
extern int g_debug_simulated_key;
extern bool g_debug_track_mouse_clicks;

} // End of namespace Sci

#endif
