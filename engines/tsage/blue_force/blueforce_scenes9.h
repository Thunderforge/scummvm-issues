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

#ifndef TSAGE_BLUEFORCE_SCENES9_H
#define TSAGE_BLUEFORCE_SCENES9_H

#include "common/scummsys.h"
#include "tsage/blue_force/blueforce_logic.h"
#include "tsage/blue_force/blueforce_speakers.h"
#include "tsage/converse.h"
#include "tsage/events.h"
#include "tsage/core.h"
#include "tsage/scenes.h"
#include "tsage/globals.h"
#include "tsage/sound.h"

namespace TsAGE {

namespace BlueForce {

using namespace TsAGE;

class Scene900: public PalettedScene {
	/* Items */
	class Exterior: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class WestExit: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	/* Objects */
	class Gate: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Door: public NamedObjectExt {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Dog: public NamedObjectExt {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Lyle: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Body: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Actions */
	class Action1 : public Action {
	public:
		void signal() override;
	};
	class Action2 : public Action {
	public:
		void signal() override;
	};
	class Action3 : public Action {
	public:
		void signal() override;
	};
	class Action4 : public Action {
	public:
		void signal() override;
	};

public:
	SequenceManager _sequenceManager1, _sequenceManager2;
	SpeakerGameText _gameTextSpeaker;
	SpeakerJakeJacket _jakeJacketSpeaker;
	SpeakerLyleHat _lyleHatSpeaker;
	Exterior _exterior;
	Gate _gate;
	Door _door;
	Dog _dog;
	NamedHotspot _item2;
	NamedHotspot _item3;
	NamedObject _object4;
	NamedObject _object5;
	Lyle _lyle;
	Body _body;
	WestExit _westExit;
	ASoundExt _sound1;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	Action4 _action4;
	int _lyleDialogCtr;
	int _field1976;

	Scene900();
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
	void synchronize(Serializer &s) override;
};

class Scene910: public PalettedScene {
	/* Actions */
	class Action1 : public Action {
	public:
		void signal() override;
	};
	class Action2 : public Action {
	public:
		void signal() override;
	};
	/* Objects */
	class Lyle: public NamedObject {
	public:
		int _field90;
		void synchronize(Serializer &s) override;
		bool startAction(CursorType action, Event &event) override;
	};
	class Nico: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Stuart: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Forbes: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class PowerCord: public NamedObject {
	public:
		int _field90, _field92;

		void synchronize(Serializer &s) override;
		bool startAction(CursorType action, Event &event) override;
		void init(int val);

	};
	class BreakerBox: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class FakeWall: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	class Object13: public NamedObject {
	protected:
		int _state, _mode;
	public:
		void setupBreaker(int x, int y, int mode, int8 frameNumber);
		void synchronize(Serializer &s) override;
		bool startAction(CursorType action, Event &event) override;
		void remove() override;
	};

	class BlackPlug: public Object13 {
	public:
		void init(int x, int y, int arg8, int8 mode);
		bool startAction(CursorType action, Event &event) override;
		void remove() override;
	};

	class Object25: public NamedObject {
		int _field90, _field92;
	public:
		Object25();
		void setupHiddenSwitch(int x, int y, int arg8, int argA);
		void synchronize(Serializer &s) override;
		bool startAction(CursorType action, Event &event) override;
		void remove() override;
	};

	class BreakerBoxInset: public FocusObject {
		Object13 _object13, _object14, _object15, _object16, _object17, _object18;
		Object13 _object19, _object20, _object21, _object22, _object23, _object24;
		Object25 _object25, _object26;
	public:
		Object13 _object27;
		BlackPlug _object28;
		Common::String getClassName() override { return "Scene910_object12"; }
		void postInit(SceneObjectList *OwnerList = NULL) override;
		void remove() override;
	};

	class PowerButton: public NamedObject {
	public:
		NamedObject _object32;
		void remove() override;
		bool startAction(CursorType action, Event &event) override;
		void init(int frame);
	};

	class GeneratorInset: public FocusObject {
		BlackPlug _blackPlug;
		PowerButton _powerButton;
	public:
		Common::String getClassName() override { return "Scene910_object29"; }
		void postInit(SceneObjectList *OwnerList = NULL) override;
		void remove() override;
	};

