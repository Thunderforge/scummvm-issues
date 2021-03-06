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

#ifndef TSAGE_BLUEFORCE_SCENES1_H
#define TSAGE_BLUEFORCE_SCENES1_H

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

class Scene100: public SceneExt {
	/* Support classes */
	class Text: public SceneText {
	public:
		Common::String getClassName() override { return "BF100Text"; }
		void dispatch() override;
	};

	/* Actions */
	class Action1: public ActionExt {
	private:
		void setTextStrings(const Common::String &msg1, const Common::String &msg2, Action *action);
	public:
		Text _sceneText1;
		SceneText _sceneText2;
		int _textHeight;

		Common::String getClassName() override { return "BF100Action1"; }
		void synchronize(Serializer &s) override {
			ActionExt::synchronize(s);
			s.syncAsSint16LE(_textHeight);
		}
		void signal() override;
	};
	class Action2: public ActionExt {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	Action1 _action1;
	Action2 _action2;
	ScenePalette _scenePalette;
	NamedObject _object1, _object2, _object3, _object4, _object5;
	int _index;

	Scene100();
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
};

class Scene109: public PalettedScene {
	/* Actions */
	class Action1: public Action {
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

public:
	SequenceManager _sequenceManager1, _sequenceManager2, _sequenceManager3;
	SequenceManager _sequenceManager4, _sequenceManager5, _sequenceManager6;
	SequenceManager _sequenceManager7, _sequenceManager8;
	SceneObject _object1, _object2, _protaginist2, _protaginist1, _cop1;
	SceneObject _drunk, _cop2, _bartender, _beerSign, _animationInset;
	IntroSceneText _text;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
public:
	Scene109();

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
};

class Scene110: public SceneExt {
	/* Actions */
	class Action1: public Action {
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
		void dispatch() override;
	};
	class Action4: public Action {
	public:
		void signal() override;
		void dispatch() override;
	};
	class Action5: public Action {
	public:
		void signal() override;
	};
public:
	NamedObject _object1, _object2, _object3, _object4, _object5, _object6, _object7, _object8, _object9, _object10;
	ASound _sound;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	Action4 _action4;
	Action5 _action5;
public:
	void postInit(SceneObjectList *OwnerList = NULL) override;
};

class Scene114: public SceneExt {
	/* Objects */
	class Vechile: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Door: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
public:
	SequenceManager _sequenceManager1;
	Vechile _vechile;
	Door _door;
	NamedObject _lyle;
	NamedHotspot _item1;
public:
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
};

class Scene115: public SceneExt {
	/* Objects */
	class Kate: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Tony: public NamedObject {
	public:
		int _talkToTonyCtr2;
		bool startAction(CursorType action, Event &event) override;
	};
	class Object3: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Object4: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Custom class */
	class EventHandler1: public EventHandler {
	public:
		Common::String getClassName() override { return "Scene115_EventHandler1"; }
		void dispatch() override;
	};

	/* Items */
	class Jukebox: public NamedHotspot {
		SequenceManager _sequenceManager6;
	public:
		int _jokeboxPlayingCtr;

		Jukebox();
		bool startAction(CursorType action, Event &event) override;
		void signal() override;
		void synchronize(Serializer &s) override;
	};
	class Item10: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item14: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Actions */
	class Action1: public Action {
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
	class Action7: public Action {
	public:
		void signal() override;
	};
	class Action8: public Action {
	public:
		void signal() override;
	};
	class Action9: public Action {
	public:
		void signal() override;
	};

