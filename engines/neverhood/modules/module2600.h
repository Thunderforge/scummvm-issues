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

#ifndef NEVERHOOD_MODULES_MODULE2600_H
#define NEVERHOOD_MODULES_MODULE2600_H

#include "neverhood/neverhood.h"
#include "neverhood/module.h"
#include "neverhood/scene.h"

namespace Neverhood {

// Module2600

class Module2600 : public Module {
public:
	Module2600(NeverhoodEngine *vm, Module *parentModule, int which);
	~Module2600() override;
protected:
	int _sceneNum;
	void createScene(int sceneNum, int which);
	void updateScene();
};

class Scene2609 : public Scene {
public:
	Scene2609(NeverhoodEngine *vm, Module *parentModule, int which);
protected:
	bool _isBusy;
	Sprite *_asWater;
	Sprite *_ssButton;
	uint32 handleMessage(int messageNum, const MessageParam &param, Entity *sender);
};

} // End of namespace Neverhood

#endif /* NEVERHOOD_MODULES_MODULE2600_H */
