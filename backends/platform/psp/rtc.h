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

#ifndef _PSP_RTC_H_
#define _PSP_RTC_H_

#include "common/singleton.h"

class PspRtc : public Common::Singleton<PspRtc> {
private:
	uint32 _startMillis;
	uint32 _startMicros;
	uint32 _lastMillis;
	uint32 _milliOffset;		// to prevent looping around of millis
	bool _looped;				// make sure we only loop once - for threading
public:
	PspRtc()
		: _startMillis(0), _startMicros(0),
		  _lastMillis(0), _milliOffset(0),
		  _looped(false) {
		init();
	}
	void init();
	uint32 getMillis(bool skipRecord = false);
	uint32 getMicros();
};

#endif
