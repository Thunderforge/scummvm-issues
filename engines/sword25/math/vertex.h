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

/*
 * This code is based on Broken Sword 2.5 engine
 *
 * Copyright (c) Malte Thiesen, Daniel Queteschiner and Michael Elsdoerfer
 *
 * Licensed under GNU GPL v2
 *
 */

/*
	BS_Vertex
	---------

	Autor: Malte Thiesen
*/

#ifndef SWORD25_VERTEX_H
#define SWORD25_VERTEX_H

// Includes
#include "common/rect.h"
#include "sword25/kernel/common.h"

struct lua_State;

namespace Sword25 {

/**
 * Defines a 2-D Vertex
 */
class Vertex : public Common::Point {
public:
	Vertex() : Point() {}
	Vertex(int x_, int y_) : Point(x_, y_) {}
	Vertex(Point p) : Point(p) {}

	/**
	 * Calculates the square of the distance between two Vertecies.
	 * @param Vertex        The vertex for which the distance is to be calculated
	 * @return              Returns the square of the distance between itself and the passed vertex
	 * @remark              If only distances should be compared, sqrDist() should be used, since it is faster.
	 */
	inline int distance(const Vertex &vertex) const {
		return (int)(sqrt(static_cast<float>(sqrDist(vertex))) + 0.5);
	}

	static Vertex &luaVertexToVertex(lua_State *L, int StackIndex, Vertex &vertex);
	static void vertexToLuaVertex(lua_State *L, const Vertex &vertex);
};

} // End of namespace Sword25

#endif
