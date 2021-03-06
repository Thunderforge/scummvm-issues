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

#ifndef WINTERMUTE_UITILEDIMAGE_H
#define WINTERMUTE_UITILEDIMAGE_H


#include "engines/wintermute/ui/ui_object.h"
#include "common/rect.h"

namespace Wintermute {
class BaseSubFrame;
class UITiledImage : public BaseObject {
	using Wintermute::BaseObject::display;

public:
	DECLARE_PERSISTENT(UITiledImage, BaseObject)
	void correctSize(int32 *width, int32 *height);
	bool loadFile(const char *filename);
	bool loadBuffer(char *buffer, bool complete = true);
	bool saveAsText(BaseDynamicBuffer *buffer, int indent) override;

	bool display(int x, int y, int width, int height);
	UITiledImage(BaseGame *inGame = nullptr);
	~UITiledImage() override;
private:
	BaseSubFrame *_image;
	Rect32 _upLeft;
	Rect32 _upMiddle;
	Rect32 _upRight;
	Rect32 _middleLeft;
	Rect32 _middleMiddle;
	Rect32 _middleRight;
	Rect32 _downLeft;
	Rect32 _downMiddle;
	Rect32 _downRight;
};

} // End of namespace Wintermute

#endif
