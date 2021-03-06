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
 * This code is based on Broken Sword 2.5 engine
 *
 * Copyright (c) Malte Thiesen, Daniel Queteschiner and Michael Elsdoerfer
 *
 * Licensed under GNU GPL v2
 *
 */

#include "sword25/kernel/outputpersistenceblock.h"
#include "sword25/kernel/inputpersistenceblock.h"
#include "sword25/gfx/animationdescription.h"

namespace Sword25 {

bool AnimationDescription::persist(OutputPersistenceBlock &writer) {
	writer.write(static_cast<uint32>(_animationType));
	writer.write(_FPS);
	writer.write(_millisPerFrame);
	writer.write(_scalingAllowed);
	writer.write(_alphaAllowed);
	writer.write(_colorModulationAllowed);

	return true;
}

bool AnimationDescription::unpersist(InputPersistenceBlock &reader) {
	uint32 animationType;
	reader.read(animationType);
	_animationType = static_cast<Animation::ANIMATION_TYPES>(animationType);
	reader.read(_FPS);
	reader.read(_millisPerFrame);
	reader.read(_scalingAllowed);
	reader.read(_alphaAllowed);
	reader.read(_colorModulationAllowed);

	return reader.isGood();
}

} // End of namespace Sword25
