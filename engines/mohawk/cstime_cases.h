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

#ifndef MOHAWK_CSTIME_CASES_H
#define MOHAWK_CSTIME_CASES_H

#include "mohawk/cstime_game.h"

namespace Mohawk {

class CSTimeCase1 : public CSTimeCase {
public:
	CSTimeCase1(MohawkEngine_CSTime *vm);
	~CSTimeCase1() override;

	bool checkConvCondition(uint16 conditionId) override;
	bool checkAmbientCondition(uint16 charId, uint16 ambientId) override;
	bool checkObjectCondition(uint16 objectId) override;
	void selectHelpStrings() override;
	void handleConditionalEvent(const CSTimeEvent &event) override;

protected:
	void incorrectBodySequence(uint16 stage, uint16 speech, uint16 feature);
};

} // End of namespace Mohawk

#endif
