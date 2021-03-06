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

#include "bladerunner/framelimiter.h"

#include "bladerunner/bladerunner.h"
#include "bladerunner/time.h"

#include "common/debug.h"
#include "common/system.h"

namespace BladeRunner {

Framelimiter::Framelimiter(BladeRunnerEngine *vm, uint fps) {
	_vm = vm;

	reset();

	if (fps > 0) {
		_enabled = true;
		_speedLimitMs = 1000 / fps;
	} else {
		_enabled = false;
	}

	_timeFrameStart = _vm->_time->currentSystem();
}

void Framelimiter::wait() {
	// TODO: when vsync will be supported, use it

	if (!_enabled) {
		return;
	}

	uint32 timeNow = _vm->_time->currentSystem();
	uint32 frameDuration = timeNow - _timeFrameStart;
	if (frameDuration < _speedLimitMs) {
		uint32 waittime = _speedLimitMs - frameDuration;
		if (_vm->_noDelayMillisFramelimiter) {
			while (_vm->_time->currentSystem() - timeNow < waittime) { }
		} else {
			_vm->_system->delayMillis(waittime);
		}
		timeNow += waittime;
	}
	// debug("frametime %i ms", timeNow - _timeFrameStart);
	// using _vm->_time->currentSystem() here is slower and causes some shutters
	_timeFrameStart = timeNow;
}

void Framelimiter::reset() {
	_timeFrameStart = 0u;
}

} // End of namespace BladeRunner
