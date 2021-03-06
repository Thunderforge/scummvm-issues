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

#ifndef PARALLACTION_SAVELOAD_H
#define PARALLACTION_SAVELOAD_H

namespace Parallaction {

struct Character;

class SaveLoad {
protected:
	Common::SaveFileManager	*_saveFileMan;
	Common::String _saveFilePrefix;

	Common::String genSaveFileName(uint slot);
	Common::InSaveFile *getInSaveFile(uint slot);
	Common::OutSaveFile *getOutSaveFile(uint slot);
	int selectSaveFile(Common::String &selectedName, bool saveMode, const Common::U32String &caption, const Common::U32String &button);
	int buildSaveFileList(Common::StringArray& l);
	virtual void doLoadGame(uint16 slot) = 0;
	virtual void doSaveGame(uint16 slot, const char* name) = 0;

public:
	SaveLoad(Common::SaveFileManager* saveFileMan, const char *prefix) : _saveFileMan(saveFileMan), _saveFilePrefix(prefix) { }
	virtual ~SaveLoad() { }

	virtual bool loadGame();
	virtual bool saveGame();

	virtual void getGamePartProgress(bool *complete, int size) = 0;
	virtual void setPartComplete(const char *part) = 0;

	virtual void renameOldSavefiles() { }
};

class SaveLoad_ns : public SaveLoad {
	Parallaction_ns *_vm;

protected:
	void renameOldSavefiles() override;
	void doLoadGame(uint16 slot) override;
	void doSaveGame(uint16 slot, const char* name) override;

public:
	SaveLoad_ns(Parallaction_ns *vm, Common::SaveFileManager *saveFileMan) : SaveLoad(saveFileMan, "nippon"), _vm(vm) { }

	bool saveGame() override;

	void getGamePartProgress(bool *complete, int size) override;
	void setPartComplete(const char *part) override;
};

class SaveLoad_br : public SaveLoad {
//	Parallaction_br *_vm;
	void doLoadGame(uint16 slot) override;
	void doSaveGame(uint16 slot, const char* name) override;

public:
	SaveLoad_br(Parallaction_br *vm, Common::SaveFileManager *saveFileMan) : SaveLoad(saveFileMan, "bra") { }

	void getGamePartProgress(bool *complete, int size) override;
	void setPartComplete(const char *part) override;
};

} // namespace Parallaction

#endif
