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

#include "graphics/scaler/intern.h"
#include "graphics/scaler/aspect.h"

#ifdef USE_ARM_NEON_ASPECT_CORRECTOR
#include <arm_neon.h>
#endif

#define	kSuperFastAndUglyAspectMode	0	// No interpolation at all, but super-fast
#define	kVeryFastAndGoodAspectMode	1	// Good quality with very good speed
#define	kFastAndVeryGoodAspectMode	2	// Very good quality with good speed
#define	kSlowAndPerfectAspectMode	3	// Accurate but slow code

#define ASPECT_MODE	kVeryFastAndGoodAspectMode


#if ASPECT_MODE == kSlowAndPerfectAspectMode

template<typename ColorMask, int scale>
static inline uint16 interpolate5(uint16 A, uint16 B) {
	uint16 r = (uint16)(((A & ColorMask::kRedBlueMask & 0xFF00) * scale + (B & ColorMask::kRedBlueMask & 0xFF00) * (5 - scale)) / 5);
	uint16 g = (uint16)(((A & ColorMask::kGreenMask) * scale + (B & ColorMask::kGreenMask) * (5 - scale)) / 5);
	uint16 b = (uint16)(((A & ColorMask::kRedBlueMask & 0x00FF) * scale + (B & ColorMask::kRedBlueMask & 0x00FF) * (5 - scale)) / 5);

	return (uint16)((r & ColorMask::kRedBlueMask & 0xFF00) | (g & ColorMask::kGreenMask) | (b & ColorMask::kRedBlueMask & 0x00FF));
}


template<typename ColorMask, int scale>
static inline void interpolate5Line(uint16 *dst, const uint16 *srcA, const uint16 *srcB, int width) {
	// Accurate but slightly slower code
	while (width--) {
		*dst++ = interpolate5<ColorMask, scale>(*srcA++, *srcB++);
	}
}
#endif

#if ASPECT_MODE == kVeryFastAndGoodAspectMode

#ifdef USE_ARM_NEON_ASPECT_CORRECTOR

template<typename ColorMask>
static void interpolate5LineNeon(uint16 *dst, const uint16 *srcA, const uint16 *srcB, int width, int k1, int k2) {
	uint16x4_t kRedBlueMask_4 = vdup_n_u16(ColorMask::kRedBlueMask);
	uint16x4_t kGreenMask_4 = vdup_n_u16(ColorMask::kGreenMask);
	uint16x4_t k1_4 = vdup_n_u16(k1);
	uint16x4_t k2_4 = vdup_n_u16(k2);
	while (width >= 4) {
		uint16x4_t srcA_4 = vld1_u16(srcA);
		uint16x4_t srcB_4 = vld1_u16(srcB);
		uint16x4_t p1_4 = srcB_4;
		uint16x4_t p2_4 = srcA_4;

		uint16x4_t p1_rb_4 = vand_u16(p1_4, kRedBlueMask_4);
		uint16x4_t p1_g_4  = vand_u16(p1_4, kGreenMask_4);
		uint16x4_t p2_rb_4 = vand_u16(p2_4, kRedBlueMask_4);
		uint16x4_t p2_g_4  = vand_u16(p2_4, kGreenMask_4);

		uint32x4_t tmp_rb_4 = vshrq_n_u32(vmlal_u16(vmull_u16(p2_rb_4, k2_4), p1_rb_4, k1_4), 3);
		uint32x4_t tmp_g_4  = vshrq_n_u32(vmlal_u16(vmull_u16(p2_g_4, k2_4), p1_g_4, k1_4), 3);
		uint16x4_t p_rb_4 = vmovn_u32(tmp_rb_4);
		p_rb_4 = vand_u16(p_rb_4, kRedBlueMask_4);
		uint16x4_t p_g_4 = vmovn_u32(tmp_g_4);
		p_g_4 = vand_u16(p_g_4, kGreenMask_4);

		uint16x4_t result_4 = p_rb_4 | p_g_4;
		vst1_u16(dst, result_4);

		dst += 4;
		srcA += 4;
		srcB += 4;
		width -= 4;
	}
}
#endif // USE_ARM_NEON_ASPECT_CORRECTOR

template<typename ColorMask, int scale>
static void interpolate5Line(uint16 *dst, const uint16 *srcA, const uint16 *srcB, int width) {
	if (scale == 1) {
#ifdef USE_NEON_ASPECT_CORRECTOR
		int width4 = width & ~3;
		interpolate5LineNeon<ColorMask>(dst, srcA, srcB, width4, 7, 1);
		srcA += width4;
		srcB += width4;
		dst += width4;
		width -= width4;
#endif // USE_ARM_NEON_ASPECT_CORRECTOR
		while (width--) {
			*dst++ = interpolate16_7_1<ColorMask>(*srcB++, *srcA++);
		}
	} else {
#ifdef USE_ARM_NEON_ASPECT_CORRECTOR
		int width4 = width & ~3;
		interpolate5LineNeon<ColorMask>(dst, srcA, srcB, width4, 5, 3);
		srcA += width4;
		srcB += width4;
		dst += width4;
		width -= width4;
#endif // USE_ARM_NEON_ASPECT_CORRECTOR
		while (width--) {
			*dst++ = interpolate16_5_3<ColorMask>(*srcB++, *srcA++);
		}
	}
}
#endif

#if ASPECT_MODE == kFastAndVeryGoodAspectMode

