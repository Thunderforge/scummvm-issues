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

#ifndef WINTERMUTE_ADSPRITESET_H
#define WINTERMUTE_ADSPRITESET_H


#include "engines/wintermute/base/base_object.h"

namespace Wintermute {
class BaseSprite;
class AdSpriteSet : public BaseObject {
public:
	bool containsSprite(BaseSprite *sprite);
	bool saveAsText(BaseDynamicBuffer *buffer, int indent = 0) override;
	BaseSprite *getSprite(TDirection direction);
	DECLARE_PERSISTENT(AdSpriteSet, BaseObject)
	BaseObject *_owner;
	AdSpriteSet(BaseGame *inGame, BaseObject *owner = nullptr);
	~AdSpriteSet() override;
	bool loadFile(const char *filename, int lifeTime = -1, TSpriteCacheType cacheType = CACHE_ALL);
	bool loadBuffer(char *buffer, bool complete = true, int lifeTime = -1, TSpriteCacheType cacheType = CACHE_ALL);
	BaseSprite *_sprites[NUM_DIRECTIONS];
};

} // End of namespace Wintermute

#endif
