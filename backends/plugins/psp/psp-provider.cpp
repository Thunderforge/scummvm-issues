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

#define FORBIDDEN_SYMBOL_EXCEPTION_time_h
#include "common/scummsys.h"

#if defined(DYNAMIC_MODULES) && defined(__PSP__)

#include <psputils.h>
#include <psputilsforkernel.h>

#include "backends/plugins/psp/psp-provider.h"
#include "backends/plugins/elf/mips-loader.h"

class PSPDLObject : public MIPSDLObject {
protected:
	virtual void flushDataCache(void *ptr, uint32 len) const {
		sceKernelDcacheWritebackRange(ptr, len);
		sceKernelIcacheInvalidateRange(ptr, len);
	}
};

Plugin *PSPPluginProvider::createPlugin(const Common::FSNode &node) const {
	return new TemplatedELFPlugin<PSPDLObject>(node.getPath());
}

#endif // defined(DYNAMIC_MODULES) && defined(__PSP__)
