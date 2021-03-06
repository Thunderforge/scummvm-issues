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

#ifndef ULTIMA8_GUMPS_CRUINVENTORYGUMP_H
#define ULTIMA8_GUMPS_CRUINVENTORYGUMP_H

#include "ultima/ultima8/gumps/cru_stat_gump.h"
#include "ultima/ultima8/misc/classtype.h"

namespace Ultima {
namespace Ultima8 {

class TextWidget;

/**
 * Inventory box, the 3rd box along the bottom of the screen
 */
class CruInventoryGump : public CruStatGump {
public:
	ENABLE_RUNTIME_CLASSTYPE()

	CruInventoryGump();
	CruInventoryGump(Shape *shape, int x);
	~CruInventoryGump() override;

	// Init the gump, call after construction
	void InitGump(Gump *newparent, bool take_focus = true) override;

	// Paint this Gump
	void PaintThis(RenderSurface *, int32 lerp_factor, bool scaled) override;

	bool loadData(Common::ReadStream *rs, uint32 version);
	void saveData(Common::WriteStream *ws) override;

private:
	Gump *_inventoryItemGump;
	TextWidget *_inventoryText;

	void resetText();
};

} // End of namespace Ultima8
} // End of namespace Ultima

#endif
