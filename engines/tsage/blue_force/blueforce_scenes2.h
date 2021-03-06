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

#ifndef TSAGE_BLUEFORCE_SCENES2_H
#define TSAGE_BLUEFORCE_SCENES2_H

#include "common/scummsys.h"
#include "tsage/blue_force/blueforce_logic.h"
#include "tsage/blue_force/blueforce_speakers.h"
#include "tsage/events.h"
#include "tsage/core.h"
#include "tsage/scenes.h"
#include "tsage/globals.h"
#include "tsage/sound.h"

namespace TsAGE {

namespace BlueForce {

using namespace TsAGE;

class IntroObject: public NamedObject {
};

class Scene200: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	Action1 _action1;
	Action2 _action2;
	NamedObject _object1, _object2, _object3, _object4, _object5, _object6;
	IntroObject  _object7, _object8, _object9;
	NamedObject _object10, _object11;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

class Scene210: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	Action1 _action1;
	IntroObject _object1, _object2, _object3, _object4;
	IntroObject _object5, _object6, _object7, _object8;
	NamedObject _object9, _object10, _object11, _object12;
	NamedObject _object13, _object14, _object15;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

class Scene220: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	Action1 _action1;
	Action2 _action2;
	NamedObject _object1, _object2, _object3, _object4, _object5;
	NamedObject _object6, _object7, _object8, _object9;
	IntroObject _object10, _object11, _object12, _object13;
	IntroObject _object14, _object15, _object16;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

class Scene225: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
	};
	class Action3: public Action {
	public:
		void signal() override;
	};
	class Action4: public Action {
	public:
		void signal() override;
	};
	class Action5: public Action {
	public:
		void signal() override;
	};
	class Action6: public Action {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	Action4 _action4;
	Action5 _action5;
	Action6 _action6;
	IntroObject _object1, _object2, _object3, _object4;
	IntroObject _object5, _object6, _object7;
	NamedObject _object8, _object9, _object10, _object11, _object12;
	NamedObject _object13, _object14, _object15, _object16;
	NamedObject _object17, _object18, _object19;
	NamedObject _object20, _object21;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

class Scene265: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
public:
	Action1 _action1;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

class Scene270: public SceneExt {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};

	/* Objects */
	class Lyle: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Grandma: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Items */
	class Item: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Exit: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
public:
	SequenceManager _sequenceManager1, _sequenceManager2, _sequenceManager3;
	SpeakerGrandma _grandmaSpeaker;
	SpeakerLyle _lyleSpeaker;
	SpeakerJake _jakeSpeaker;
	SpeakerLaura _lauraSpeaker;
	SpeakerSkip _skipSpeaker;
	SpeakerGameText _gameTextSpeaker;
	Action1 _action1;
	NamedObject _object1, _object2, _object3, _laura;
	NamedObject _skip, _tv, _fireplace;
	Lyle _lyle;
	Grandma _grandma;
	Item _couch, _afgan;
	NamedHotspot _appliances;
	NamedHotspot _ivy, _fridge, _photos, _item8, _item9;
	NamedHotspot _item10, _item11, _background;
	Exit _exit;
	int _field380, _field382, _field384, _field386;
	int _field219A, _field21A0;
	Common::Point _tempPos;

	Scene270();
	void synchronize(Serializer &s) override;
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
};

class Scene271: public PalettedScene {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};

	/* Objects */
	class Object12: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Items */
	class Item: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Exit: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
public:
	SequenceManager _sequenceManager1, _sequenceManager2, _sequenceManager3;
	SpeakerGrandma _grandmaSpeaker;
	SpeakerLyle _lyleSpeaker;
	SpeakerJake _jakeSpeaker;
	SpeakerLaura _lauraSpeaker;
	SpeakerSkip _skipSpeaker;
	SpeakerGameText _gameTextSpeaker;
	SpeakerGranText _granTextSpeaker;
	SpeakerLyleText _lyleTextSpeaker;

	NamedObject _object1, _object2, _object3, _object4, _object5;
	NamedObject _object6, _object7, _object8, _tv, _object10;
	NamedObject _object11;
	Object12 _object12;
	Item _item1, _item3;
	NamedHotspot _item2, _item4, _item5, _item6, _item7;
	NamedHotspot _item8, _item9, _item10, _item11;
	Exit _exit;
	Action1 _action1;
	Rect _rect1;
	int _field796, _field2E16;
	Common::Point _tempPos;

	Scene271();
	void synchronize(Serializer &s) override;
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
};

class Scene280: public PalettedScene {
	/* Actions */
	class Action1: public ActionExt {
	public:
		void signal() override;
	};
public:
	Action1 _action1;
	SpeakerGameText _gameTextSpeaker;
	NamedObject _jake, _dad, _mum, _object4;

	void postInit(SceneObjectList *OwnerList) override;
	void signal() override;
};

} // End of namespace BlueForce

} // End of namespace TsAGE

#endif