template<typename ColorMask, int scale>
static inline void interpolate5Line(uint16 *dst, const uint16 *srcA, const uint16 *srcB, int width) {
	// For efficiency reasons we blit two pixels at a time, so it is important
	// that makeRectStretchable() guarantees that the width is even and that
	// the rect starts on a well-aligned address. (Even where unaligned memory
	// access is allowed there may be a speed penalty for it.)

	// These asserts are disabled for maximal speed; but I leave them in here
	// in case  other people want to test if the memory alignment (to an
	// address divisible by 4) is really working properly.
	//assert(((int)dst & 3) == 0);
	//assert(((int)srcA & 3) == 0);
	//assert(((int)srcB & 3) == 0);
	//assert((width & 1) == 0);

	width /= 2;
	const uint32 *sA = (const uint32 *)srcA;
	const uint32 *sB = (const uint32 *)srcB;
	uint32 *d = (uint32 *)dst;
	if (scale == 1) {
		while (width--) {
			*d++ = interpolate32_3_1<ColorMask>(*sB++, *sA++);
		}
	} else {
		while (width--) {
			*d++ = interpolate32_1_1<ColorMask>(*sB++, *sA++);
		}
	}
}
#endif

void makeRectStretchable(int &x, int &y, int &w, int &h, bool interpolate) {
#if ASPECT_MODE != kSuperFastAndUglyAspectMode
	if (!interpolate)
		return;
	int m = real2Aspect(y) % 6;

	// Ensure that the rect will start on a line that won't have its
	// colors changed by the stretching function.
	if (m != 0 && m != 5) {
		y -= m;
		h += m;
	}

  #if ASPECT_MODE == kVeryFastAndGoodAspectMode
	// Force x to be even, to ensure aligned memory access (this assumes
	// that each line starts at an even memory location, but that should
	// be the case on every target anyway).
	if (x & 1) {
		x--;
		w++;
	}

	// Finally force the width to be even, since we blit 2 pixels at a time.
	// While this means we may sometimes blit one column more than necessary,
	// this should actually be faster than having the check for the
	if (w & 1)
		w++;
  #endif
#endif
}

/**
 * Stretch a 16bpp image vertically by factor 1.2. Used to correct the
 * aspect-ratio in games using 320x200 pixel graphics with non-qudratic
 * pixels. Applying this method effectively turns that into 320x240, which
 * provides the correct aspect-ratio on modern displays.
 *
 * The image would normally have occupied y coordinates origSrcY through
 * origSrcY + height - 1.
 *
 * However, we have already placed it at srcY - the aspect-corrected y
 * coordinate - to allow in-place stretching.
 *
 * Therefore, the source image now occupies Y coordinates srcY through
 * srcY + height - 1, and it should be stretched to Y coordinates srcY
 * through real2Aspect(srcY + height - 1).
 */

int stretch200To240Nearest(uint8 *buf, uint32 pitch, int width, int height, int srcX, int srcY, int origSrcY, const Graphics::PixelFormat &format) {
	int maxDstY = real2Aspect(origSrcY + height - 1);
	int y;
	const uint8 *startSrcPtr = buf + srcX * format.bytesPerPixel + (srcY - origSrcY) * pitch;
	uint8 *dstPtr = buf + srcX * format.bytesPerPixel + maxDstY * pitch;

	for (y = maxDstY; y >= srcY; y--) {
		const uint8 *srcPtr = startSrcPtr + aspect2Real(y) * pitch;
		if (srcPtr == dstPtr)
			break;
		memcpy(dstPtr, srcPtr, format.bytesPerPixel * width);
		dstPtr -= pitch;
	}

	return 1 + maxDstY - srcY;
}

template<typename ColorMask>
int stretch200To240Interpolated(uint8 *buf, uint32 pitch, int width, int height, int srcX, int srcY, int origSrcY) {
	int maxDstY = real2Aspect(origSrcY + height - 1);
	int y;
	const uint8 *startSrcPtr = buf + srcX * 2 + (srcY - origSrcY) * pitch;
	uint8 *dstPtr = buf + srcX * 2 + maxDstY * pitch;

	for (y = maxDstY; y >= srcY; y--) {
		const uint8 *srcPtr = startSrcPtr + aspect2Real(y) * pitch;
		switch (y % 6) {
		case 0:
		case 5:
			if (srcPtr != dstPtr)
				memcpy(dstPtr, srcPtr, sizeof(uint16) * width);
			break;
		case 1:
			interpolate5Line<ColorMask, 1>((uint16 *)dstPtr, (const uint16 *)(srcPtr - pitch), (const uint16 *)srcPtr, width);
			break;
		case 2:
			interpolate5Line<ColorMask, 2>((uint16 *)dstPtr, (const uint16 *)(srcPtr - pitch), (const uint16 *)srcPtr, width);
			break;
		case 3:
			interpolate5Line<ColorMask, 2>((uint16 *)dstPtr, (const uint16 *)srcPtr, (const uint16 *)(srcPtr - pitch), width);
			break;
		case 4:
			interpolate5Line<ColorMask, 1>((uint16 *)dstPtr, (const uint16 *)srcPtr, (const uint16 *)(srcPtr - pitch), width);
			break;
		default:
			break;
		}
		dstPtr -= pitch;
	}

	return 1 + maxDstY - srcY;
}

int stretch200To240(uint8 *buf, uint32 pitch, int width, int height, int srcX, int srcY, int origSrcY, bool interpolate, const Graphics::PixelFormat &format) {
#if ASPECT_MODE != kSuperFastAndUglyAspectMode
	if (interpolate && format.bytesPerPixel == 2) {
		if (format.gLoss == 2)
			return stretch200To240Interpolated<Graphics::ColorMasks<565> >(buf, pitch, width, height, srcX, srcY, origSrcY);
		else if (format.gLoss == 3)
			return stretch200To240Interpolated<Graphics::ColorMasks<555> >(buf, pitch, width, height, srcX, srcY, origSrcY);
	}
#endif

	return stretch200To240Nearest(buf, pitch, width, height, srcX, srcY, origSrcY, format);
}
