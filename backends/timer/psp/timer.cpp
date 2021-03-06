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

// Disable printf override in common/forbidden.h to avoid
// clashes with pspdebug.h from the PSP SDK.
// That header file uses
//   __attribute__((format(printf,1,2)));
// which gets messed up by our override mechanism; this could
// be avoided by either changing the PSP SDK to use the equally
// legal and valid
//   __attribute__((format(__printf__,1,2)));
// or by refining our printf override to use a varadic macro
// (which then wouldn't be portable, though).
// Anyway, for now we just disable the printf override globally
// for the PSP port
#define FORBIDDEN_SYMBOL_EXCEPTION_printf

#include "common/scummsys.h"

#if defined(__PSP__)
#include <pspthreadman.h>

#include "common/scummsys.h"
#include "common/timer.h"
#include "backends/platform/psp/thread.h"
#include "backends/timer/psp/timer.h"

//#define __PSP_DEBUG_FUNCS__	/* For debugging function calls */
//#define __PSP_DEBUG_PRINT__	/* For debug printouts */

#include "backends/platform/psp/trace.h"

PspTimerManager::PspTimerManager(uint32 interval) : _interval(interval * 1000), _threadId(-1), _init(false) {
	DEBUG_ENTER_FUNC();

	_threadId = sceKernelCreateThread("timerThread", thread, PRIORITY_TIMER_THREAD, STACK_TIMER_THREAD, THREAD_ATTR_USER, 0);

	if (_threadId < 0) {	// error
		PSP_ERROR("failed to create timer thread. Error code %d\n", _threadId);
		return;
	}

	PspTimerManager *_this = this;	// trick to get into context when the thread starts
	_init = true;

	if (sceKernelStartThread(_threadId, sizeof(uint32 *), &_this) < 0) {
		PSP_ERROR("failed to start thread %d\n", _threadId);
		return;
	}

	PSP_DEBUG_PRINT("created timer thread[%x]\n", _threadId);
}

int PspTimerManager::thread(SceSize, void *__this) {
	DEBUG_ENTER_FUNC();
	PspTimerManager *_this = *(PspTimerManager **)__this;		// get our this for the context

	_this->timerThread();
	return 0;
};

void PspTimerManager::timerThread() {
	DEBUG_ENTER_FUNC();

	while (_init) {
		sceKernelDelayThread(_interval);
		PSP_DEBUG_PRINT("calling callback!\n");
		handler();
	}
};

#endif /* __PSP__ */
