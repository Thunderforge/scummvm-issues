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

#ifndef BLADERUNNER_ACTOR_DIALOGUE_QUEUE_H
#define BLADERUNNER_ACTOR_DIALOGUE_QUEUE_H

#include "common/array.h"

namespace BladeRunner {

class BladeRunnerEngine;
class SaveFileReadStream;
class SaveFileWriteStream;

class ActorDialogueQueue {
	static const uint kMaxEntries = 25;

	struct Entry {
		bool   isNotPause;
		bool   isPause;
		int    actorId;
		int    sentenceId;
		int    animationMode;
		int32  delayMillis; // in milliseconds, TODO: Info on special values 0 and -1?

		Entry();
	};

	BladeRunnerEngine *_vm;

	Common::Array<Entry> _entries;
	bool                 _isNotPause;
	int                  _actorId;
	int                  _sentenceId;
	int                  _animationMode;
	int                  _animationModePrevious;
	bool                 _isPause;
	int32                _delayMillis; // in milliseconds, TODO: Info on special values 0 and -1?
	uint32               _timeLast;    // in milliseconds

public:
	ActorDialogueQueue(BladeRunnerEngine *vm);
	~ActorDialogueQueue();

	void add(int actorId, int sentenceId, int animationMode);
	void addPause(int32 delayMillis);
	void flush(int a1, bool callScript);
	bool isEmpty();
	void tick();

	void save(SaveFileWriteStream &f);
	void load(SaveFileReadStream &f);

private:
	void clear();
};

} // End of namespace BladeRunner

#endif
