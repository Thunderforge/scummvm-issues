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
 * This code is based on original Hugo Trilogy source code
 *
 * Copyright (c) 1989-1995 David P. Gray
 *
 */

#ifndef INTRO_H
#define INTRO_H
#include "graphics/surface.h"
#include "graphics/fonts/winfont.h"

namespace Hugo {

enum seqTextIntro {
	kIntro1 = 0,
	kIntro2 = 1,
	kIntro3 = 2
};

class IntroHandler {
public:
	IntroHandler(HugoEngine *vm);
	Graphics::Surface _surf;
	Graphics::WinFont _font;

	virtual ~IntroHandler();

	virtual void preNewGame() = 0;
	virtual void introInit() = 0;
	virtual bool introPlay() = 0;

	void freeIntroData();
	void loadIntroData(Common::SeekableReadStream &in);

	byte getIntroSize() const;

protected:
	HugoEngine *_vm;

	byte *_introX;
	byte *_introY;
	byte  _introXSize;
	int16 _introTicks;                              // Count calls to introPlay()
};

class intro_v1w : public IntroHandler {
public:
	intro_v1w(HugoEngine *vm);
	~intro_v1w() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
};

class intro_v1d : public IntroHandler {
public:
	intro_v1d(HugoEngine *vm);
	~intro_v1d() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
private:
	int _introState;
};

class intro_v2w : public IntroHandler {
public:
	intro_v2w(HugoEngine *vm);
	~intro_v2w() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
};

class intro_v2d : public IntroHandler {
public:
	intro_v2d(HugoEngine *vm);
	~intro_v2d() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
};

class intro_v3w : public IntroHandler {
public:
	intro_v3w(HugoEngine *vm);
	~intro_v3w() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
};

class intro_v3d : public IntroHandler {
public:
	intro_v3d(HugoEngine *vm);
	~intro_v3d() override;

	void preNewGame() override;
	void introInit() override;
	bool introPlay() override;
};

} // End of namespace Hugo

#endif
