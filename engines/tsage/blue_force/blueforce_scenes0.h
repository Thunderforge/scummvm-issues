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

#ifndef TSAGE_BLUEFORCE_SCENES0_H
#define TSAGE_BLUEFORCE_SCENES0_H

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

class Scene20 : public SceneExt {
	/* Actions */
	class Action1 : public Action {
	private:
		ASoundExt _sound;
	public:
		void signal() override;
	};
public:
	Action1 _action1;
	ScenePalette _scenePalette;
	SceneObject _tsunamiWave, _letterT, _letterS, _letterU;
	SceneObject _letterN, _letterA, _letterM, _letterI;

	void postInit(SceneObjectList *OwnerList = NULL) override;
};

class Scene50: public SceneExt {
	class Tooltip: public SavedObject {
	public:
		Rect _bounds;
		Common::String _msg;
		int _newSceneNumber;
		int _locationId;
	public:
		Tooltip();
		void set(const Rect &bounds, int sceneNum, const Common::String &msg, int locationId);
		void update();
		void highlight(bool btnDown);

		Common::String getClassName() override { return "Scene50_Tooltip"; }
		void synchronize(Serializer &s) override;
	};
	class Tooltip2: public Action {
	public:
		Tooltip2(): Action() {}

		Common::String getClassName() override { return "Scene50_Tooltip2"; }
		void signal() override;
		void dispatch() override;
	};
public:
	int _sceneNumber;
	SceneText _text;
	SceneItemType2 _item;
	Tooltip _location1, _location2, _location3, _location4, _location5;
	Tooltip _location6, _location7, _location8, _location9;
	Timer _timer;
public:
	Scene50();

	Common::String getClassName() override { return "Scene50"; }
	void synchronize(Serializer &s) override;

	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
	void signal() override;
	void process(Event &event) override;
};

class Scene60 : public SceneExt {
	/* Items */
	class Ignition: public NamedHotspot {
	private:
		bool check1();
		bool check2();
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Item3: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Radio: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class Compartment: public NamedHotspot {
	public:
		bool startAction(CursorType action, Event &event) override;
	};

	/* Objects */
	class MirandaCard: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class TicketBook: public NamedObject {
	public:
		bool startAction(CursorType action, Event &event) override;
	};
	class CompartmentDoor: public NamedObject {
	public:
		bool _flag;
		bool startAction(CursorType action, Event &event) override;
	};

	/* Actions */
	class Action1: public ActionExt {
	private:
		int useRadio();
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
	SequenceManager _sequenceManager;
	Action1 _action1;
	Action2 _action2;
	Action3 _action3;
	NamedObject _object1;
	MirandaCard _mirandaCard;
	TicketBook _ticketBook;
	CompartmentDoor _compartmentDoor;
	SceneObject _dashboard;
	BackgroundSceneObject _car;
	NamedHotspot _item1;
	Ignition _ignition;
	Item3 _item3;
	Radio _radio;
	Compartment _compartment;
	SpeakerGameText _gameTextSpeaker;
	SpeakerJakeRadio _jakeRadioSpeaker;
	ASound _sound;
	int _newScene;
	int _sceneNumber;
	int _visage;
	CursorType _cursorId;

	Scene60();
	void synchronize(Serializer &s) override;
	void postInit(SceneObjectList *OwnerList = NULL) override;
	void remove() override;
	void signal() override;
	void dispatch() override;
};


} // End of namespace BlueForce

} // End of namespace TsAGE

#endif
