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

#ifndef WINTERMUTE_ADSCENENODE_H
#define WINTERMUTE_ADSCENENODE_H


#include "engines/wintermute/ad/ad_types.h"    // Added by ClassView
#include "engines/wintermute/ad/ad_region.h"   // Added by ClassView
#include "engines/wintermute/ad/ad_entity.h"

namespace Wintermute {

class AdSceneNode : public BaseObject {
public:
	DECLARE_PERSISTENT(AdSceneNode, BaseObject)
	bool setRegion(AdRegion *region);
	bool setEntity(AdEntity *entity);
	AdEntity *_entity;
	AdRegion *_region;
	TObjectType _type;
	AdSceneNode(BaseGame *inGame);
	~AdSceneNode() override;

};

}

#endif
