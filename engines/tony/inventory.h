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
 * This code is based on original Tony Tough source code
 *
 * Copyright (c) 1997-2003 Nayma Software
 */

#ifndef TONY_INVENTORY_H
#define TONY_INVENTORY_H

#include "common/scummsys.h"
#include "common/mutex.h"
#include "tony/font.h"
#include "tony/game.h"
#include "tony/gfxcore.h"
#include "tony/loc.h"

namespace Tony {

struct RMInventoryItem {
	RMItem _icon;
	RMGfxSourceBuffer8RLEByteAA *_pointer;
	int _status;
};

class RMInventory : public RMGfxWoodyBuffer {
private:
	enum InventoryState {
		CLOSED,
		OPENING,
		OPENED,
		CLOSING,
		SELECTING
	};

protected:
	int _nItems;
	RMInventoryItem *_items;

	int _inv[256];
	int _nInv;
	int _curPutY;
	uint32 _curPutTime;

	int _curPos;
	InventoryState _state;
	bool _bHasFocus;
	int _nSelectObj;
	int _nCombine;
	bool _bCombining;

	bool _bBlinkingRight, _bBlinkingLeft;

	int _miniAction;
	RMItem _miniInterface;
	RMText _hints[3];

	Common::Mutex _csModifyInterface;

protected:
	/**
	 * Prepare the image inventory. It should be recalled whenever the inventory changes
	 */
	void prepare();

	/**
	 * Check if the mouse Y position is conrrect, even under the inventory portion of the screen
	 */
	bool checkPointInside(const RMPoint &pt);

public:
	RMInventory();
	~RMInventory() override;

	/**
	 * Prepare a frame
	 */
	void doFrame(RMGfxTargetBuffer &bigBuf, RMPointer &ptr, RMPoint mpos, bool bCanOpen);

	/**
	 * Initialization and closing
	 */
	using RMGfxWoodyBuffer::init;
	void init();
	void close();
	void reset();

	/**
	 * Overload test for removal from OT list
	 */
	void removeThis(CORO_PARAM, bool &result) override;

	/**
	 * Overload the drawing of the inventory
	 */
	void draw(CORO_PARAM, RMGfxTargetBuffer &bigBuf, RMGfxPrimitive *prim) override;

	/**
	 * Method for determining whether the inventory currently has the focus
	 */
	bool haveFocus(const RMPoint &mpos);

	/**
	 * Method for determining if the mini interface is active
	 */
	bool miniActive();

	/**
	 * Handle the left mouse click (only when the inventory has the focus)
	 */
	bool leftClick(const RMPoint &mpos, int &nCombineObj);

	/**
	 * Handle the right mouse button (only when the inventory has the focus)
	 */
	void rightClick(const RMPoint &mpos);
	bool rightRelease(const RMPoint &mpos, RMTonyAction &curAction);

	/**
	 * Warn that an item combine is over
	 */
	void endCombine();

public:
	/**
	 * Add an item to the inventory
	 */
	void addItem(int code);
	RMInventory &operator+=(RMItem *item);
	RMInventory &operator+=(RMItem &item);
	RMInventory &operator+=(int code);

	/**
	 * Removes an item
	 */
	void removeItem(int code);

	/**
	 * We are on an object?
	 */
	RMItem *whichItemIsIn(const RMPoint &mpt);
	bool itemInFocus(const RMPoint &mpt);

	/**
	 * Change the icon of an item
	 */
	void changeItemStatus(uint32 dwCode, uint32 dwStatus);

	/**
	 * Save methods
	 */
	int getSaveStateSize();
	void saveState(byte *state);
	int loadState(byte *state);
};

class RMInterface : public RMGfxSourceBuffer8RLEByte {
private:
	bool _bActive;
	RMPoint _mpos;
	RMPoint _openPos;
	RMPoint _openStart;
	RMText _hints[5];
	RMGfxSourceBuffer8RLEByte _hotzone[5];
	RMRect _hotbbox[5];
	bool _bPerorate;
	int _lastHotZone;

protected:
	/**
	 * Return which box a given point is in
	 */
	int onWhichBox(RMPoint pt);

public:
	RMInterface();
	~RMInterface() override;

	/**
	 * The usual DoFrame (poll the graphics engine)
	 */
	void doFrame(RMGfxTargetBuffer &bigBuf, RMPoint mousepos);

	/**
	 * TRUE if it is active (you can select items)
	 */
	bool active();

	/**
	 * Initialization
	 */
	using RMGfxSourceBuffer8RLEByte::init;
	void init();
	void close();

	/**
	 * Reset the interface
	 */
	void reset();

	/**
	 * Warns of mouse clicks and releases
	 */
	void clicked(const RMPoint &mousepos);
	bool released(const RMPoint &mousepos, RMTonyAction &action);

	/**
	 * Enables or disables the fifth verb
	 */
	void setPerorate(bool bOn);
	bool getPerorate();

	/**
	 * Overloaded Draw
	 */
	void draw(CORO_PARAM, RMGfxTargetBuffer &bigBuf, RMGfxPrimitive *prim) override;
};

} // End of namespace Tony

#endif
