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

#ifndef GRAPHICS_SCALER_INTERN_H
#define GRAPHICS_SCALER_INTERN_H

#include "common/scummsys.h"
#include "graphics/colormasks.h"


/**
 * Interpolate two 16 bit pixel *pairs* at once with equal weights 1.
 * In particular, p1 and p2 can contain two pixels each in the upper
 * and lower halves.
 *
 * This also works for 32 bit pixels.
 */
template<typename ColorMask>
static inline uint32 interpolate32_1_1(uint32 p1, uint32 p2) {
	// Clear the low bit of each channel,
	// divide each channel by 2,
	// add the two pixels together,
	// add 1 to each channel if the lowbits would have added to 2
	return (((p1 & ColorMask::kHighBitsMask) >> 1) +
	        ((p2 & ColorMask::kHighBitsMask) >> 1) +
	         (p1 & p2 & ColorMask::kLowBitsMask));
}

/**
 * Interpolate two 16 bit pixel *pairs* at once with weights 3 resp. 1.
 * In particular, p1 and p2 can contain two pixels/each in the upper
 * and lower halves.
 *
 * This also works for 32 bit pixels.
 */
template<typename ColorMask>
static inline uint32 interpolate32_3_1(uint32 p1, uint32 p2) {
	// Clear the 2 lowest bits of each channel,
	// divide each channel by 4, multiply p1 by 3
	// add the two pixels together,
	uint32 x = ((p1 & ColorMask::qhighBits) >> 2) * 3 + ((p2 & ColorMask::qhighBits) >> 2);
	// Get 2 lowest bits of each channel,
	// multiply p1 by 3, add them together, then divide by 4
	uint32 y = ((p1 & ColorMask::qlowBits) * 3 + (p2 & ColorMask::qlowBits)) >> 2;

	// Use only the low bits of the second result to add to the first result
	y &= ColorMask::qlowBits;
	return x + y;
}

/**
 * Interpolate two 32 bit pixels with weights 2 and 1 and 1, i.e., (2*p1+p2)/3.
 */
template<typename ColorMask>
uint32 interpolate32_2_1(uint32 pixel1, uint32 pixel2) {
	uint32 rsum, gsum, bsum, asum;

	rsum =  ((pixel1 & ColorMask::kRedMask) >> ColorMask::kRedShift) << 1;
	rsum += ((pixel2 & ColorMask::kRedMask) >> ColorMask::kRedShift);
	rsum /= 3;
	rsum <<= ColorMask::kRedShift;

	gsum =  ((pixel1 & ColorMask::kGreenMask) >> ColorMask::kGreenShift) << 1;
	gsum += ((pixel2 & ColorMask::kGreenMask) >> ColorMask::kGreenShift);
	gsum /= 3;
	gsum <<= ColorMask::kGreenShift;

	bsum =  ((pixel1 & ColorMask::kBlueMask) >> ColorMask::kBlueShift) << 1;
	bsum += ((pixel2 & ColorMask::kBlueMask) >> ColorMask::kBlueShift);
	bsum /= 3;
	bsum <<= ColorMask::kBlueShift;

	asum =  ((pixel1 & ColorMask::kAlphaMask) >> ColorMask::kAlphaShift) << 1;
	asum += ((pixel2 & ColorMask::kAlphaMask) >> ColorMask::kAlphaShift);
	asum /= 3;
	asum <<= ColorMask::kAlphaShift;

	return (rsum & ColorMask::kRedMask) | (gsum & ColorMask::kGreenMask) | (bsum & ColorMask::kBlueMask) | (asum & ColorMask::kAlphaMask);
}

