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

#include "titanic/true_talk/tt_major_word.h"

namespace Titanic {

bool TTmajorWord::_staticFlag;

TTmajorWord::TTmajorWord(const TTstring &str, WordClass wordClass, int val2, int val3) :
		TTword(str, wordClass, val2), _field2C(val3) {
}

TTmajorWord::TTmajorWord(const TTmajorWord *src) : TTword(src) {
	if (src->getStatus()) {
		_field2C = 0;
		_status = SS_5;
	} else {
		_field2C = src->_field2C;
	}
}

int TTmajorWord::saveData(SimpleFile *file, int val) const {
	int result = TTword::save(file);
	if (!result) {
		file->writeFormat("%1.0d", val);
		file->writeFormat("%c", '\n');
		if (_synP)
			result = _synP->save(file);
	}

	return result;
}

TTword *TTmajorWord::copy() const {
	TTmajorWord *returnWordP = new TTmajorWord(this);
	returnWordP->_status = _status;
	if (!_status) {
		_staticFlag = false;
		return returnWordP;
	} else if (_status == SS_13 && !_staticFlag) {
		_staticFlag = true;
		delete returnWordP;
		return copy();
	} else {
		delete returnWordP;
		return nullptr;
	}
}

} // End of namespace Titanic
