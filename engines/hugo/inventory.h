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

/*
 * This code is based on original Hugo Trilogy source code
 *
 * Copyright (c) 1989-1995 David P. Gray
 *
 */

#ifndef HUGO_INVENTORY_H
#define HUGO_INVENTORY_H
namespace Hugo {

/**
 * Actions for Process_inventory()
 */
enum InvAct {kInventoryActionInit, kInventoryActionLeft, kInventoryActionRight, kInventoryActionGet};

class InventoryHandler {
public:
	InventoryHandler(HugoEngine *vm);

	void     setInventoryObjId(int16 objId);
	void     setInventoryState(Istate state);
	void     freeInvent();

	int16    getInventoryObjId() const;
	Istate   getInventoryState() const;

	int16 findIconId(int16 objId);
	void  loadInvent(Common::SeekableReadStream &in);
	int16 processInventory(const int action, ...);
	void  runInventory();

private:
	HugoEngine *_vm;

	static const int kStepDy = 8;                   // Pixels per step movement

	int16    _firstIconId;                          // Index of first icon to display
	int16   *_invent;
	Istate   _inventoryState;                       // Inventory icon bar state
	int16    _inventoryHeight;                      // Inventory icon bar height
	int16    _inventoryObjId;                       // Inventory object selected, or -1
	byte     _maxInvent;

	void constructInventory(const int16 imageTotNumb, int displayNumb, const bool scrollFl, int16 firstObjId);
};

} // End of namespace Hugo

#endif // HUGO_INVENTORY_H