/**
 * Interpolate two 32 bit pixels with weights 5 and 3 and 1, i.e., (5*p1+3*p2)/8.
 * @see interpolate_32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_5_3(uint32 p1, uint32 p2) {
	uint32 x = ((p1 & ~ColorMask::kLow3Bits) >> 3) * 5 + ((p2 & ~ColorMask::kLow3Bits) >> 3) * 3;
	uint32 y = ((p1 & ColorMask::kLow3Bits) * 5 + (p2 & ColorMask::kLow3Bits) * 3) >> 3;

	y &= ColorMask::kLow3Bits;
	return x + y;
}

/**
 * Interpolate two 32 bit pixels with weights 7 and 1, i.e., (7*p1+p2)/8.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_7_1(uint32 p1, uint32 p2) {
	uint32 x = ((p1 & ~ColorMask::kLow3Bits) >> 3) * 7 + ((p2 & ~ColorMask::kLow3Bits) >> 3);
	uint32 y = ((p1 & ColorMask::kLow3Bits) * 7 + (p2 & ColorMask::kLow3Bits)) >> 3;

	y &= ColorMask::kLow3Bits;
	return x + y;
}

/**
 * Interpolate three 32 bit pixels with weights 2, 1, and 1, i.e., (2*p1+p2+p3)/4.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_2_1_1(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ColorMask::qhighBits) >> 1)
		              + ((p2 & ColorMask::qhighBits) >> 2)
		              + ((p3 & ColorMask::qhighBits) >> 2);
	uint32 y = ((p1 & ColorMask::qlowBits) <<  1)
			          +  (p2 & ColorMask::qlowBits)
			          +  (p2 & ColorMask::qlowBits);
	y >>= 2;
	y &= ColorMask::qlowBits;
	return x + y;
}

/**
 * Interpolate three 32 bit pixels with weights 5, 2, and 1, i.e., (5*p1+2*p2+p3)/8.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_5_2_1(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ~ColorMask::kLow3Bits) >> 3) * 5
		              + ((p2 & ~ColorMask::kLow3Bits) >> 3) * 2
		              + ((p3 & ~ColorMask::kLow3Bits) >> 3);
	uint32 y = (p1 & ColorMask::kLow3Bits) * 5
			          + (p2 & ColorMask::kLow3Bits) * 2
			          + (p2 & ColorMask::kLow3Bits);
	y >>= 3;
	y &= ColorMask::kLow3Bits;
	return x + y;
}

/**
 * Interpolate three 32 bit pixels with weights 6, 1, and 1, i.e., (6*p1+p2+p3)/8.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_6_1_1(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ~ColorMask::kLow3Bits) >> 3) * 6
		              + ((p2 & ~ColorMask::kLow3Bits) >> 3)
		              + ((p3 & ~ColorMask::kLow3Bits) >> 3);
	uint32 y = (p1 & ColorMask::kLow3Bits) * 6
			          + (p2 & ColorMask::kLow3Bits)
			          + (p2 & ColorMask::kLow3Bits);
	y >>= 3;
	y &= ColorMask::kLow3Bits;
	return x + y;
}

/**
 * Interpolate three 32 bit pixels with weights 2, 3, and 3, i.e., (2*p1+3*(p2+p3))/8.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_2_3_3(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ~ColorMask::kLow3Bits) >> 2)
		              + (((p2 & ~ColorMask::kLow3Bits) >> 3)
		              + ((p3 & ~ColorMask::kLow3Bits) >> 3)) * 3;
	uint32 y = (p1 & ColorMask::kLow3Bits) * 2
			          + ((p2 & ColorMask::kLow3Bits)
			          + (p2 & ColorMask::kLow3Bits)) * 3;
	y >>= 3;
	y &= ColorMask::kLow3Bits;
	return x + y;
}

/**
 * Interpolate three 32 bit pixels with weights 2, 7, and 7, i.e., (2*p1+7*(p2+p3))/16.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
inline uint32 interpolate32_2_7_7(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ~ColorMask::kLow4Bits) >> 3)
		              + (((p2 & ~ColorMask::kLow4Bits) >> 4)
		              +  ((p3 & ~ColorMask::kLow4Bits) >> 4)) * 7;
	uint32 y = (p1 & ColorMask::kLow4Bits) * 2
			          + ((p2 & ColorMask::kLow4Bits)
			          + (p2 & ColorMask::kLow4Bits)) * 7;
	y >>= 4;
	y &= ColorMask::kLow4Bits;
	return x + y;
}

// Dummy specializations.
template<>
inline uint32 interpolate32_2_7_7<Graphics::ColorMasks<555> >(uint32 p1, uint32 p2, uint32 p3) {
	assert(0);
	return 0;
}

template<>
inline uint32 interpolate32_2_7_7<Graphics::ColorMasks<565> >(uint32 p1, uint32 p2, uint32 p3) {
	assert(0);
	return 0;
}

/**
 * Interpolate three 32 bit pixels with weights 14, 1, and 1, i.e., (14*p1+p2+p3)/16.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
inline uint32 interpolate32_14_1_1(uint32 p1, uint32 p2, uint32 p3) {
	uint32 x = ((p1 & ~ColorMask::kLow4Bits) >> 4) * 14
		              + ((p2 & ~ColorMask::kLow4Bits) >> 4)
		              + ((p3 & ~ColorMask::kLow4Bits) >> 4);
	uint32 y = (p1 & ColorMask::kLow4Bits) * 14
			          + (p2 & ColorMask::kLow4Bits)
			          + (p2 & ColorMask::kLow4Bits);
	y >>= 4;
	y &= ColorMask::kLow4Bits;
	return x + y;
}


// Dummy specializations.
template<>
inline uint32 interpolate32_14_1_1<Graphics::ColorMasks<555> >(uint32 p1, uint32 p2, uint32 p3) {
	assert(0);
	return 0;
}

template<>
inline uint32 interpolate32_14_1_1<Graphics::ColorMasks<565> >(uint32 p1, uint32 p2, uint32 p3) {
	assert(0);
	return 0;
}

/**
 * Interpolate three 32 bit pixels with weights 1, 1, and 1, i.e., (p1+p2+p3)/3.
 */

