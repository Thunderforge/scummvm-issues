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

#ifndef TITANIC_MUSIC_SWITCH_INVERSION_H
#define TITANIC_MUSIC_SWITCH_INVERSION_H

#include "titanic/gfx/music_switch.h"

namespace Titanic {

class CMusicSwitchInversion : public CMusicSwitch {
	DECLARE_MESSAGE_MAP;
	bool MusicSettingChangedMsg(CMusicSettingChangedMsg *msg);
	bool EnterViewMsg(CEnterViewMsg *msg);
	bool QueryMusicControlSettingMsg(CQueryMusicControlSettingMsg *msg);
public:
	CLASSDEF;

	/**
	 * Save the data for the class to file
	 */
	void save(SimpleFile *file, int indent) override;

	/**
	 * Load the data for the class from file
	 */
	void load(SimpleFile *file) override;
};

} // End of namespace Titanic

#endif /* TITANIC_MUSIC_SWITCH_INVERSION_H */
