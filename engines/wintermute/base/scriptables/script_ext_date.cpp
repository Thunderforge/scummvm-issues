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

/*
 * This file is based on WME Lite.
 * http://dead-code.org/redir.php?target=wmelite
 * Copyright (c) 2011 Jan Nedoma
 */

#include "engines/wintermute/base/scriptables/script_stack.h"
#include "engines/wintermute/base/scriptables/script_value.h"
#include "engines/wintermute/base/scriptables/script_ext_date.h"

namespace Wintermute {

IMPLEMENT_PERSISTENT(SXDate, false)

BaseScriptable *makeSXDate(BaseGame *inGame, ScStack *stack) {
	return new SXDate(inGame, stack);
}

//////////////////////////////////////////////////////////////////////////
SXDate::SXDate(BaseGame *inGame, ScStack *stack) : BaseScriptable(inGame) {
	stack->correctParams(6);

	memset(&_tm, 0, sizeof(_tm));

	ScValue *valYear = stack->pop();
	_tm.tm_year = valYear->getInt() - 1900;
	_tm.tm_mon = stack->pop()->getInt() - 1;
	_tm.tm_mday = stack->pop()->getInt();
	_tm.tm_hour = stack->pop()->getInt();
	_tm.tm_min = stack->pop()->getInt();
	_tm.tm_sec = stack->pop()->getInt();

	if (valYear->isNULL()) {
		g_system->getTimeAndDate(_tm);
	}
}


//////////////////////////////////////////////////////////////////////////
SXDate::~SXDate() {

}

//////////////////////////////////////////////////////////////////////////
const char *SXDate::scToString() {
	// TODO: Make this more stringy, and less ISO 8601-like
	_strRep.format("%04d-%02d-%02d - %02d:%02d:%02d", _tm.tm_year, _tm.tm_mon, _tm.tm_mday, _tm.tm_hour, _tm.tm_min, _tm.tm_sec);
	return _strRep.c_str();
	//return asctime(&_tm);
}


//////////////////////////////////////////////////////////////////////////
bool SXDate::scCallMethod(ScScript *script, ScStack *stack, ScStack *thisStack, const char *name) {
	//////////////////////////////////////////////////////////////////////////
	// GetYear
	//////////////////////////////////////////////////////////////////////////
	if (strcmp(name, "GetYear") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_year + 1900);
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// GetMonth
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetMonth") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_mon + 1);
		return STATUS_OK;
	}
#ifdef ENABLE_FOXTAIL
	//////////////////////////////////////////////////////////////////////////
	// [FoxTail] GetDay
	// date.GetDate() was renamed to date.GetDay() in FoxTail 1.2.896 engine
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetDay") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_mday);
		return STATUS_OK;
	}
#endif
	//////////////////////////////////////////////////////////////////////////
	// GetDate
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetDate") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_mday);
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// GetHours
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetHours") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_hour);
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// GetMinutes
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetMinutes") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_min);
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// GetSeconds
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetSeconds") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_sec);
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// GetWeekday
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "GetWeekday") == 0) {
		stack->correctParams(0);
		stack->pushInt(_tm.tm_wday);
		return STATUS_OK;
	}


	//////////////////////////////////////////////////////////////////////////
	// SetYear
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetYear") == 0) {
		stack->correctParams(1);
		_tm.tm_year = stack->pop()->getInt() - 1900;
		stack->pushNULL();
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// SetMonth
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetMonth") == 0) {
		stack->correctParams(1);
		_tm.tm_mon = stack->pop()->getInt() - 1;
		stack->pushNULL();
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// SetDate
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetDate") == 0) {
		stack->correctParams(1);
		_tm.tm_mday = stack->pop()->getInt();
		stack->pushNULL();
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// SetHours
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetHours") == 0) {
		stack->correctParams(1);
		_tm.tm_hour = stack->pop()->getInt();
		stack->pushNULL();
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// SetMinutes
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetMinutes") == 0) {
		stack->correctParams(1);
		_tm.tm_min = stack->pop()->getInt();
		stack->pushNULL();
		return STATUS_OK;
	}
	//////////////////////////////////////////////////////////////////////////
	// SetSeconds
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetSeconds") == 0) {
		stack->correctParams(1);
		_tm.tm_sec = stack->pop()->getInt();
		stack->pushNULL();
		return STATUS_OK;
	}


	//////////////////////////////////////////////////////////////////////////
	// SetCurrentTime
	//////////////////////////////////////////////////////////////////////////
	else if (strcmp(name, "SetCurrentTime") == 0) {
		stack->correctParams(0);
		g_system->getTimeAndDate(_tm);
		stack->pushNULL();
		return STATUS_OK;
	} else {
		return STATUS_FAILED;
	}
}