template<typename ColorMask>
uint32 interpolate32_1_1_1(uint32 pixel1, uint32 pixel2, uint32 pixel3) {
	uint32 rsum, gsum, bsum;

	rsum =  ((pixel1 & ColorMask::kRedMask) >> ColorMask::kRedShift);
	rsum += ((pixel2 & ColorMask::kRedMask) >> ColorMask::kRedShift);
	rsum += ((pixel3 & ColorMask::kRedMask) >> ColorMask::kRedShift);
	rsum /= 3;
	rsum <<= ColorMask::kRedShift;

	gsum =  ((pixel1 & ColorMask::kGreenMask) >> ColorMask::kGreenShift);
	gsum += ((pixel2 & ColorMask::kGreenMask) >> ColorMask::kGreenShift);
	gsum += ((pixel3 & ColorMask::kGreenMask) >> ColorMask::kGreenShift);
	gsum /= 3;
	gsum <<= ColorMask::kGreenShift;

	bsum =  ((pixel1 & ColorMask::kBlueMask) >> ColorMask::kBlueShift);
	bsum += ((pixel2 & ColorMask::kBlueMask) >> ColorMask::kBlueShift);
	bsum += ((pixel3 & ColorMask::kBlueMask) >> ColorMask::kBlueShift);
	bsum /= 3;
	bsum <<= ColorMask::kBlueShift;

	return (rsum & ColorMask::kRedMask) | (gsum & ColorMask::kGreenMask) | (bsum & ColorMask::kBlueMask);
}

/**
 * Interpolate four 32 bit pixels with weights 1, 1, 1, and 1, i.e., (p1+p2+p3+p4)/4.
 *
 * @see interpolate32_3_1 for similar method
 */
