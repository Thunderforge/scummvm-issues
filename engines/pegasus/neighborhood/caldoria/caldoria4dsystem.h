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

#ifndef PEGASUS_NEIGHBORHOOD_CALDORIA_CALDORIA4DSYSTEM_H
#define PEGASUS_NEIGHBORHOOD_CALDORIA_CALDORIA4DSYSTEM_H

#include "pegasus/interaction.h"
#include "pegasus/movie.h"
#include "pegasus/notification.h"
#include "pegasus/timers.h"

namespace Pegasus {

class Neighborhood;

class Caldoria4DSystem : public GameInteraction, private Idler, public NotificationReceiver {
public:
	Caldoria4DSystem(Neighborhood *);
	~Caldoria4DSystem() override;

	void shutDown4DSystem();

protected:
	void openInteraction() override;
	void initInteraction() override;
	void closeInteraction() override;

	void handleInput(const Input &, const Hotspot *) override;
	void activateHotspots() override;
	void clickInHotspot(const Input &, const Hotspot *) override;
	void receiveNotification(Notification *, const NotificationFlags) override;
	void setSpritesMovie();
	void makeIslandChoice();
	void makeRockChoice();
	void makeMountainChoice();
	void makeOrchestralChoice();
	void makeDesertChoice();
	void makeRhythmsChoice();
	void makeAcousticChoice();

	void useIdleTime() override;
	void loopExtra(const ExtraID);

	void playSound(const Common::String &baseFileName);

	Movie _4DSpritesMovie;
	TimeScale _4DSpritesScale;
	uint _whichMenu;
	uint _videoChoice;
	uint _audioChoice;
	Notification *_neighborhoodNotification;
	TimeValue _loopStart;
	HotSpotID _clickedHotspotID;
};

} // End of namespace Pegasus

#endif
