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

#ifndef PEGASUS_NEIGHBORHOOD_CALDORIA_CALDORIAMESSAGES_H
#define PEGASUS_NEIGHBORHOOD_CALDORIA_CALDORIAMESSAGES_H

#include "pegasus/input.h"
#include "pegasus/interaction.h"
#include "pegasus/movie.h"
#include "pegasus/notification.h"
#include "pegasus/timers.h"

namespace Pegasus {

class Neighborhood;

class CaldoriaMessages : public GameInteraction, public Notification, public NotificationReceiver {
public:
	CaldoriaMessages(Neighborhood *, const NotificationID, NotificationManager *);
	~CaldoriaMessages() override {}

	void setSoundFXLevel(const uint16) override;

protected:
	void openInteraction() override;
	void initInteraction() override;
	void closeInteraction() override;
	void receiveNotification(Notification *, const NotificationFlags) override;
	void clickInHotspot(const Input &, const Hotspot *) override;
	void play1Message(uint);

	Movie _messageMovie;
	NotificationCallBack _messageCallBack;
	Notification *_neighborhoodNotification;
	uint _messageNumber;
};

} // End of namespace Pegasus

#endif
