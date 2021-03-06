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

#include "mohawk/myst.h"
#include "mohawk/graphics.h"
#include "mohawk/myst_areas.h"
#include "mohawk/sound.h"
#include "mohawk/video.h"
#include "mohawk/myst_stacks/makingof.h"

namespace Mohawk {
namespace MystStacks {

MakingOf::MakingOf(MohawkEngine_Myst *vm) :
		MystScriptParser(vm, kMakingOfStack) {
	setupOpcodes();
}

MakingOf::~MakingOf() {
}

void MakingOf::setupOpcodes() {
	// "Stack-Specific" Opcodes
	REGISTER_OPCODE(100, MakingOf, o_quit);
}

void MakingOf::disablePersistentScripts() {
}

void MakingOf::runPersistentScripts() {
}

} // End of namespace MystStacks
} // End of namespace Mohawk
