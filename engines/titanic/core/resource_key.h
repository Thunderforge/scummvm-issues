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

#ifndef TITANIC_RESOURCE_KEY_H
#define TITANIC_RESOURCE_KEY_H

#include "titanic/support/string.h"
#include "titanic/core/saveable_object.h"

namespace Titanic {

class CResourceKey: public CSaveableObject {
private:
	CString _key;
	CString _value;

	void setValue(const CString &name);
public:
	CLASSDEF;
	CResourceKey() {}
	CResourceKey(const CString &name) { setValue(name); }

	/**
	 * Save the data for the class to file
	 */
	void save(SimpleFile *file, int indent) override;

	/**
	 * Load the data for the class from file
	 */
	void load(SimpleFile *file) override;

	/**
	 * Return the key
	 */
	const CString &getString() const { return _key; }

	/**
	 * Extracts a filename from the resource key
	 */
	CString getFilename() const;

	/**
	 * Scans for a file with a matching name
	 */
	bool scanForFile() const;

	/**
	 * Returns the type of the resource based on it's extension
	 */
	FileType fileTypeSuffix() const;

	/**
	 * Returns the type of the resource based on it's extension
	 */
	ImageType imageTypeSuffix() const;
};

} // End of namespace Titanic

#endif /* TITANIC_RESOURCE_KEY_H */
