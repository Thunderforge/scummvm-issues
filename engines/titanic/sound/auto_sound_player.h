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

#ifndef TITANIC_AUTO_SOUND_PLAYER_H
#define TITANIC_AUTO_SOUND_PLAYER_H

#include "titanic/core/game_object.h"

namespace Titanic {

class CAutoSoundPlayer : public CGameObject {
	DECLARE_MESSAGE_MAP;
	bool TurnOn(CTurnOn *msg);
	bool TurnOff(CTurnOff *msg);
	bool SignalObject(CSignalObject *msg);
	bool SetVolumeMsg(CSetVolumeMsg *msg);
	bool LoadSuccessMsg(CLoadSuccessMsg *msg);
public:
	int _unused;
	CString _filename;
	int _volume;
	int _balance;
	bool _repeated;
	int _soundHandle;
	int _stopSeconds;
	int _startSeconds;
	bool _active;
	bool _isVectorSound;
public:
	CLASSDEF;
	CAutoSoundPlayer();

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

#endif /* TITANIC_AUTO_SOUND_PLAYER_H */
