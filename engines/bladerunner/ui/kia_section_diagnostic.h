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

#ifndef BLADERUNNER_KIA_SECTION_DIAGNOSTIC_H
#define BLADERUNNER_KIA_SECTION_DIAGNOSTIC_H

#include "bladerunner/color.h"
#include "bladerunner/ui/kia_section_base.h"

namespace BladeRunner {

class TextResource;

class KIASectionDiagnostic : public KIASectionBase {
	static const Color256 kTextColors[];
	static const int      kLineHeight = 18;

	TextResource *_text;
	int           _offset;
	uint32        _timeLast;

public:
	KIASectionDiagnostic(BladeRunnerEngine *vm);

	void open() override;
	void close() override;

	void draw(Graphics::Surface &surface) override;
};

} // End of namespace BladeRunner

#endif
