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

#include "audio/musicplugin.h"
#include "common/hash-str.h"

MusicDevice::MusicDevice(MusicPluginObject const *musicPlugin, Common::String name, MusicType mt) :
	_musicDriverName(musicPlugin->getName()), _musicDriverId(musicPlugin->getId()),
	_name(name), _type(mt) {
}

Common::String MusicDevice::getCompleteName() {
	Common::String name;

	if (_name.empty()) {
		// Default device, just show the driver name
		name = _musicDriverName;
	} else {
		// Show both device and driver names
		name = _name;
		name += " [";
		name += _musicDriverName;
		name += "]";
	}

	return name;
}

Common::String MusicDevice::getCompleteId() {
	Common::String id = _musicDriverId;
	if (!_name.empty()) {
		id += "_";
		id += _name;
	}

	return id;
}

MidiDriver::DeviceHandle MusicDevice::getHandle() {
	return (MidiDriver::DeviceHandle)getCompleteId().hash();
}
