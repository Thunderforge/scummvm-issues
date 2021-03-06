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

#include "engines/wintermute/base/font/base_font.h"
#include "engines/wintermute/base/font/base_font_bitmap.h"
#include "engines/wintermute/base/font/base_font_truetype.h"
#include "engines/wintermute/base/base_parser.h"
#include "engines/wintermute/base/base_file_manager.h"

namespace Wintermute {

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_PERSISTENT(BaseFont, false)

//////////////////////////////////////////////////////////////////////
BaseFont::BaseFont(BaseGame *inGame) : BaseObject(inGame) {

}


//////////////////////////////////////////////////////////////////////
BaseFont::~BaseFont() {
}


//////////////////////////////////////////////////////////////////////
void BaseFont::drawText(const byte *text, int x, int y, int width, TTextAlign align, int maxHeight, int maxLength) {
}


//////////////////////////////////////////////////////////////////////
int BaseFont::getTextHeight(const byte *text, int width) {
	return 0;
}


//////////////////////////////////////////////////////////////////////
int BaseFont::getTextWidth(const byte *text, int maxLength) {
	return 0;
}


//////////////////////////////////////////////////////////////////////////
int BaseFont::getLetterHeight() {
	return 0;
}


//////////////////////////////////////////////////////////////////////////
bool BaseFont::persist(BasePersistenceManager *persistMgr) {

	BaseObject::persist(persistMgr);
	return STATUS_OK;
}


//////////////////////////////////////////////////////////////////////////
BaseFont *BaseFont::createFromFile(BaseGame *gameRef, const Common::String &filename) {
	if (isTrueType(gameRef,  filename)) {
		BaseFontTT *font = new BaseFontTT(gameRef);
		if (font) {
			if (DID_FAIL(font->loadFile(filename))) {
				delete font;
				return nullptr;
			}
		}
		return font;
	} else {
		BaseFontBitmap *font = new BaseFontBitmap(gameRef);
		if (font) {
			if (DID_FAIL(font->loadFile(filename))) {
				delete font;
				return nullptr;
			}
		}
		return font;
	}
}


TOKEN_DEF_START
TOKEN_DEF(FONT)
TOKEN_DEF(TTFONT)
TOKEN_DEF_END
//////////////////////////////////////////////////////////////////////////
bool BaseFont::isTrueType(BaseGame *gameRef, const Common::String &filename) {
	TOKEN_TABLE_START(commands)
	TOKEN_TABLE(FONT)
	TOKEN_TABLE(TTFONT)
	TOKEN_TABLE_END


	char *buffer = (char *)BaseFileManager::getEngineInstance()->readWholeFile(filename);
	if (buffer == nullptr) {
		return false;
	}

	char *workBuffer = buffer;

	char *params;
	BaseParser parser;

	bool ret = false;
	if (parser.getCommand(&workBuffer, commands, &params) == TOKEN_TTFONT) {
		ret = true;
	}

	delete[] buffer;
	return ret;
}

} // End of namespace Wintermute
