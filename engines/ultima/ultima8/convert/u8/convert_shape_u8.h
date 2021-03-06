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

#ifndef ULTIMA8_CONVERT_U8_CONVERTSHAPEU8_H
#define ULTIMA8_CONVERT_U8_CONVERTSHAPEU8_H

#include "ultima/ultima8/convert/convert_shape.h"

namespace Ultima {
namespace Ultima8 {

// Shape format configuration for Ultima 8
extern const ConvertShapeFormat		U8ShapeFormat;

// Shape format configuration for Ultima 8 2D
extern const ConvertShapeFormat		U82DShapeFormat;

// Shape format configuration for Ultima 8 SKF file shapes
extern const ConvertShapeFormat		U8SKFShapeFormat;

// Shape format configuration for Compressed Ultima 8 shapes
extern const ConvertShapeFormat		U8CMPShapeFormat;

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
