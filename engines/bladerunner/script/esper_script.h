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

#ifndef BLADERUNNER_SCRIPT_ESPER_H
#define BLADERUNNER_SCRIPT_ESPER_H

#include "bladerunner/script/script.h"

namespace BladeRunner {

class BladeRunnerEngine;

class ESPERScript : ScriptBase {
public:
	ESPERScript(BladeRunnerEngine *vm) : ScriptBase(vm) {}

	void initialize();
	void photoSelected(int photoId);
	void specialRegionSelected(int photoId, int regionId);

private:
	void SCRIPT_ESPER_DLL_Initialize();
	void SCRIPT_ESPER_DLL_Photo_Selected(int photo);
	bool SCRIPT_ESPER_DLL_Special_Region_Selected(int photo, int region);
};

} // End of namespace BladeRunner

#endif
