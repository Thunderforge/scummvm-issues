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

#ifndef BLADERUNNER_IMAGE_H
#define BLADERUNNER_IMAGE_H

#include "graphics/surface.h"

namespace Common {
	class String;
}

namespace BladeRunner {

class BladeRunnerEngine;

class Image {
	BladeRunnerEngine *_vm;
	Graphics::Surface  _surface;

public:
	Image(BladeRunnerEngine *vm);
	~Image();

	bool open(const Common::String &name);
	void copyToSurface(Graphics::Surface *surface) const;
};

} // End of namespace BladeRunner

#endif
