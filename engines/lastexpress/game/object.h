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

#ifndef LASTEXPRESS_OBJECT_H
#define LASTEXPRESS_OBJECT_H

#include "lastexpress/shared.h"

#include "common/serializer.h"
#include "common/system.h"

namespace LastExpress {

class LastExpressEngine;

class Objects : Common::Serializable {
public:

	struct Object : Common::Serializable {                         // All fields should be saved as bytes
		EntityIndex entity;
		ObjectLocation status;
		CursorStyle windowCursor;
		CursorStyle handleCursor;
		ObjectModel model;

		Object() {
			entity = kEntityPlayer;
			status = kObjectLocationNone;
			windowCursor = kCursorHandKnock;
			handleCursor = kCursorHandKnock;
			model = kObjectModelNone;
		}

		Common::String toString();

		// Serializable
		void saveLoadWithSerializer(Common::Serializer &s) override {
			s.syncAsByte(entity);
			s.syncAsByte(status);
			s.syncAsByte(windowCursor);
			s.syncAsByte(handleCursor);
			s.syncAsByte(model);
		}
	};

	Objects(LastExpressEngine *engine);

	const Object get(ObjectIndex index) const;
	void update(ObjectIndex index, EntityIndex entity, ObjectLocation status, CursorStyle cursor, CursorStyle cursor2);
	void updateModel(ObjectIndex index, ObjectModel model);

	// Serializable
	void saveLoadWithSerializer(Common::Serializer &s) override;

	/**
	 * Convert this object into a string representation.
	 *
	 * @return A string representation of this object.
	 */
	Common::String toString();

private:
	LastExpressEngine *_engine;

	Object _objects[kObjectMax];
};

} // End of namespace LastExpress

#endif // LASTEXPRESS_OBJECT_H