template<typename ColorMask>
static inline uint32 interpolate32_1_1_1_1(uint32 p1, uint32 p2, uint32 p3, uint32 p4) {
	uint32 x = ((p1 & ~ColorMask::kLow2Bits) >> 2)
		              + ((p2 & ~ColorMask::kLow2Bits) >> 2)
		              + ((p3 & ~ColorMask::kLow2Bits) >> 2)
		              + ((p4 & ~ColorMask::kLow2Bits) >> 2);
	uint32 y = (p1 & ColorMask::kLow2Bits)
			          + (p2 & ColorMask::kLow2Bits)
			          + (p3 & ColorMask::kLow2Bits)
			          + (p4 & ColorMask::kLow2Bits);
	y >>= 2;
	y &= ColorMask::kLow2Bits;
	return x + y;
}


/**
 * Interpolate two 16 bit pixels with weights 1 and 1, i.e., (p1+p2)/2.
 * See <http://www.slack.net/~ant/info/rgb_mixing.html> for details on how this works.
 */
template<typename ColorMask>
static inline unsigned interpolate16_1_1(unsigned p1, unsigned p2) {
	const unsigned lowbits = (p1 ^ p2) & ColorMask::kLowBits;
	return ((p1 + p2) - lowbits) >> 1;
}

/**
 * Interpolate two 16 bit pixels with weights 3 and 1, i.e., (3*p1+p2)/4.
 */
template<typename ColorMask>
static inline unsigned interpolate16_3_1(unsigned p1, unsigned p2) {
	const unsigned lowbits = (((p1 & ColorMask::kLowBits) << 1) + (p1 & ColorMask::kLow2Bits)
		                   + (p2 & ColorMask::kLow2Bits)) & ColorMask::kLow2Bits;
	return ((p1*3 + p2) - lowbits) >> 2;
}

/**
 * Interpolate two 16 bit pixels with weights 2 and 1, i.e., (2*p1+p2)/3.
 */
template<typename ColorMask>
uint16 interpolate16_2_1(uint16 pixel1, uint16 pixel2) {
	uint32 rsum;
	uint16 gsum, bsum;

	rsum =  (pixel1 & ColorMask::kRedMask) << 1;
	rsum += (pixel2 & ColorMask::kRedMask);
	rsum /= 3;

	gsum =  (pixel1 & ColorMask::kGreenMask) << 1;
	gsum += (pixel2 & ColorMask::kGreenMask);
	gsum /= 3;

	bsum =  (pixel1 & ColorMask::kBlueMask) << 1;
	bsum += (pixel2 & ColorMask::kBlueMask);
	bsum /= 3;

	return (rsum & ColorMask::kRedMask) | (gsum & ColorMask::kGreenMask) | (bsum & ColorMask::kBlueMask);
}

/**
 * Interpolate two 16 bit pixels with weights 5 and 3 and 1, i.e., (5*p1+3*p2)/8.
 */
template<typename ColorMask>
static inline unsigned interpolate16_5_3(unsigned p1, unsigned p2) {
	const unsigned lowbits = (((p1 & ColorMask::kLowBits) << 2) + (p1 & ColorMask::kLow3Bits)
		                   + ((p2 & ColorMask::kLow2Bits) << 1) + (p2 & ColorMask::kLow3Bits)) & ColorMask::kLow3Bits;
	return ((p1*5 + p2*3) - lowbits) >> 3;
}

/**
 * Interpolate two 16 bit pixels with weights 7 and 1, i.e., (7*p1+p2)/8.
 */
template<typename ColorMask>
static inline unsigned interpolate16_7_1(unsigned p1, unsigned p2) {
	const unsigned lowbits = (((p1 & ColorMask::kLowBits) << 2) + ((p1 & ColorMask::kLow2Bits) << 1) + (p1 & ColorMask::kLow3Bits)
		                   +  (p2 & ColorMask::kLow3Bits)) & ColorMask::kLow3Bits;
	return ((p1*7+p2) - lowbits) >> 3;
}

/**
 * Interpolate three 16 bit pixels with weights 2, 1, and 1, i.e., (2*p1+p2+p3)/4.
 */
