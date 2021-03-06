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

#ifndef WINTERMUTE_BASE_VIEWPORT_H
#define WINTERMUTE_BASE_VIEWPORT_H


#include "engines/wintermute/base/base.h"
#include "engines/wintermute/math/rect32.h"
#include "engines/wintermute/persistent.h"

namespace Wintermute {
class BaseObject;
class BaseViewport : public BaseClass {
public:
	int getHeight() const;
	int getWidth() const;
	Rect32 *getRect();
	bool setRect(int32 left, int32 top, int32 right, int32 bottom, bool noCheck = false);
	DECLARE_PERSISTENT(BaseViewport, BaseClass)
	int32 _offsetY;
	int32 _offsetX;
	BaseObject *_mainObject;
	BaseViewport(BaseGame *inGame = nullptr);
	~BaseViewport() override;
	virtual Common::String debuggerToString() const;
private:
	Rect32 _rect;
};

} // End of namespace Wintermute

#endif
