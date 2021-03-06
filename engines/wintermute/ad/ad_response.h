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

#ifndef WINTERMUTE_ADRESPONSE_H
#define WINTERMUTE_ADRESPONSE_H


#include "engines/wintermute/base/base_object.h"
#include "engines/wintermute/ad/ad_types.h"

namespace Wintermute {
class BaseFont;
class AdResponse : public BaseObject {
public:
	DECLARE_PERSISTENT(AdResponse, BaseObject)
	bool setIcon(const char *filename);
	bool setFont(const char *filename);
	bool setIconHover(const char *filename);
	bool setIconPressed(const char *filename);
	void setText(const char *text);
	void setID(int32 id);
	BaseSprite *getIcon() const;
	BaseSprite *getIconHover() const;
	BaseSprite *getIconPressed() const;
	BaseFont *getFont() const;
	int32 getID() const;

	const char *getText() const;
	const char *getTextOrig() const;

	AdResponse(BaseGame *inGame);
	~AdResponse() override;
	TResponseType _responseType;
private:
	BaseSprite *_icon;
	BaseSprite *_iconHover;
	BaseSprite *_iconPressed;
	BaseFont *_font;

	int32 _iD;

	char *_text;
	char *_textOrig;
};

} // End of namespace Wintermute

#endif
