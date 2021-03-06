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

#ifndef BACKEND_MORPHOS_DIALOGS_H
#define BACKEND_MORPHOS_DIALOGS_H

#if defined(__MORPHOS__) && defined(USE_SYSDIALOGS)

#include "common/fs.h"
#include "common/dialogs.h"

class MorphosDialogManager : public Common::DialogManager {
public:
	virtual DialogResult showFileBrowser(const Common::U32String &title, Common::FSNode &choice, bool isDirBrowser);

private:
	char *utf8ToLocal(char *in);
};

#endif

#endif // BACKEND_MORPHOS_DIALOGS_H
