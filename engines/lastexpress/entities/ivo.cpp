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

#include "lastexpress/entities/ivo.h"

#include "lastexpress/fight/fight.h"

#include "lastexpress/game/action.h"
#include "lastexpress/game/entities.h"
#include "lastexpress/game/logic.h"
#include "lastexpress/game/object.h"
#include "lastexpress/game/savepoint.h"
#include "lastexpress/game/scenes.h"
#include "lastexpress/game/state.h"

#include "lastexpress/lastexpress.h"

namespace LastExpress {

Ivo::Ivo(LastExpressEngine *engine) : Entity(engine, kEntityIvo) {
	ADD_CALLBACK_FUNCTION(Ivo, reset);
	ADD_CALLBACK_FUNCTION_S(Ivo, draw);
	ADD_CALLBACK_FUNCTION_SI(Ivo, enterExitCompartment);
	ADD_CALLBACK_FUNCTION_I(Ivo, updateFromTime);
	ADD_CALLBACK_FUNCTION_I(Ivo, updateFromTicks);
	ADD_CALLBACK_FUNCTION_II(Ivo, updateEntity);
	ADD_CALLBACK_FUNCTION(Ivo, callbackActionOnDirection);
	ADD_CALLBACK_FUNCTION_S(Ivo, playSound);
	ADD_CALLBACK_FUNCTION(Ivo, callbackActionRestaurantOrSalon);
	ADD_CALLBACK_FUNCTION_II(Ivo, savegame);
	ADD_CALLBACK_FUNCTION(Ivo, goCompartment);
	ADD_CALLBACK_FUNCTION(Ivo, sitAtTableWithSalko);
	ADD_CALLBACK_FUNCTION(Ivo, leaveTableWithSalko);
	ADD_CALLBACK_FUNCTION(Ivo, chapter1);
	ADD_CALLBACK_FUNCTION(Ivo, chapter1Handler);
	ADD_CALLBACK_FUNCTION(Ivo, inCompartment);
	ADD_CALLBACK_FUNCTION(Ivo, function17);
	ADD_CALLBACK_FUNCTION(Ivo, chapter2);
	ADD_CALLBACK_FUNCTION(Ivo, goBreakfast);
	ADD_CALLBACK_FUNCTION(Ivo, atBreakfast);
	ADD_CALLBACK_FUNCTION(Ivo, function21);
	ADD_CALLBACK_FUNCTION(Ivo, chapter3);
	ADD_CALLBACK_FUNCTION(Ivo, chapter3Handler);
	ADD_CALLBACK_FUNCTION(Ivo, chapter4);
	ADD_CALLBACK_FUNCTION(Ivo, chapter4Handler);
	ADD_CALLBACK_FUNCTION(Ivo, returnCompartment4);
	ADD_CALLBACK_FUNCTION(Ivo, inCompartment4);
	ADD_CALLBACK_FUNCTION(Ivo, hiding);
	ADD_CALLBACK_FUNCTION(Ivo, function29);
	ADD_CALLBACK_FUNCTION(Ivo, chapter5);
	ADD_CALLBACK_FUNCTION(Ivo, chapter5Handler);
	ADD_CALLBACK_FUNCTION(Ivo, fightCath);
	ADD_CALLBACK_FUNCTION(Ivo, knockedOut);
	ADD_CALLBACK_FUNCTION(Ivo, function34);
}

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(1, Ivo, reset)
	Entity::reset(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_S(2, Ivo, draw)
	Entity::draw(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SI(3, Ivo, enterExitCompartment, ObjectIndex)
	Entity::enterExitCompartment(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(4, Ivo, updateFromTime, uint32)
	Entity::updateFromTime(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(5, Ivo, updateFromTicks, uint32)
	Entity::updateFromTicks(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(6, Ivo, updateEntity, CarIndex, EntityPosition)
	if (savepoint.action == kActionExcuseMeCath || savepoint.action == kActionExcuseMe) {
		getSound()->playSound(kEntityPlayer, "CAT1127A");
		return;
	}

	Entity::updateEntity(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(7, Ivo, callbackActionOnDirection)
	Entity::callbackActionOnDirection(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_NOSETUP(8, Ivo, playSound)
	Entity::playSound(savepoint, true);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(9, Ivo, callbackActionRestaurantOrSalon)
	Entity::callbackActionRestaurantOrSalon(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(10, Ivo, savegame, SavegameType, uint32)
	Entity::savegame(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(11, Ivo, goCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getEntities()->isDistanceBetweenEntities(kEntityIvo, kEntitySalko, 750) || getEntities()->checkDistanceFromPosition(kEntitySalko, kPosition_2740, 500)) {
			getSavePoints()->push(kEntityIvo, kEntitySalko, kAction123668192);

			setCallback(4);
			setup_enterExitCompartment("613Ah", kObjectCompartmentH);
		}
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityIvo, "809DS");
		if (getEntities()->isInRestaurant(kEntityPlayer))
			getEntities()->updateFrame(kEntityIvo);

		setCallback(1);
		setup_callbackActionOnDirection();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSavePoints()->push(kEntityIvo, kEntitySalko, kAction125242096);

			setCallback(2);
			setup_updateEntity(kCarRedSleeping, kPosition_2740);
			break;

		case 2:
			if (getEntities()->isDistanceBetweenEntities(kEntityIvo, kEntitySalko, 750) || getEntities()->checkDistanceFromPosition(kEntitySalko, kPosition_2740, 500)) {
				getSavePoints()->push(kEntityIvo, kEntitySalko, kAction123668192);

				setCallback(3);
				setup_enterExitCompartment("613Ah", kObjectCompartmentH);
			} else {
				getEntities()->drawSequenceLeft(kEntityIvo, "613Hh");
				getEntities()->enterCompartment(kEntityIvo, kObjectCompartmentH, true);
			}
			break;

		case 3:
			getData()->entityPosition = kPosition_2740;
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityIvo);

			callbackAction();
			break;

		case 4:
			getEntities()->exitCompartment(kEntityIvo, kObjectCompartmentH, true);
			getData()->entityPosition = kPosition_2740;
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityIvo);

			callbackAction();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(12, Ivo, sitAtTableWithSalko)
	switch (savepoint.action) {
	default:
		break;

	case kActionExitCompartment:
		getEntities()->clearSequences(kEntitySalko);
		getSavePoints()->push(kEntityIvo, kEntityTables2, kAction136455232);

		callbackAction();
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityIvo, "023A1");
		getEntities()->drawSequenceRight(kEntitySalko, "023A2");
		getEntities()->drawSequenceRight(kEntityTables2, "023A3");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(13, Ivo, leaveTableWithSalko)
	switch (savepoint.action) {
	default:
		break;

	case kActionExitCompartment:
		getSavePoints()->push(kEntityIvo, kEntityTables2, kActionDrawTablesWithChairs, "009E");
		getEntities()->clearSequences(kEntitySalko);

		callbackAction();
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityIvo, "023D1");
		getEntities()->drawSequenceRight(kEntitySalko, "023D2");
		getEntities()->drawSequenceRight(kEntityTables2, "023D3");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(14, Ivo, chapter1)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		Entity::timeCheck(kTimeChapter1, params->param1, WRAP_SETUP_FUNCTION(Ivo, setup_chapter1Handler));
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject47, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		getData()->entityPosition = kPosition_4691;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRestaurant;

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(15, Ivo, chapter1Handler)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		getData()->entityPosition = getEntityData(kEntityMilos)->entityPosition;
		getData()->location = getEntityData(kEntityMilos)->location;
		getData()->car = getEntityData(kEntityMilos)->car;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_goCompartment();
			break;

		case 2:
			getSavePoints()->push(kEntityIvo, kEntityMilos, kAction135024800);
			setup_inCompartment();
			break;
		}
		break;

	case kAction125242096:
		setCallback(1);
		setup_updateFromTicks(75);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(16, Ivo, inCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;

		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
		getEntities()->clearSequences(kEntityIvo);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceLeft(kEntityIvo, "613Ch");
			getEntities()->enterCompartment(kEntityIvo, kObjectCompartmentH, true);
			getSavePoints()->push(kEntityIvo, kEntityCoudert, kAction88652208);
			break;

		case 2:
			getData()->entityPosition = kPosition_2740;
			getData()->location = kLocationInsideCompartment;

			getEntities()->clearSequences(kEntityIvo);
			getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
			break;
		}
		break;

	case kAction122865568:
		getData()->location = kLocationOutsideCompartment;

		setCallback(1);
		setup_enterExitCompartment("613Bh", kObjectCompartmentH);
		break;

	case kAction123852928:
		getEntities()->exitCompartment(kEntityIvo, kObjectCompartmentH, true);

		setCallback(2);
		setup_enterExitCompartment("613Dh", kObjectCompartmentH);
		break;

	case kAction221683008:
		getSavePoints()->push(kEntityIvo, kEntityCoudert, kAction123199584);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(17, Ivo, function17)
	if (savepoint.action == kActionDefault) {
		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;

		getEntities()->clearSequences(kEntityIvo);
		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(18, Ivo, chapter2)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		Entity::timeCheck(kTime1777500, params->param1, WRAP_SETUP_FUNCTION(Ivo, setup_goBreakfast));
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityIvo);

		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothesDefault;
		getData()->inventoryItem = kItemNone;

		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject47, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(19, Ivo, goBreakfast)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterExitCompartment("613FH", kObjectCompartmentH);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;
			if (getData()->entityPosition < kPosition_2087)
				getData()->entityPosition = kPosition_2088;

			setCallback(2);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 2:
			getSavePoints()->push(kEntityIvo, kEntitySalko, kAction136184016);
			break;

		case 3:
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(4);
			setup_draw("809US");
			break;

		case 4:
			setCallback(5);
			setup_sitAtTableWithSalko();
			break;

		case 5:
			getData()->location = kLocationInsideCompartment;
			setup_atBreakfast();
			break;
		}
		break;

	case kAction102675536:
		setCallback(3);
		setup_callbackActionRestaurantOrSalon();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(20, Ivo, atBreakfast)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime1809000 && params->param1) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				getData()->location = kLocationOutsideCompartment;

				setCallback(2);
				setup_leaveTableWithSalko();
			}
		}
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityIvo, kEntityWaiter2, kAction189688608);
		getEntities()->drawSequenceLeft(kEntityIvo, "023B");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			 getSavePoints()->push(kEntityIvo, kEntityWaiter2, kAction101106391);
			 getEntities()->drawSequenceLeft(kEntityIvo, "023B");
			 params->param1 = 1;
			break;

