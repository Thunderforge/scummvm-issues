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

#if !defined(BACKEND_EVENTS_OP_H) && !defined(DISABLE_DEFAULT_EVENTMANAGER)
#define BACKEND_EVENTS_OP_H

#include "backends/events/sdl/sdl-events.h"

/**
 * Events manager for the OpenPandora.
 */

class OPEventSource : public SdlEventSource {
public:
	OPEventSource();

protected:

	/**
	 * Button state for L button modifier
	 */
	bool _buttonStateL;

	int _tapmodeLevel;

	void ToggleTapMode();

	bool handleMouseButtonDown(SDL_Event &ev, Common::Event &event);
	bool handleMouseButtonUp(SDL_Event &ev, Common::Event &event);
	bool remapKey(SDL_Event &ev, Common::Event &event);
};

#endif /* BACKEND_EVENTS_OP_H */