	/* Items */
	class Generator: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item2: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item3: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item9: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item15: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item16: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item17: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	int _sceneSubMode, _breakerButtonCtr, _field2DE0, _field2DE2, _field2DE4;
	Common::Point _destPos;
public:
	SequenceManager _sequenceManager1, _sequenceManager2;
	SpeakerGameText _gameTextSpeaker;
	SpeakerJakeJacket _jakeJacketSpeaker;
	SpeakerLyleHat _lyleHatSpeaker;
	SpeakerFBI _fbiSpeaker;
	SpeakerNico _nicoSpeaker;
	SpeakerDA _daSpeaker;
	Action1 _action1;
	Action2 _action2;
	Timer _timer1;
	Lyle _lyle;
	Nico _nico;
	Stuart _stuart;
	Forbes _forbes;
	NamedObject _object5,  _vent, _shadow;
	PowerCord _blackCord, _yellowCord;
	BreakerBox _breakerBox;
	FakeWall _fakeWall;
	BreakerBoxInset _breakerBoxInset;
	GeneratorInset _generatorInset;
	NamedObject _object30, _object31, _object32;
	Generator _generator;
	Item2 _item2;
	Item3 _item3;
	NamedHotspot _item4,  _item5,  _item6,  _item7,  _item8;
	Item9 _item9, _item10;
	NamedHotspot _item11, _backWall, _item13, _item14;
	Item15 _item15;
	Item16 _item16;
	Item17 _item17;
	ASoundExt _sound1, _sound2;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void synchronize(Serializer &s) override;
	void remove() override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
	void checkGun() override;
	void openHiddenDoor();
	void closeHiddenDoor();
};

class Scene920: public SceneExt {
	/* Items */
	class Item1: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item8: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

public:
	SequenceManager _sequenceManager1;
	SpeakerGameText _gameTextSpeaker;
	SpeakerJakeJacket _jakeJacketSpeaker;

	Item1 _crate;
	NamedHotspot _item2;
	NamedHotspot _item3;
	NamedHotspot _item4;
	NamedHotspot _item5;
	NamedHotspot _item6;
	NamedHotspot _item7;
	NamedObject _crateTop;
	NamedObject _crateWindow;
	NamedObject _doorway;
	Item8 _exitN;
	Common::Point _oldCoord;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
	void synchronize(Serializer &s) override;
};

class Scene930: public PalettedScene {
	/* Objects */
	class Object1: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Object2: public FocusObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Object3: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Object4: public FocusObject {
	public:
		bool startAction(CursorType action, Event &event) override;
		void remove() override;
	};
	class Object5: public FocusObject {
	public:
		bool startAction(CursorType action, Event &event) override;
		void remove() override;
	};
	/* Items */
	class Item1: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	/* Actions */
	class Action1 : public Action {
	public:
		void signal() override;
	};
	class Action2 : public Action {
	public:
		void signal() override;
	};
	class Action3 : public Action {
	public:
		void signal() override;
	};

	void showBootInset();
	void showBoxInset();
	void showSoleInset();
public:
	SequenceManager _sequenceManager1;
	Object1 _box;
	Object2 _boxInset;
	Object3 _boots;
	Object4 _bootsInset;
	Object5 _soleInset;

	Item1 _item1;
	NamedHotspot _item2;
	NamedHotspot _item3;
	NamedHotspot _item4;
	NamedHotspot _item5;
	NamedHotspot _item6;
	NamedHotspot _item7;
	NamedHotspot _item8;
	NamedHotspot _item9;
	NamedHotspot _item10;
	NamedHotspot _item11;
	NamedHotspot _item12;
	NamedHotspot _item13;
	NamedHotspot _item14;
	NamedHotspot _item15;
	NamedHotspot _item16;
	NamedHotspot _item17;
	NamedHotspot _item18;
	NamedHotspot _item19;
	NamedHotspot _item20;
	NamedHotspot _item21;

	Action1 _action1;
	Action2 _action2;
	Action3 _action3;

	SpeakerGameText gameTextSpeaker;

	bool _soleOpened;
	int _bootInsetDisplayed;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void dispatch() override;
	void synchronize(Serializer &s) override;
};

class Scene935: public PalettedScene {
	/* Actions */
	class Action1 : public Action {
	public:
		void signal() override;
	};

public:
	SequenceManager _sequenceManager;
	NamedObject _object1;
	NamedObject _object2;
	NamedObject _object3;
	Action1 _action1;
	VisualSpeaker _visualSpeaker;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
	void signal() override;
	void dispatch() override;
};

class Scene940: public SceneExt {
	/* Items */
	class Item1: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	/* Actions */
	class Action1 : public Action {
	public:
		void signal() override;
	};

public:
	SequenceManager _sequenceManager1;
	SequenceManager _sequenceManager2;
	SequenceManager _sequenceManager3;
	SequenceManager _sequenceManager4;
	NamedObject _object1;
	NamedObject _object2;
	NamedObject _object3;
	NamedObject _object4;
	NamedObject _object5;
	NamedObject _object6;
	NamedObject _object7;
	NamedObject _object8;
	NamedObject _object9;
	NamedObject _object10;
	NamedObject _object11;
	NamedObject _object12;
	NamedObject _object13;
	NamedObject _object14;
	NamedObject _object15;
	NamedObject _object16;
	NamedObject _object17;
	NamedObject _object18;
	Item1 _item1;
	Action1 _action1;

	SpeakerGameText _gameTextSpeaker1;
	SpeakerGameText _gameTextSpeaker2;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
};

} // End of namespace BlueForce
} // End of namespace TsAGE

#endif
