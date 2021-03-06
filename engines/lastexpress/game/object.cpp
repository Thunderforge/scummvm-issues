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

#include "lastexpress/game/object.h"

#include "lastexpress/game/entities.h"
#include "lastexpress/game/logic.h"
#include "lastexpress/game/scenes.h"
#include "lastexpress/game/state.h"

#include "lastexpress/lastexpress.h"

namespace LastExpress {

Common::String Objects::Object::toString() {
	return Common::String::format("{ %s - %d - %d - %d - %d }", ENTITY_NAME(entity), status, windowCursor, handleCursor, model);
}

Objects::Objects(LastExpressEngine *engine) : _engine(engine) {}

const Objects::Object Objects::get(ObjectIndex index) const {
	if (index >= kObjectMax)
		error("[Objects::get] Invalid object index (%d)", index);

	return _objects[index];
}

void Objects::update(ObjectIndex index, EntityIndex entity, ObjectLocation status, CursorStyle windowCursor, CursorStyle handleCursor) {
	if (index >= kObjectMax)
		return;

	Object *object = &_objects[index];

	// Store original location
	ObjectLocation original_status = object->status;

	// Update entity
	object->entity = entity;
	object->status = status;

	if (windowCursor != kCursorKeepValue || handleCursor != kCursorKeepValue) {
		if (windowCursor != kCursorKeepValue)
			object->windowCursor = windowCursor;
		if (handleCursor != kCursorKeepValue)
			object->handleCursor = handleCursor;

		getLogic()->updateCursor();
	}

	getFlags()->flag_3 = true;

	// Compartments
	if (original_status != status && (original_status == kObjectLocation2 || status == kObjectLocation2)) {
		if ((index >= kObjectCompartment1 && index <= kObjectCompartment8)
		   || (index >= kObjectCompartmentA && index <= kObjectCompartmentF)) {
			getScenes()->updateDoorsAndClock();
		}
	}
}

void Objects::updateModel(ObjectIndex index, ObjectModel model) {
	if (index >= kObjectMax)
		return;

	_objects[index].model = model;
}

//////////////////////////////////////////////////////////////////////////
// Serializable
//////////////////////////////////////////////////////////////////////////
void Objects::saveLoadWithSerializer(Common::Serializer &s) {
	for (int i = 0; i < ARRAYSIZE(_objects); i++)
		_objects[i].saveLoadWithSerializer(s);
}

//////////////////////////////////////////////////////////////////////////
// toString
//////////////////////////////////////////////////////////////////////////
Common::String Objects::toString() {
	Common::String ret = "";

	for (int i = 0; i < ARRAYSIZE(_objects); i++)
		ret += Common::String::format("%d : %s\n", i, _objects[i].toString().c_str());

	return ret;
}

} // End of namespace LastExpress