	SequenceManager _sequenceManager1;
	SequenceManager _sequenceManager2;
	SequenceManager _sequenceManager3;
	SequenceManager _sequenceManager4;
	SequenceManager _sequenceManager5;
	Kate _kate;
	Tony _tony;
	Object3 _object3;
	Object4 _object4;
	SceneObject _object5,  _object6,  _neonSign,  _object8,  _object9;
	SceneObject _object10, _object11, _object12, _object13;
	Jukebox _itemJukebox;
	EventHandler1 _eventHandler1;
	NamedHotspot _item2, _item3, _item4, _item5, _item6, _item7, _item8, _item9;
	Item10 _item10;
	NamedHotspot _item11, _item12, _item13;
	Item14 _item14;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	Action4 _action4;
	Action5 _action5;
	Action6 _action6;
	Action7 _action7;
	Action8 _action8;
	Action9 _action9;
	SpeakerGameText _gameTextSpeaker;
	SpeakerKate _kateSpeaker;
	SpeakerTony _tonySpeaker;
	SpeakerJakeJacket _jakeJacketSpeaker;
	SpeakerJakeUniform _jakeUniformSpeaker;
	SpeakerLyleHat _lyleHatSpeaker;
	ASound _sound1;
	int _lineNumModifier;
	int _jukeboxPlaying;
	int _talkToTonyCtr;
public:
	Scene115();
	void synchronize(Serializer &s) override;
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
};

class Scene125: public SceneExt {
	class Action1: public Action {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
		void dispatch() override;
	};
	class Action3: public Action {
	public:
		void signal() override;
		void dispatch() override;
	};
	class Action4: public Action {
	public:
		void signal() override;
		void dispatch() override;
	};
	class Action5: public Action {
	public:
		void signal() override;
	};
	class Action6: public Action {
	public:
		void signal() override;
		void dispatch() override;
	};

public:
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	Action4 _action4;
	Action5 _action5;
	Action6 _action6;
	NamedObject _object1, _object2, _object3, _object4, _object5;
	NamedObject _object6, _object7, _object8, _object9;
	ASoundExt _soundExt1;
	ASoundExt _soundExt2;

	void postInit(SceneObjectList *OwnerList) override;
};

class Scene140: public SceneExt {
	class Action1: public Action {
	public:
		void signal() override;
	};
public:
	Action1 _action1;
	ASoundExt _soundExt1;
	NamedObject _object1;
	NamedObject _object2;
	IntroSceneText _text;

	void postInit(SceneObjectList *OwnerList) override;
};

class Scene150: public SceneExt {
	class Action1: public Action {
		NamedObject _object2;
		ASound _sound1;
	public:
		void signal() override;
	};
public:
	NamedObject _object1;
	Action1 _action1;

	void postInit(SceneObjectList *OwnerList) override;
};

class Scene160: public SceneExt {
	class Action1: public Action {
	public:
		void signal() override;
	};
	class Action2: public Action {
	public:
		void signal() override;
		void process(Event &event) override;
	};
	class Action3: public ActionExt {
	public:
		void signal() override;
	};
public:
	NamedObject _flag, _kid, _kidBody, _leftOfficer, _grandma, _rightOfficer;
	ASound _sound1;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	IntroSceneText _text;

	void postInit(SceneObjectList *OwnerList) override;
};

class Scene180: public SceneExt {
	/* Objects */
	class Vechile: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Items */
	class GarageExit: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
public:
	SequenceManager _sequenceManager;
	SpeakerGameText _gameTextSpeaker;
	NamedObject _object1;
	Vechile _vechile;
	NamedHotspot _driveway, _garage, _frontDoor, _house, _street;
	NamedHotspot _lawn, _bushes, _palms, _fence, _steps;
	NamedHotspot _curb, _sky;
	GarageExit _garageExit;
	ASoundExt _sound1;
	SceneMessage _sceneMessage;
	int _dispatchMode;

	Scene180();
	void synchronize(Serializer &s) override;
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
};

class Scene190: public SceneExt {
	/* Objects */
	class LyleCar: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Items */
	class Item1: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item2: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Exit: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Actions */
	class Action1: public Action {
	public:
		void signal() override;
	};
public:
	SequenceManager _sequenceManager;
	FollowerObject _object1;
	NamedObject _door, _flag;
	LyleCar _lyleCar;
	Item1 _item1;
	Item2 _item2;
	NamedHotspot _item3, _item4, _item5, _item6;
	NamedHotspot _item7, _item8, _item9, _item10;
	Exit _exit;
	Action1 _action1;
	ASoundExt _sound;
	SpeakerGameText _speaker;
	bool _fieldB52;

	Scene190();
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void signal() override;
	void process(Event &event) override;
	void dispatch() override;
	void synchronize(Serializer &s) override;
};

} // End of namespace BlueForce

} // End of namespace TsAGE

#endif
