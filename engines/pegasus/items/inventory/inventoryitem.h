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

#ifndef PEGASUS_ITEMS_INVENTORY_INVENTORYITEM_H
#define PEGASUS_ITEMS_INVENTORY_INVENTORYITEM_H

#include "pegasus/items/item.h"

namespace Pegasus {

// JMPInventoryInfo contains the resource data used by InventoryItems.

struct JMPInventoryInfo {
	TimeValue panelStart;
	TimeValue panelStop;
};

class InventoryItem : public Item {
public:
	InventoryItem(const ItemID, const NeighborhoodID, const RoomID, const DirectionConstant);
	~InventoryItem() override;

	ItemType getItemType() override;

	void getPanelTimes(TimeValue &, TimeValue &) const;
	TimeValue getLeftAreaTime() const;

	void setAnimationTime(const TimeValue);
	TimeValue getAnimationTime() const;

	virtual void toggleItemState() {}

	// Must affect images in left area.
	void select() override;
	void deselect() override;

protected:
	JMPInventoryInfo _inventoryInfo;
	ItemStateInfo _leftAreaInfo;
	TimeValue _itemAnimationTime;
};

} // End of namespace Pegasus

#endif
