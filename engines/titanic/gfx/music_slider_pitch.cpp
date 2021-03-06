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

#include "titanic/gfx/music_slider_pitch.h"
#include "titanic/translation.h"

namespace Titanic {

BEGIN_MESSAGE_MAP(CMusicSliderPitch, CMusicSlider)
	ON_MESSAGE(MusicSettingChangedMsg)
	ON_MESSAGE(EnterViewMsg)
	ON_MESSAGE(QueryMusicControlSettingMsg)
END_MESSAGE_MAP()

void CMusicSliderPitch::save(SimpleFile *file, int indent) {
	file->writeNumberLine(1, indent);
	CMusicSlider::save(file, indent);
}

void CMusicSliderPitch::load(SimpleFile *file) {
	file->readNumber();
	CMusicSlider::load(file);
}

bool CMusicSliderPitch::MusicSettingChangedMsg(CMusicSettingChangedMsg *msg) {
	if (_enabled) {
		if (++_controlVal > _controlMax)
			_controlVal = 0;

		loadFrame(3 - _controlVal);
		playSound(TRANSLATE("z#54.wav", "z#585.wav"), 50);
	} else {
		playSound(TRANSLATE("z#46.wav", "z#577.wav"));
	}

	return true;
}

bool CMusicSliderPitch::EnterViewMsg(CEnterViewMsg *msg) {
	loadFrame(3 - _controlVal);
	return true;
}

bool CMusicSliderPitch::QueryMusicControlSettingMsg(CQueryMusicControlSettingMsg *msg) {
	msg->_value = _controlVal - 2;
	return true;
}

} // End of namespace Titanic
