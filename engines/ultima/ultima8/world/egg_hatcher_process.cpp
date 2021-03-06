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


#include "ultima/ultima8/world/egg_hatcher_process.h"
#include "ultima/ultima8/world/actors/main_actor.h"
#include "ultima/ultima8/world/teleport_egg.h"
#include "ultima/ultima8/world/get_object.h"
#include "ultima/ultima8/ultima8.h"

namespace Ultima {
namespace Ultima8 {

DEFINE_RUNTIME_CLASSTYPE_CODE(EggHatcherProcess)

EggHatcherProcess::EggHatcherProcess() {
}


EggHatcherProcess::~EggHatcherProcess() {
}

void EggHatcherProcess::addEgg(uint16 egg) {
	_eggs.push_back(egg);
}

void EggHatcherProcess::addEgg(Egg *egg) {
	assert(egg);
	_eggs.push_back(egg->getObjId());
}

void EggHatcherProcess::run() {
	bool nearteleporter = false;
	MainActor *av = getMainActor();
	if (!av)
		return;

	// CONSTANTS!
	const int range_mul = GAME_IS_U8 ? 32 : 64;
	const int z_range = 48;

	for (unsigned int i = 0; i < _eggs.size(); i++) {
		uint16 eggid = _eggs[i];
		Egg *egg = dynamic_cast<Egg *>(getObject(eggid));
		if (!egg) continue; // egg gone

		int32 x, y, z;
		egg->getLocation(x, y, z);

		//! constants
		int32 x1 = x - range_mul * egg->getXRange();
		int32 x2 = x + range_mul * egg->getXRange();
		int32 y1 = y - range_mul * egg->getYRange();
		int32 y2 = y + range_mul * egg->getYRange();

		// get avatar location
		int32 ax, ay, az;
		int32 axs, ays, azs;
		av->getLocation(ax, ay, az);
		av->getFootpadWorld(axs, ays, azs);

		// 'justTeleported':
		// if the avatar teleports, set the 'justTeleported' flag.
		// if this is set, don't hatch any teleport eggs
		// unset it when you're out of range of any teleport eggs
		TeleportEgg *tegg = dynamic_cast<TeleportEgg *>(egg);

		if (x1 <= ax && ax - axs < x2 && y1 <= ay && ay - ays < y2 &&
		        z - z_range < az && az <= z + z_range) {
			if (tegg && tegg->isTeleporter())
				nearteleporter = true;

			if (tegg && av->hasJustTeleported())
				continue;

			egg->hatch();
		} else {
			egg->unhatch();
		}
	}

	if (!nearteleporter)
		av->setJustTeleported(false); // clear flag
}

void EggHatcherProcess::saveData(Common::WriteStream *ws) {
	Process::saveData(ws);
}


bool EggHatcherProcess::loadData(Common::ReadStream *rs, uint32 version) {
	if (!Process::loadData(rs, version)) return false;

	// the eggs will be re-added to the EggHatcherProcess when they're
	// re-added to the CurrentMap

	return true;
}

} // End of namespace Ultima8
} // End of namespace Ultima
