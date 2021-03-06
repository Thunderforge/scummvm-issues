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

#ifndef WINTERMUTE_BASE_FONT_H
#define WINTERMUTE_BASE_FONT_H

#include "engines/wintermute/base/base_object.h"

#define NUM_CHARACTERS 256

namespace Wintermute {

class BaseFont: public BaseObject {
public:
	DECLARE_PERSISTENT(BaseFont, BaseObject)
	virtual int getTextWidth(const byte *text, int maxLength = -1);
	virtual int getTextHeight(const byte *text, int width);
	virtual void drawText(const byte *text, int x, int y, int width, TTextAlign align = TAL_LEFT, int max_height = -1, int maxLength = -1);
	virtual int getLetterHeight();

	virtual void initLoop() {}
	virtual void afterLoad() {}
	BaseFont(BaseGame *inGame);
	~BaseFont() override;

	static BaseFont *createFromFile(BaseGame *game, const Common::String &filename);

private:
	//bool loadBuffer(byte * Buffer);
	//bool loadFile(const char* Filename);
	static bool isTrueType(BaseGame *game, const Common::String &filename);
};

} // End of namespace Wintermute

#endif
