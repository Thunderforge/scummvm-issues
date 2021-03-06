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

#include "common/util.h"
#include "common/stack.h"
#include "graphics/primitives.h"

#include "sci/sci.h"
#include "sci/engine/state.h"
#include "sci/engine/selector.h"
#include "sci/graphics/cache.h"
#include "sci/graphics/scifont.h"
#include "sci/graphics/fontsjis.h"
#include "sci/graphics/fontkorean.h"
#include "sci/graphics/view.h"

namespace Sci {

GfxCache::GfxCache(ResourceManager *resMan, GfxScreen *screen, GfxPalette *palette)
	: _resMan(resMan), _screen(screen), _palette(palette) {
}

GfxCache::~GfxCache() {
	purgeFontCache();
	purgeViewCache();
}

void GfxCache::purgeFontCache() {
	for (FontCache::iterator iter = _cachedFonts.begin(); iter != _cachedFonts.end(); ++iter) {
		delete iter->_value;
		iter->_value = 0;
	}

	_cachedFonts.clear();
}

void GfxCache::purgeViewCache() {
	for (ViewCache::iterator iter = _cachedViews.begin(); iter != _cachedViews.end(); ++iter) {
		delete iter->_value;
		iter->_value = 0;
	}

	_cachedViews.clear();
}

GfxFont *GfxCache::getFont(GuiResourceId fontId) {
	if (_cachedFonts.size() >= MAX_CACHED_FONTS)
		purgeFontCache();

	if (!_cachedFonts.contains(fontId)) {
		// Create special Korean font in korean games, when font 1001 is selected
		if ((fontId == 1001) && (g_sci->getLanguage() == Common::KO_KOR))
			_cachedFonts[fontId] = new GfxFontKorean(_screen, fontId);
		// Create special SJIS font in japanese games, when font 900 is selected
		else if ((fontId == 900) && (g_sci->getLanguage() == Common::JA_JPN))
			_cachedFonts[fontId] = new GfxFontSjis(_screen, fontId);
		else
			_cachedFonts[fontId] = new GfxFontFromResource(_resMan, _screen, fontId);
	}

	return _cachedFonts[fontId];
}

GfxView *GfxCache::getView(GuiResourceId viewId) {
	if (_cachedViews.size() >= MAX_CACHED_VIEWS)
		purgeViewCache();

	if (!_cachedViews.contains(viewId))
		_cachedViews[viewId] = new GfxView(_resMan, _screen, _palette, viewId);

	return _cachedViews[viewId];
}

int16 GfxCache::kernelViewGetCelWidth(GuiResourceId viewId, int16 loopNo, int16 celNo) {
	return getView(viewId)->getCelInfo(loopNo, celNo)->scriptWidth;
}

int16 GfxCache::kernelViewGetCelHeight(GuiResourceId viewId, int16 loopNo, int16 celNo) {
	return getView(viewId)->getCelInfo(loopNo, celNo)->scriptHeight;
}

int16 GfxCache::kernelViewGetLoopCount(GuiResourceId viewId) {
#ifdef ENABLE_SCI32
	if (getSciVersion() >= SCI_VERSION_2) {
		return CelObjView::getNumLoops(viewId);
	}
#endif
	return getView(viewId)->getLoopCount();
}

int16 GfxCache::kernelViewGetCelCount(GuiResourceId viewId, int16 loopNo) {
#ifdef ENABLE_SCI32
	if (getSciVersion() >= SCI_VERSION_2) {
		return CelObjView::getNumCels(viewId, loopNo);
	}
#endif
	return getView(viewId)->getCelCount(loopNo);
}

} // End of namespace Sci
