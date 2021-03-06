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

#ifndef BACKENDS_TIMER_DEFAULT_H
#define BACKENDS_TIMER_DEFAULT_H

#include "common/str.h"
#include "common/hash-str.h"
#include "common/timer.h"
#include "common/mutex.h"

struct TimerSlot;

class DefaultTimerManager : public Common::TimerManager {
private:
	typedef Common::HashMap<Common::String, TimerProc, Common::IgnoreCase_Hash, Common::IgnoreCase_EqualTo> TimerSlotMap;

	Common::Mutex _mutex;
	TimerSlot *_head;
	TimerSlotMap _callbacks;

	uint32 _timerCallbackNext;

public:
	DefaultTimerManager();
	virtual ~DefaultTimerManager();
	virtual bool installTimerProc(TimerProc proc, int32 interval, void *refCon, const Common::String &id);
	virtual void removeTimerProc(TimerProc proc);

	/**
	 * Timer callback, to be invoked at regular time intervals by the backend.
	 */
	void handler();

	/*
	 * Ensure that the callback is called at regular time intervals.
	 * Should be called from pollEvents() on backends without threads.
	 */
	void checkTimers(uint32 interval = 10);
};

#endif
