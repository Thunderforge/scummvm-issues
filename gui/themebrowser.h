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

#ifndef GUI_THEMEBROWSER_H
#define GUI_THEMEBROWSER_H

#include "gui/dialog.h"
#include "gui/ThemeEngine.h"

#include "common/str.h"
#include "common/list.h"

namespace GUI {

class CommandSender;
class ListWidget;

class ThemeBrowser : public Dialog {
public:
	ThemeBrowser();

	void open() override;
	void handleCommand(CommandSender *sender, uint32 cmd, uint32 data) override;

	const Common::String &getSelected() const { return _select; }
	const Common::String &getSelectedName() const { return _selectName; }
private:
	ListWidget *_fileList;
	Common::String _select;
	Common::String _selectName;

	typedef Common::List<ThemeEngine::ThemeDescriptor> ThemeDescList;
	ThemeDescList _themes;

	void updateListing();
};

} // End of namespace GUI

#endif