template<typename ColorMask>
static inline unsigned interpolate16_2_1_1(unsigned p1, unsigned p2, unsigned p3) {
	p1<<=1;
	const unsigned lowbits = ((p1 & (ColorMask::kLowBits << 1))
		                   +  (p2 & ColorMask::kLow2Bits)
		                   +  (p3 & ColorMask::kLow2Bits)) & ColorMask::kLow2Bits;
	return ((p1+p2+p3) - lowbits) >> 2;
}

/**
 * Interpolate three 16 bit pixels with weights 5, 2, and 1, i.e., (5*p1+2*p2+p3)/8.
 */
template<typename ColorMask>
static inline unsigned interpolate16_5_2_1(unsigned p1, unsigned p2, unsigned p3) {
	p2<<=1;
	const unsigned lowbits = (((p1 & ColorMask::kLowBits) << 2) + (p1 & ColorMask::kLow3Bits)
		                   +  (p2 & (ColorMask::kLow2Bits << 1))
		                   +  (p3 & ColorMask::kLow3Bits)) & ColorMask::kLow3Bits;
	return ((p1*5 + p2 + p3) - lowbits) >> 3;
}

/**
 * Interpolate three 16 bit pixels with weights 6, 1, and 1, i.e., (6*p1+p2+p3)/8.
 */
template<typename ColorMask>
static inline unsigned interpolate16_6_1_1(unsigned p1, unsigned p2, unsigned p3) {
	const unsigned lowbits = (((((p1 & ColorMask::kLowBits) << 1) + (p1 & ColorMask::kLow2Bits)) << 1)
		                   + (p2 & ColorMask::kLow3Bits)
		                   + (p3 & ColorMask::kLow3Bits)) & ColorMask::kLow3Bits;
	return ((p1*6 + p2 + p3) - lowbits) >> 3;
}

/**
 * Interpolate three 16 bit pixels with weights 2, 3, and 3, i.e., (2*p1+3*(p2+p3))/8.
 */
template<typename ColorMask>
static inline unsigned interpolate16_2_3_3(unsigned p1, unsigned p2, unsigned p3) {
	p1 <<= 1;
	const unsigned rb = (p1 & (ColorMask::kRedBlueMask<<1))
		              + ((p2 & ColorMask::kRedBlueMask) + (p3 & ColorMask::kRedBlueMask))*3;
	const unsigned  g = (p1 & (ColorMask::kGreenMask<<1))
		              + ((p2 & ColorMask::kGreenMask) + (p3 & ColorMask::kGreenMask))*3;
	return ((rb & (ColorMask::kRedBlueMask<<3)) | (g & (ColorMask::kGreenMask<<3))) >> 3;
}

/**
 * Interpolate three 16 bit pixels with weights 2, 7, and 7, i.e., (2*p1+7*(p2+p3))/16.
 */
template<typename ColorMask>
static inline unsigned interpolate16_2_7_7(unsigned p1, unsigned p2, unsigned p3) {
	p1 <<= 1;
	const unsigned rb = (p1 & (ColorMask::kRedBlueMask<<1))
		              + ((p2 & ColorMask::kRedBlueMask) + (p3 & ColorMask::kRedBlueMask))*7;
	const unsigned  g = (p1 & (ColorMask::kGreenMask<<1))
		              + ((p2 & ColorMask::kGreenMask) + (p3 & ColorMask::kGreenMask))*7;
	return ((rb & (ColorMask::kRedBlueMask<<4)) | (g & (ColorMask::kGreenMask<<4))) >> 4;
}

/**
 * Interpolate three 16 bit pixels with weights 14, 1, and 1, i.e., (14*p1+p2+p3)/16.
 */
