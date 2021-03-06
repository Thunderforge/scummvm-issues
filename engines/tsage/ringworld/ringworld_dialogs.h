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

#ifndef TSAGE_RINGWORLD_DIALOGS_H
#define TSAGE_RINGWORLD_DIALOGS_H

#include "tsage/dialogs.h"
#include "tsage/events.h"
#include "tsage/graphics.h"
#include "common/list.h"
#include "common/rect.h"
#include "common/system.h"

namespace TsAGE {

namespace Ringworld {

class RightClickButton : public GfxButton {
private:
	GfxSurface *_savedButton;
public:
	int _buttonIndex;

	RightClickButton(int buttonIndex, int xp, int yp);
	~RightClickButton() override { delete _savedButton; }

	void highlight() override;
};

class RightClickDialog : public GfxDialog {
private:
	GfxSurface _surface;
	RightClickButton *_highlightedButton;
	int _selectedAction;
	RightClickButton _walkButton, _lookButton, _useButton, _talkButton, _inventoryButton, _optionsButton;

	RightClickButton *findButton(const Common::Point &pt);
public:
	RightClickDialog();
	~RightClickDialog() override;

	void draw() override;
	bool process(Event &event) override;
	void execute();
};

class OptionsDialog : public ModalDialog {
private:
	GfxButton _btnSave, _btnRestore, _btnRestart;
	GfxButton _btnQuit, _btnResume;
	GfxButton _btnSound;
	GfxMessage _gfxMessage;
public:
	OptionsDialog();
	~OptionsDialog() override {}
	GfxButton *execute() { return GfxDialog::execute(&_btnResume); }

	static void show();
};

/*--------------------------------------------------------------------------*/

class GfxInvImage : public GfxImage {
public:
	InvObject *_invObject;
public:
	GfxInvImage() : GfxImage(), _invObject(NULL) {}

	bool process(Event &event) override;
};

#define MAX_INVOBJECT_DISPLAY 20

class InventoryDialog : public ModalDialog {
private:
	Common::Array<GfxInvImage *> _images;
	GfxButton _btnOk, _btnLook;
public:
	InventoryDialog();
	~InventoryDialog() override;
	void execute();

	static void show();
};

} // End of namespace Ringworld

} // End of namespace TsAGE

#endif
