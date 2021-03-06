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

#include "cine/console.h"
#include "cine/cine.h"

namespace Cine {

bool labyrinthCheat;
bool hacksEnabled;

CineConsole::CineConsole(CineEngine *vm) : GUI::Debugger(), _vm(vm) {
	assert(_vm);
	registerCmd("labyrinthCheat", WRAP_METHOD(CineConsole, Cmd_LabyrinthCheat));
	registerCmd("disableLabyrinthCheat", WRAP_METHOD(CineConsole, Cmd_DisableLabyrinthCheat));
	registerCmd("disableHacks", WRAP_METHOD(CineConsole, Cmd_DisableHacks));
	registerCmd("enableHacks", WRAP_METHOD(CineConsole, Cmd_EnableHacks));

	labyrinthCheat = false;
	hacksEnabled = true;
}

CineConsole::~CineConsole() {
}

// Activate Cheat during Scene 6 Labyrinth chased by Guards in Otto's Mansion
// This puzzle is hard, especially without save/load so this will aid playtesting.
bool CineConsole::Cmd_LabyrinthCheat(int argc, const char **argv) {
	labyrinthCheat = true;
	return true;
}

bool CineConsole::Cmd_DisableLabyrinthCheat(int argc, const char **argv) {
	labyrinthCheat = false;
	return true;
}

bool CineConsole::Cmd_DisableHacks(int argc, const char **argv) {
	hacksEnabled = false;
	return true;
}

bool CineConsole::Cmd_EnableHacks(int argc, const char **argv) {
	hacksEnabled = true;
	return true;
}

} // End of namespace Cine
