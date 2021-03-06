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

// Disable symbol overrides so that we can use system headers.
#define FORBIDDEN_SYMBOL_ALLOW_ALL

#include "util.h"
#include <stdarg.h>

#ifdef _MSC_VER
#define vsnprintf _vsnprintf
#endif

void error(const char *s, ...) {
	char buf[1024];
	va_list va;

	va_start(va, s);
	vsnprintf(buf, 1024, s, va);
	va_end(va);

	fprintf(stderr, "ERROR: %s!\n", buf);

	exit(1);
}

void warning(const char *s, ...) {
	char buf[1024];
	va_list va;

	va_start(va, s);
	vsnprintf(buf, 1024, s, va);
	va_end(va);

	fprintf(stderr, "WARNING: %s!\n", buf);
}

int scumm_stricmp(const char *s1, const char *s2) {
	byte l1, l2;
	do {
		// Don't use ++ inside tolower, in case the macro uses its
		// arguments more than once.
		l1 = (byte) * s1++;
		l1 = tolower(l1);
		l2 = (byte) * s2++;
		l2 = tolower(l2);
	} while (l1 == l2 && l1 != 0);
	return l1 - l2;
}

void debug(int level, const char *s, ...) {
	char buf[1024];
	va_list va;

	va_start(va, s);
	vsnprintf(buf, 1024, s, va);
	va_end(va);

	fprintf(stderr, "DEBUG: %s!\n", buf);
}

size_t writeByte(FILE *fp, uint8 b) {
	fwrite(&b, 1, 1, fp);
	return sizeof(b);
}

size_t writeUint16BE(FILE *fp, uint16 value) {
	writeByte(fp, (uint8)(value >> 8));
	writeByte(fp, (uint8)(value));
	return sizeof(value);
}

size_t writeUint16LE(FILE *fp, uint16 value) {
	writeByte(fp, (uint8)(value));
	writeByte(fp, (uint8)(value >> 8));
	return sizeof(value);
}

size_t writeUint32BE(FILE *fp, uint32 value) {
	writeByte(fp, (uint8)(value >> 24));
	writeByte(fp, (uint8)(value >> 16));
	writeByte(fp, (uint8)(value >> 8));
	writeByte(fp, (uint8)(value));
	return sizeof(value);
}

size_t writeUint32LE(FILE *fp, uint32 value) {
	writeByte(fp, (uint8)(value));
	writeByte(fp, (uint8)(value >> 8));
	writeByte(fp, (uint8)(value >> 16));
	writeByte(fp, (uint8)(value >> 24));
	return sizeof(value);
}

size_t writeString16(FILE *fp, const char *string) {
	if (string == nullptr) {
		// Like an empty string
		return writeUint16LE(fp, 0);
	}
	size_t n = strlen(string);
	if (n > 0xffff) {
		return 0;
	}
	size_t written = 0;
	written += writeUint16LE(fp, n);
	fwrite(string, n, 1, fp);
	written += n;
	return written;
}

size_t writeString16Array16(FILE *fp, char const *const *array, uint16 elems) {
	return writeArray<char const *, writeString16, uint16, writeUint16LE>(fp, array, elems);
}

//#define DEBUG
static const char padBuf[PADDING_ALIGNMENT] = {
#ifndef DEBUG
	0
#else
	0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C,
#endif
};

size_t writePadding(FILE *fp) {
	long pos = ftell(fp);

	pos = pos & PADDING_MASK; // Keep only remainder
	if (pos == 0) {
		return 0;
	}

	pos = PADDING_ALIGNMENT - pos;
	fwrite(padBuf, pos, 1, fp);
	return pos;
}

uint32 fileSize(FILE *fp) {
	uint32 sz;
	uint32 pos = ftell(fp);
	fseek(fp, 0, SEEK_END);
	sz = ftell(fp);
	fseek(fp, pos, SEEK_SET);
	return sz;
}
