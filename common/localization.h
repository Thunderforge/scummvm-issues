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

#ifndef COMMON_LOCALIZATION_H
#define COMMON_LOCALIZATION_H

#include "common/language.h"
#include "common/keyboard.h"

namespace Common {

/**
 * @defgroup common_localization Localization
 * @ingroup common
 *
 * @brief Functions for managing localized elements of the GUI.
 *
 *
 * @{
 */

/**
 * Get localized equivalents for Y/N buttons of the specified language. In
 * case there is no specialized keys for the given language it will fall back
 * to the English keys.
 *
 * @param id Language id
 * @param keyYes Key code for yes
 * @param keyNo Key code for no
 */
void getLanguageYesNo(Language id, KeyCode &keyYes, KeyCode &keyNo);

/**
 * Get localized equivalents for Y/N buttons of the current translation
 * language of the ScummVM GUI.
 *
 * @param keyYes Key code for yes
 * @param keyNo Key code for no
 */
void getLanguageYesNo(KeyCode &keyYes, KeyCode &keyNo);

/** @} */

} // End of namespace Common

#endif
