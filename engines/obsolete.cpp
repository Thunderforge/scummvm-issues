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

#include "engines/obsolete.h"

#include "common/config-manager.h"


namespace Engines {

void upgradeTargetIfNecessary(const ObsoleteGameID *obsoleteList) {
	if (obsoleteList == 0)
		return;

	Common::String gameid = ConfMan.get("gameid");

	for (const ObsoleteGameID *o = obsoleteList; o->from; ++o) {
		if (gameid.equalsIgnoreCase(o->from)) {
			gameid = o->to;
			ConfMan.set("gameid", gameid);

			if (o->platform != Common::kPlatformUnknown)
				ConfMan.set("platform", Common::getPlatformCode(o->platform));

			warning("Target upgraded from %s to %s", o->from, o->to);

			// WORKAROUND: Fix for bug #3192: "DETECTOR: Launching
			// undefined target adds launcher entry"
			if (ConfMan.hasKey("id_came_from_command_line")) {
				warning("Target came from command line. Skipping save");
			} else {
				ConfMan.flushToDisk();
			}
			break;
		}
	}
}

PlainGameDescriptor findGameID(
	const char *gameid,
	const PlainGameDescriptor *gameids,
	const ObsoleteGameID *obsoleteList) {
	// First search the list of supported gameids for a match.
	const PlainGameDescriptor *g = findPlainGameDescriptor(gameid, gameids);
	if (g)
		return *g;

	// If we didn't find the gameid in the main list, check if it
	// is an obsolete game id.
	if (obsoleteList != 0) {
		const ObsoleteGameID *o = obsoleteList;
		while (o->from) {
			if (0 == scumm_stricmp(gameid, o->from)) {
				g = findPlainGameDescriptor(o->to, gameids);
				if (g && g->description)
					return PlainGameDescriptor::of(gameid, g->description);
				else
					return PlainGameDescriptor::of(gameid, "Obsolete game ID");
			}
			o++;
		}
	}

	// No match found
	return PlainGameDescriptor::empty();
}

} // End of namespace Engines