//////////////////////////////////////////////////////////////////////////
ScValue *SXDate::scGetProperty(const Common::String &name) {
	_scValue->setNULL();

	//////////////////////////////////////////////////////////////////////////
	// Type
	//////////////////////////////////////////////////////////////////////////
	if (name == "Type") {
		_scValue->setString("date");
		return _scValue;
	} else {
		return _scValue;
	}
}


//////////////////////////////////////////////////////////////////////////
bool SXDate::scSetProperty(const char *name, ScValue *value) {
	/*
	//////////////////////////////////////////////////////////////////////////
	// Name
	//////////////////////////////////////////////////////////////////////////
	if (name == "Name")==0) {
	    setName(value->getString());
	    return STATUS_OK;
	}

	else*/ return STATUS_FAILED;
}


//////////////////////////////////////////////////////////////////////////
bool SXDate::persist(BasePersistenceManager *persistMgr) {

	BaseScriptable::persist(persistMgr);
	int32 year = _tm.tm_year;
	int32 mon = _tm.tm_mon;
	int32 mday = _tm.tm_mday;
	int32 hour = _tm.tm_hour;
	int32 min = _tm.tm_min;
	int32 sec = _tm.tm_sec;
	persistMgr->transferSint32(TMEMBER(year));
	persistMgr->transferSint32(TMEMBER(mon));
	persistMgr->transferSint32(TMEMBER(mday));
	persistMgr->transferSint32(TMEMBER(hour));
	persistMgr->transferSint32(TMEMBER(min));
	persistMgr->transferSint32(TMEMBER(sec));
	if (persistMgr->checkVersion(1, 2, 1)) {
		int32 wday = _tm.tm_wday;
		persistMgr->transferSint32(TMEMBER(wday));
		_tm.tm_wday = wday;
	}
	_tm.tm_year = year;
	_tm.tm_mon = mon;
	_tm.tm_mday = mday;
	_tm.tm_hour = hour;
	_tm.tm_min = min;
	_tm.tm_sec = sec;
	return STATUS_OK;
}

//////////////////////////////////////////////////////////////////////////
int SXDate::scCompare(BaseScriptable *Value) {
	TimeDate time1 = _tm;
	TimeDate time2 = ((SXDate *)Value)->_tm;

	if (time1.tm_year < time2.tm_year) {
		return -1;
	} else if (time1.tm_year == time2.tm_year) {
		if (time1.tm_mon < time2.tm_mon) {
			return -1;
		} else if (time1.tm_mon == time2.tm_mon) {
			if (time1.tm_mday < time2.tm_mday) {
				return -1;
			} else if (time1.tm_mday == time2.tm_mday) {
				if (time1.tm_hour < time2.tm_hour) {
					return -1;
				} else if (time1.tm_hour == time2.tm_hour) {
					if (time1.tm_min < time2.tm_min) {
						return -1;
					} else if (time1.tm_min == time2.tm_min) {
						if (time1.tm_sec < time2.tm_sec) {
							return -1;
						} else if (time1.tm_sec == time2.tm_sec) {
							return 0; // Equal
						} else {
							return 1; // Sec
						}
					} else {
						return 1; // Minute
					}
				} else {
					return 1; // Hour
				}
			} else {
				return 1; // Day
			}
		} else {
			return 1; // Month
		}
	} else {
		return 1; // Year
	}
}

} // End of namespace Wintermute
