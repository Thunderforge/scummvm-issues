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

#include "common/memstream.h"
#include "common/textconsole.h"
#include "sword25/gfx/screenshot.h"
#include "sword25/kernel/filesystemutil.h"

namespace Sword25 {

#define THUMBNAIL_VERSION 1

bool Screenshot::saveToFile(Graphics::Surface *data, Common::WriteStream *stream) {
	// Convert the RGBA data to RGB
	const uint32 *pSrc = (const uint32 *)data->getPixels();

	// Write our own custom header
	stream->writeUint32BE(MKTAG('S','C','R','N'));	// SCRN, short for "Screenshot"
	stream->writeUint16LE(data->w);
	stream->writeUint16LE(data->h);
	stream->writeByte(THUMBNAIL_VERSION);

	for (int y = 0; y < data->h; y++) {
		for (int x = 0; x < data->w; x++) {
			// This is only called by createThumbnail below, which
			// provides a fake 'surface' with LE data in it.
			byte a, r, g, b;

			data->format.colorToARGB(*pSrc++, a, r, g, b);
			stream->writeByte(r);
			stream->writeByte(g);
			stream->writeByte(b);
		}
	}

	return true;
}

// -----------------------------------------------------------------------------

Common::SeekableReadStream *Screenshot::createThumbnail(Graphics::Surface *data) {
	// This method takes a screen image with a dimension of 800x600, and creates a screenshot with a dimension of 200x125.
	// First 50 pixels are cut off the top and bottom (the interface boards in the game). The remaining image of 800x500
	// will be on a 16th of its size, reduced by being handed out in 4x4 pixel blocks and the average of each block
	// generates a pixel of the target image. Finally, the result as a PNG file is stored as a file.

	// The source image must be 800x600.
	if (data->w != 800 || data->h != 600 || data->format.bytesPerPixel != 4) {
		error("The sreenshot dimensions have to be 800x600 in order to be saved as a thumbnail.");
		return 0;
	}

	// Buffer for the output thumbnail
	Graphics::Surface thumbnail;
	thumbnail.create(200, 125, g_system->getScreenFormat());

	// Uber das Zielbild iterieren und einen Pixel zur Zeit berechnen.
	uint x, y;
	x = y = 0;

	for (uint32 *pDest = (uint32 *)thumbnail.getPixels(); pDest < thumbnail.getBasePtr(0, thumbnail.h); ) {
		// Get an average over a 4x4 pixel block in the source image
		int alpha, red, green, blue;
		alpha = red = green = blue = 0;
		for (int j = 0; j < 4; ++j) {
			const uint32 *srcP = (const uint32 *)data->getBasePtr(x * 4, y * 4 + j + 50);
			for (int i = 0; i < 4; ++i) {
				byte a, r, g, b;
				data->format.colorToARGB(*(srcP + i), a, r, g, b);
				alpha += a;
				red += r;
				green += g;
				blue += b;
			}
		}

		*pDest++ = thumbnail.format.ARGBToColor(alpha / 16, red / 16, green / 16, blue / 16);

		// Move to next block
		++x;
		if (x == (uint)thumbnail.w) {
			x = 0;
			++y;
		}
	}

	// Create a PNG representation of the thumbnail data
	Common::MemoryWriteStreamDynamic stream(DisposeAfterUse::NO);
	saveToFile(&thumbnail, &stream);
	thumbnail.free();

	// Output a MemoryReadStream that encompasses the written data
	Common::SeekableReadStream *result = new Common::MemoryReadStream(stream.getData(), stream.size(),
		DisposeAfterUse::YES);
	return result;
}

} // End of namespace Sword25
