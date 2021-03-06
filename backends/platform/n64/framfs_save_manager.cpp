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

#include <n64utils.h>

#include "framfs_save_manager.h"

bool fram_deleteSaveGame(const char *filename) {
	int res = framfs_removeFile(filename);

	return (res == 0);
}

uint32 InFRAMSave::read(void *buf, uint32 cnt) {
	return framfs_read(buf, 1, cnt, fd);
}

bool InFRAMSave::seek(int64 offs, int whence) {
	framfs_seek(fd, offs, whence);

	return true;
}

bool InFRAMSave::skip(uint32 offset) {
	framfs_seek(fd, offset, SEEK_CUR);

	return true;
}

uint32 OutFRAMSave::write(const void *buf, uint32 cnt) {
	return framfs_write(buf, 1, cnt, fd);
}

Common::StringArray FRAMSaveManager::listSavefiles(const Common::String &pattern) {
	FRAMDIR *dirp = framfs_opendir();
	framfs_dirent *dp;
	Common::StringArray list;
	Common::String *fname;

	while ((dp = framfs_readdir(dirp)) != NULL) {
		fname = new Common::String(dp->entryname);
		if (fname->matchString(pattern, false, NULL))
			list.push_back(dp->entryname);

		delete fname;
		free(dp);
	}

	framfs_closedir(dirp);

	return list;
}
