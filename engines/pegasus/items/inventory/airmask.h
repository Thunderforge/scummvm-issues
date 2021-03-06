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

#ifndef PEGASUS_ITEMS_INVENTORY_AIRMASK_H
#define PEGASUS_ITEMS_INVENTORY_AIRMASK_H

#include "pegasus/hotspot.h"
#include "pegasus/timers.h"
#include "pegasus/items/inventory/inventoryitem.h"

namespace Pegasus {

class AirMask : public InventoryItem, private Idler {
public:
	AirMask(const ItemID, const NeighborhoodID, const RoomID, const DirectionConstant);
	~AirMask() override;

	void writeToStream(Common::WriteStream *) override;
	void readFromStream(Common::ReadStream *) override;

	void setItemState(const ItemState) override;
	void putMaskOn();
	void takeMaskOff();
	void toggleItemState() override;
	void airQualityChanged();

	bool isAirMaskInUse();
	bool isAirMaskOn();
	bool isAirFilterOn();

	void refillAirMask();

	// Returns a percentage
	uint getAirLeft();

	void activateAirMaskHotspots();
	void clickInAirMaskHotspot();

protected:
	void airMaskTimerExpired();

	void removedFromInventory() override;
	void addedToInventory() override;
	void useIdleTime() override;

	Hotspot _toggleSpot;
	FuseFunction _oxygenTimer;
};

extern AirMask *g_airMask;

} // End of namespace Pegasus

#endif
