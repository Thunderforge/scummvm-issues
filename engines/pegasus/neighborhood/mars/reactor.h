/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1995-1997 Presto Studios, Inc.
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

#ifndef PEGASUS_NEIGHBORHOOD_MARS_REACTOR_H
#define PEGASUS_NEIGHBORHOOD_MARS_REACTOR_H

#include "pegasus/elements.h"
#include "pegasus/surface.h"
#include "pegasus/util.h"

namespace Pegasus {

class ReactorGuess : public DisplayElement {
public:
	ReactorGuess(const DisplayElementID);
	~ReactorGuess() override {}

	void initReactorGuess();
	void disposeReactorGuess();

	void setGuess(int32, int32, int32);

	void draw(const Common::Rect &) override;

protected:
	int32 _currentGuess[3];

	Surface _colors;
};

class ReactorChoiceHighlight : public DisplayElement {
public:
	ReactorChoiceHighlight(const DisplayElementID);
	~ReactorChoiceHighlight() override {}

	void initReactorChoiceHighlight();
	void disposeReactorChoiceHighlight();

	void resetHighlight() {
		_choices.clearAllFlags();
		triggerRedraw();
	}

	bool choiceHighlighted(uint32 whichChoice) { return _choices.getFlag(whichChoice); }

	void draw(const Common::Rect &) override;

	void highlightChoice(uint32 whichChoice) {
		_choices.setFlag(whichChoice);
		triggerRedraw();
	}

protected:
	Surface _colors;
	FlagsArray<byte, 5> _choices;
};

class ReactorHistory : public DisplayElement {
public:
	ReactorHistory(const DisplayElementID);
	~ReactorHistory() override {}

	void initReactorHistory();
	void disposeReactorHistory();

	void draw(const Common::Rect &) override;

	void addGuess(int32, int32, int32);
	int32 getNumGuesses() { return _numGuesses; }
	void clearHistory();
	void setAnswer(int32, int32, int32);
	void showAnswer();
	bool isSolved();
	int32 getCurrentNumCorrect();

protected:
	Surface _colors, _digits, _answerColors;
	int32 _answer[3];
	int32 _history[5][3];
	int32 _numGuesses;
	bool _showAnswer;
};

} // End of namespace Pegasus

#endif
