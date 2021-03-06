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

#ifndef MYST_SCRIPTS_PREVIEW_H
#define MYST_SCRIPTS_PREVIEW_H

#include "mohawk/sound.h"
#include "mohawk/myst_stacks/myst.h"

#include "common/scummsys.h"
#include "common/util.h"

namespace Mohawk {

struct MystScriptEntry;

namespace MystStacks {

#define DECLARE_OPCODE(x) void x(uint16 var, const ArgumentsArray &args)

class Preview : public Myst {
public:
	explicit Preview(MohawkEngine_Myst *vm);
	~Preview() override;

	void disablePersistentScripts() override;
	void runPersistentScripts() override;

private:
	void setupOpcodes();

	DECLARE_OPCODE(o_fadeToBlack);
	DECLARE_OPCODE(o_fadeFromBlack);
	DECLARE_OPCODE(o_stayHere);
	DECLARE_OPCODE(o_speechStop);

	DECLARE_OPCODE(o_libraryBookcaseTransformDemo_init);
	DECLARE_OPCODE(o_speech_init);
	DECLARE_OPCODE(o_library_init);

	uint16 _libraryState; // 4
	MystAreaImageSwitch *_library; // 32

	bool _speechRunning;
	uint _speechStep;
	CueList _cueList;
	int16 _currentCue;
	uint32 _speechNextTime; // 6

	void speech_run();
	void speechUpdateCue();

	void libraryBookcaseTransform_run() override;
};

} // End of namespace MystStacks
} // End of namespace Mohawk

#undef DECLARE_OPCODE

#endif
