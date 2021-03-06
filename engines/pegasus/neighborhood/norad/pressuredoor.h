/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1995-1997 Presto Studios, Inc.
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

#ifndef PEGASUS_NEIGHBORHOOD_NORAD_PRESSUREDOOR_H
#define PEGASUS_NEIGHBORHOOD_NORAD_PRESSUREDOOR_H

#include "pegasus/interaction.h"
#include "pegasus/movie.h"
#include "pegasus/notification.h"
#include "pegasus/neighborhood/norad/pressuretracker.h"

namespace Pegasus {

static const short kNormalSubRoomPressure = 2;

class PressureDoor : public GameInteraction, public NotificationReceiver {
public:
	PressureDoor(Neighborhood *, bool isUpperDoor, const HotSpotID, const HotSpotID,
			const HotSpotID, TimeValue pressureSoundIn, TimeValue pressureSoundOut,
			TimeValue equalizeSoundIn, TimeValue equalizeSoundOut);
	~PressureDoor() override {}

	void incrementPressure(const HotSpotID);
	void stopChangingPressure();

	void playAgainstRobot();

	bool canSolve() override;
	void doSolve() override;

protected:
	void openInteraction() override;
	void initInteraction() override;
	void closeInteraction() override;

	void activateHotspots() override;
	void clickInHotspot(const Input &, const Hotspot *) override;

	void receiveNotification(Notification *, const NotificationFlags) override;

	Movie _levelsMovie;
	TimeScale _levelsScale;
	Movie _typeMovie;
	TimeScale _typeScale;
	Sprite _upButton;
	Sprite _downButton;
	Notification _pressureNotification;
	NotificationCallBack _pressureCallBack;
	Notification *_neighborhoodNotification;
	int _gameState;
	HotSpotID _upHotspotID;
	HotSpotID _downHotspotID;
	HotSpotID _outHotspotID;
	PressureTracker _doorTracker;
	TimeValue _pressureSoundIn;
	TimeValue _pressureSoundOut;
	TimeValue _equalizeSoundIn;
	TimeValue _equalizeSoundOut;
	bool _isUpperDoor;

	bool _playingAgainstRobot, _typePunched;
	int _robotState, _punchCount;
	TimeBase _utilityTimer;
	Notification _utilityNotification;
	NotificationCallBack _utilityCallBack;
	TimeValue _punchInTime;
};

} // End of namespace Pegasus

#endif