		case 2:
			setCallback(3);
			setup_goCompartment();
			break;

		case 3:
			getSavePoints()->push(kEntityIvo, kEntityWaiter2, kAction236237423);
			setup_function21();
			break;
		}
		break;

	case kAction123712592:
		getEntities()->drawSequenceLeft(kEntityIvo, "023C2");

		setCallback(1);
		setup_updateFromTime(450);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(21, Ivo, function21)
	if (savepoint.action == kActionDefault) {
		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;

		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(22, Ivo, chapter3)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_chapter3Handler();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityIvo);

		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothesDefault;
		getData()->inventoryItem = kItemNone;

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(23, Ivo, chapter3Handler)
	if (savepoint.action == kActionDefault)
		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(24, Ivo, chapter4)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_chapter4Handler();
		break;

	case kActionDefault:
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRestaurant;
		getData()->inventoryItem = kItemNone;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(25, Ivo, chapter4Handler)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime2361600 && getEntities()->isSomebodyInsideRestaurantOrSalon()) {
			getData()->location = kLocationOutsideCompartment;
			setup_returnCompartment4();
		}
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityIvo, kEntityTables2, kAction136455232);
		getEntities()->drawSequenceLeft(kEntityIvo, "023B");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(26, Ivo, returnCompartment4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_leaveTableWithSalko();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_goCompartment();
			break;

		case 2:
			setup_inCompartment4();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(27, Ivo, inCompartment4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;

			if (getData()->entityPosition < kPosition_2087)
				getData()->entityPosition = kPosition_2088;

			setCallback(2);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 2:
			getEntities()->clearSequences(kEntityIvo);
			setup_hiding();
			break;

		case 3:
			getEntities()->drawSequenceLeft(kEntityIvo, "613Ch");
			getEntities()->enterCompartment(kEntityIvo, kObjectCompartmentH, true);
			getSavePoints()->push(kEntityIvo, kEntityCoudert, kAction88652208);
			break;

		case 4:
			getEntities()->exitCompartment(kEntityIvo, kObjectCompartmentH, true);
			getData()->entityPosition = kPosition_2740;
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityIvo);
			break;
		}
		break;

	case kAction55996766:
		setCallback(1);
		setup_enterExitCompartment("613FH", kObjectCompartmentH);
		break;

	case kAction122865568:
		getData()->location = kLocationOutsideCompartment;

		setCallback(3);
		setup_enterExitCompartment("613Bh", kObjectCompartmentH);
		break;

	case kAction123852928:
		setCallback(4);
		setup_enterExitCompartment("613Dh", kObjectCompartmentH);
		break;

	case kAction221683008:
		getSavePoints()->push(kEntityIvo, kEntityCoudert, kAction123199584);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(28, Ivo, hiding)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime2425500 && !params->param1) {
			params->param1 = 1;
			setCallback(1);
			setup_updateEntity(kCarRedSleeping, kPosition_2740);
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterExitCompartment("613EH", kObjectCompartmentH);
			break;

		case 2:
			setup_function29();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(29, Ivo, function29)
	if (savepoint.action == kActionDefault) {
		getEntities()->clearSequences(kEntityIvo);
		getObjects()->update(kObjectCompartmentH, kEntityPlayer, kObjectLocation3, kCursorHandKnock, kCursorHand);

		getData()->entityPosition = kPosition_2740;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->inventoryItem = kItemNone;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(30, Ivo, chapter5)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_chapter5Handler();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityIvo);

		getData()->entityPosition = kPosition_540;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarBaggageRear;
		getData()->inventoryItem = kItemNone;

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(31, Ivo, chapter5Handler)
	if (savepoint.action == kAction192637492)
		setup_fightCath();
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(32, Ivo, fightCath)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->location = kLocationOutsideCompartment;
		getData()->entityPosition = kPosition_540;
		getData()->car = kCarBaggageRear;
		getData()->inventoryItem = kItemNone;

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventCathIvoFight);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSound()->playSound(kEntityPlayer, "LIB090");
			getAction()->playAnimation(kEventCathIvoFight);

			setCallback(2);
			setup_savegame(kSavegameTypeTime, kTimeNone);
			break;

		case 2:
			params->param1 = getFight()->setup(kFightIvo);
			if (params->param1) {
				getLogic()->gameOver(kSavegameTypeIndex, 0, kSceneNone, params->param1 == Fight::kFightEndLost);
			} else {
				getScenes()->loadSceneFromPosition(kCarBaggageRear, 96);
				setup_knockedOut();
			}
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(33, Ivo, knockedOut)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getState()->time = (TimeValue)(getState()->time + 1800);

		setCallback(1);
		setup_savegame(kSavegameTypeTime, kTimeNone);
		break;

	case kActionCallback:
		if (getCallback() == 1)
			getObjects()->update(kObject94, kEntityPlayer, kObjectLocation2, kCursorKeepValue, kCursorKeepValue);

		break;

	case kAction135800432:
		setup_function34();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(34, Ivo, function34)
	if (savepoint.action == kActionDefault)
		getEntities()->clearSequences(kEntityIvo);
IMPLEMENT_FUNCTION_END

} // End of namespace LastExpress
