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

#ifndef TITANIC_GONDOLIER_SLIDER_H
#define TITANIC_GONDOLIER_SLIDER_H

#include "titanic/game/gondolier/gondolier_base.h"

namespace Titanic {

class CGondolierSlider : public CGondolierBase {
	DECLARE_MESSAGE_MAP;
	bool MouseButtonDownMsg(CMouseButtonDownMsg *msg);
	bool MouseDragMoveMsg(CMouseDragMoveMsg *msg);
	bool EnterViewMsg(CEnterViewMsg *msg);
	bool MouseDragStartMsg(CMouseDragStartMsg *msg);
	bool StatusChangeMsg(CStatusChangeMsg *msg);
	bool MouseDragEndMsg(CMouseDragEndMsg *msg);
	bool IsHookedOnMsg(CIsHookedOnMsg *msg);
	bool FrameMsg(CFrameMsg *msg);
	bool SignalObject(CSignalObject *msg);
	bool ActMsg(CActMsg *msg);
private:
	Rect _rectUnused;
	Rect _thumbRect;
	Rect _defaultThumbRect;
	int _sliderIndex;
	CString _stringUnused;
	int _sliderNum;
	CString _armName;
	CString _signalTarget;
	bool _dragging;
public:
	CLASSDEF;
	CGondolierSlider();

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

#endif /* TITANIC_GONDOLIER_SLIDER_H */