template<typename ColorMask>
static inline unsigned interpolate16_14_1_1(unsigned p1, unsigned p2, unsigned p3) {
	const unsigned rb = (p1&ColorMask::kRedBlueMask)*14
	                  + (p2&ColorMask::kRedBlueMask)
	                  + (p3&ColorMask::kRedBlueMask);
	const unsigned  g = (p1&ColorMask::kGreenMask)*14
	                  + (p2&ColorMask::kGreenMask) + (p3&ColorMask::kGreenMask);
	return ((rb&(ColorMask::kRedBlueMask<<4)) | (g&(ColorMask::kGreenMask<<4))) >> 4;
}

/**
 * Interpolate three 16 bit pixels with weights 1, 1, and 1, i.e., (p1+p2+p3)/3.
 */
template<typename ColorMask>
uint16 interpolate16_1_1_1(uint16 pixel1, uint16 pixel2, uint16 pixel3)
{
	uint32 rsum;
	uint16 gsum, bsum;

	rsum =  (pixel1 & ColorMask::kRedMask);
	rsum += (pixel2 & ColorMask::kRedMask);
	rsum += (pixel3 & ColorMask::kRedMask);
	rsum /= 3;

	gsum =  (pixel1 & ColorMask::kGreenMask);
	gsum += (pixel2 & ColorMask::kGreenMask);
	gsum += (pixel3 & ColorMask::kGreenMask);
	gsum /= 3;

	bsum =  (pixel1 & ColorMask::kBlueMask);
	bsum += (pixel2 & ColorMask::kBlueMask);
	bsum += (pixel3 & ColorMask::kBlueMask);
	bsum /= 3;

	return (rsum & ColorMask::kRedMask) | (gsum & ColorMask::kGreenMask) | (bsum & ColorMask::kBlueMask);
}

/**
 * Interpolate four 16 bit pixels with weights 1, 1, 1, and 1, i.e., (p1+p2+p3+p4)/4.
 */
template<typename ColorMask>
static inline unsigned interpolate16_1_1_1_1(unsigned p1, unsigned p2, unsigned p3, unsigned p4) {
	const unsigned lowbits = ((p1 & ColorMask::kLow2Bits)
		                   +  (p2 & ColorMask::kLow2Bits)
		                   +  (p3 & ColorMask::kLow2Bits)
		                   +  (p4 & ColorMask::kLow2Bits)) & ColorMask::kLow2Bits;
	return ((p1+p2+p3+p4) - lowbits) >> 2;
}

/**
 * Compare two YUV values (encoded 8-8-8) and check if they differ by more than
 * a certain hard coded threshold. Used by the hq scaler family.
 */
static inline bool diffYUV(int yuv1, int yuv2) {
	static const int Ymask = 0x00FF0000;
	static const int Umask = 0x0000FF00;
	static const int Vmask = 0x000000FF;
	static const int trY   = 0x00300000;
	static const int trU   = 0x00000700;
	static const int trV   = 0x00000006;

	int diff;
	int mask;

	diff = ((yuv1 & Umask) - (yuv2 & Umask));
	mask = diff >> 31;           // -1 if value < 0, 0 otherwise
	diff = (diff ^ mask) - mask; // -1: ~value + 1; 0: value
	if (diff > trU) return true;

	diff = ((yuv1 & Vmask) - (yuv2 & Vmask));
	mask = diff >> 31;           // -1 if value < 0, 0 otherwise
	diff = (diff ^ mask) - mask; // -1: ~value + 1; 0: value
	if (diff > trV) return true;

	diff = ((yuv1 & Ymask) - (yuv2 & Ymask));
	mask = diff >> 31;           // -1 if value < 0, 0 otherwise
	diff = (diff ^ mask) - mask; // -1: ~value + 1; 0: value
	if (diff > trY) return true;

	return false;
/*
	return
	  ( ( ABS((yuv1 & Ymask) - (yuv2 & Ymask)) > trY ) ||
	    ( ABS((yuv1 & Umask) - (yuv2 & Umask)) > trU ) ||
	    ( ABS((yuv1 & Vmask) - (yuv2 & Vmask)) > trV ) );
*/
}

#endif
