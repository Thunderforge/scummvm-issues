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

#if defined(WIN32)

// Disable symbol overrides so that we can use system headers.
#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "backends/fs/windows/windows-fs.h"
#include "backends/fs/windows/windows-fs-factory.h"

AbstractFSNode *WindowsFilesystemFactory::makeRootFileNode() const {
	return new WindowsFilesystemNode();
}

AbstractFSNode *WindowsFilesystemFactory::makeCurrentDirectoryFileNode() const {
	return new WindowsFilesystemNode("", true);
}

AbstractFSNode *WindowsFilesystemFactory::makeFileNodePath(const Common::String &path) const {
	return new WindowsFilesystemNode(path, false);
}
#endif
