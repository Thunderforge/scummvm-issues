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

#include "lastexpress/entities/alexei.h"

#include "lastexpress/game/action.h"
#include "lastexpress/game/entities.h"
#include "lastexpress/game/inventory.h"
#include "lastexpress/game/logic.h"
#include "lastexpress/game/object.h"
#include "lastexpress/game/savepoint.h"
#include "lastexpress/game/scenes.h"
#include "lastexpress/game/state.h"

#include "lastexpress/lastexpress.h"

namespace LastExpress {

Alexei::Alexei(LastExpressEngine *engine) : Entity(engine, kEntityAlexei) {
	ADD_CALLBACK_FUNCTION(Alexei, reset);
	ADD_CALLBACK_FUNCTION_S(Alexei, playSound);
	ADD_CALLBACK_FUNCTION_I(Alexei, updateFromTime);
	ADD_CALLBACK_FUNCTION_S(Alexei, draw);
	ADD_CALLBACK_FUNCTION_SII(Alexei, updatePosition);
	ADD_CALLBACK_FUNCTION_SI(Alexei, enterExitCompartment);
	ADD_CALLBACK_FUNCTION(Alexei, callbackActionOnDirection);
	ADD_CALLBACK_FUNCTION_SIIS(Alexei, callSavepoint);
	ADD_CALLBACK_FUNCTION_II(Alexei, savegame);
	ADD_CALLBACK_FUNCTION_II(Alexei, updateEntity);
	ADD_CALLBACK_FUNCTION_SSI(Alexei, draw2);
	ADD_CALLBACK_FUNCTION(Alexei, callbackActionRestaurantOrSalon);
	ADD_CALLBACK_FUNCTION(Alexei, enterComparment);
	ADD_CALLBACK_FUNCTION(Alexei, exitCompartment);
	ADD_CALLBACK_FUNCTION(Alexei, pacingAtWindow);
	ADD_CALLBACK_FUNCTION_IS(Alexei, compartmentLogic);
	ADD_CALLBACK_FUNCTION(Alexei, chapter1);
	ADD_CALLBACK_FUNCTION(Alexei, atDinner);
	ADD_CALLBACK_FUNCTION(Alexei, returnCompartment);
	ADD_CALLBACK_FUNCTION(Alexei, goSalon);
	ADD_CALLBACK_FUNCTION(Alexei, sitting);
	ADD_CALLBACK_FUNCTION(Alexei, standingAtWindow);
	ADD_CALLBACK_FUNCTION(Alexei, waitingForTatiana);
	ADD_CALLBACK_FUNCTION(Alexei, upset);
	ADD_CALLBACK_FUNCTION(Alexei, returnCompartmentNight);
	ADD_CALLBACK_FUNCTION(Alexei, function26);
	ADD_CALLBACK_FUNCTION(Alexei, function27);
	ADD_CALLBACK_FUNCTION(Alexei, chapter2);
	ADD_CALLBACK_FUNCTION(Alexei, inCompartment2);
	ADD_CALLBACK_FUNCTION(Alexei, atBreakfast);
	ADD_CALLBACK_FUNCTION(Alexei, returnCompartment2);
	ADD_CALLBACK_FUNCTION(Alexei, chapter3);
	ADD_CALLBACK_FUNCTION(Alexei, playingChess);
	ADD_CALLBACK_FUNCTION(Alexei, inPart3);
	ADD_CALLBACK_FUNCTION(Alexei, pacing3);
	ADD_CALLBACK_FUNCTION(Alexei, goSalon3);
	ADD_CALLBACK_FUNCTION(Alexei, chapter4);
	ADD_CALLBACK_FUNCTION(Alexei, inCompartment4);
	ADD_CALLBACK_FUNCTION(Alexei, meetTatiana);
	ADD_CALLBACK_FUNCTION(Alexei, leavePlatform);
	ADD_CALLBACK_FUNCTION(Alexei, inCompartmentAgain);
	ADD_CALLBACK_FUNCTION(Alexei, goSalon4);
	ADD_CALLBACK_FUNCTION(Alexei, pacing);
	ADD_CALLBACK_FUNCTION(Alexei, goToPlatform);
	ADD_CALLBACK_FUNCTION(Alexei, returnCompartment4);
	ADD_CALLBACK_FUNCTION(Alexei, bombPlanB);
	ADD_CALLBACK_FUNCTION(Alexei, function47);
	ADD_CALLBACK_FUNCTION(Alexei, chapter5);
}

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(1, Alexei, reset)
	Entity::reset(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_S(2, Alexei, playSound)
	Entity::playSound(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(3, Alexei, updateFromTime, uint32)
	Entity::updateFromTime(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_S(4, Alexei, draw)
	Entity::draw(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SII(5, Alexei, updatePosition, CarIndex, Position)
	Entity::updatePosition(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SI(6, Alexei, enterExitCompartment, ObjectIndex)
	Entity::enterExitCompartment(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(7, Alexei, callbackActionOnDirection)
	Entity::callbackActionOnDirection(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SIIS(8, Alexei, callSavepoint, EntityIndex, ActionIndex)
	Entity::callSavepoint(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(9, Alexei, savegame, SavegameType, uint32)
	Entity::savegame(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(10, Alexei, updateEntity, CarIndex, EntityPosition)
	switch (savepoint.action) {
	default:
		break;

	case kActionExcuseMeCath:
		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 18) || getEntities()->isPlayerPosition(kCarRedSleeping, 18)) {
			getSound()->excuseMe(kEntityAlexei);
		} else {
			if (getEvent(kEventAlexeiSalonVassili) || (getEvent(kEventTatianaAskMatchSpeakRussian) && getInventory()->hasItem(kItemPassengerList))) {
				getSound()->playSound(kEntityPlayer, rnd(2) ? "CAT1012" : "CAT1012A");
			} else {
				getSound()->excuseMeCath();
			}
		}
		// Stop execution here
		return;

	case kActionDefault:
		getData()->inventoryItem = kItemNone;
		break;
	}

	Entity::updateEntity(savepoint, true);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_NOSETUP(11, Alexei, draw2)
	Entity::draw2(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(12, Alexei, callbackActionRestaurantOrSalon)
	Entity::callbackActionRestaurantOrSalon(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(13, Alexei, enterComparment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_updateEntity(kCarGreenSleeping, kPosition_7500);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSavePoints()->push(kEntityAlexei, kEntityMertens, kAction302614416);
			getEntities()->drawSequenceLeft(kEntityAlexei, "602DB");
			getEntities()->enterCompartment(kEntityAlexei, kObjectCompartment2, true);

			getData()->location = kLocationInsideCompartment;

			if (getEntities()->isInsideCompartment(kEntityPlayer, kCarGreenSleeping, kPosition_7500)) {
				getAction()->playAnimation(isNight() ? kEventCathTurningNight : kEventCathTurningDay);
				getSound()->playSound(kEntityPlayer, "BUMP");
				getScenes()->loadSceneFromObject(kObjectCompartment2, true);
			}
			break;

		case 2:
			getEntities()->exitCompartment(kEntityAlexei, kObjectCompartment2, true);
			getData()->location = kLocationInsideCompartment;
			getData()->entityPosition = kPosition_7500;
			getEntities()->clearSequences(kEntityAlexei);

			callbackAction();
			break;
		}
		break;

	case kAction135664192:
		setCallback(2);
		setup_enterExitCompartment("602Eb", kObjectCompartment2);
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(14, Alexei, exitCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterExitCompartment("602Fb", kObjectCompartment2);
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getData()->location = kLocationOutsideCompartment;
			getSavePoints()->push(kEntityAlexei, kEntityMertens, kAction302614416);
			getEntities()->drawSequenceLeft(kEntityAlexei, "602DB");
			getEntities()->enterCompartment(kEntityAlexei, kObjectCompartment2, true);
		}
		break;

	case kAction135664192:
		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getEntities()->exitCompartment(kEntityAlexei, kObjectCompartment2, true);

		callbackAction();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(15, Alexei, pacingAtWindow)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (Entity::updateParameterCheck(params->param2, getState()->time, params->param1)) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				getData()->location = kLocationOutsideCompartment;

				setCallback(3);
				setup_updatePosition("103D", kCarRestaurant, 52);
			}
		}
		break;

	case kActionDefault:
		params->param1 = 5 * (3 * rnd(60) + 90);

		setCallback(1);
		setup_callbackActionRestaurantOrSalon();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;

			setCallback(2);
			setup_updatePosition("103C", kCarRestaurant, 52);
			break;

		case 2:
			getData()->location = kLocationInsideCompartment;
			getEntities()->drawSequenceLeft(kEntityAlexei, "103E");
			break;

		case 3:
			getData()->location = kLocationInsideCompartment;
			getEntities()->drawSequenceLeft(kEntityAlexei, "103B");

			callbackAction();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_IS(16, Alexei, compartmentLogic, TimeValue)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param7 && params->param1 < getState()->time && !params->param8) {
			params->param8 = 1;

			getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

			callbackAction();
			break;
		}

		if (params->param5) {
			if (!Entity::updateParameter(CURRENT_PARAM(1, 1), getState()->timeTicks, 75))
				break;

			params->param5 = 0;
			params->param6 = 1;

			getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorNormal, kCursorNormal);
		}

		CURRENT_PARAM(1, 1) = 0;
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorNormal, kCursorNormal);

		if (params->param5) {
			if (savepoint.param.intValue == 18) {
				setCallback(4);
				setup_playSound(getSound()->justAMinuteCath());
				break;
			}

			if (getInventory()->hasItem(kItemPassengerList)) {
				setCallback(5);
				setup_playSound(rnd(2) ? getSound()->wrongDoorCath() : "CAT1503");
			} else {
				setCallback(6);
				setup_playSound(getSound()->wrongDoorCath());
			}
		} else {
			setCallback(savepoint.action == kActionKnock ? 1 : 2);
			setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		}
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAlexei, (char *)&params->seq);
		getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);
		break;

	case kActionDrawScene:
		if (params->param6 || params->param5) {
			getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);

			params->param5 = 0;
			params->param6 = 0;
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
		case 2:
			setCallback(3);
			setup_playSound("ALX1134A");
			break;

		case 3:
			getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorTalk, kCursorNormal);
			getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param5 = 1;
			break;

		case 4:
		case 5:
		case 6:
			params->param5 = 0;
			params->param6 = 1;
			break;

		case 7:
			setCallback(8);
			setup_updateFromTime(300);
			break;

		case 8:
			setCallback(9);
			setup_enterExitCompartment("602Gb", kObjectCompartment2);
			break;

		case 9:
			getData()->location = kLocationOutsideCompartment;
			getSavePoints()->push(kEntityAlexei, kEntityMertens, kAction156567128);
			getEntities()->drawSequenceLeft(kEntityAlexei, "602Hb");
			getEntities()->enterCompartment(kEntityAlexei, kObjectCompartment2, true);
			break;

		case 10:
			getEntities()->exitCompartment(kEntityAlexei, kObjectCompartment2, true);

			getData()->location = kLocationInsideCompartment;
			getData()->entityPosition = kPosition_7500;

			getEntities()->drawSequenceLeft(kEntityAlexei, (char *)&params->seq);
			getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);

			params->param7 = 0;
			break;
		}
		break;

	case kAction124697504:
		setCallback(10);
		setup_enterExitCompartment("602Ib", kObjectCompartment2);
		break;

	case kAction221617184:
		params->param7 = 1;
		getSavePoints()->push(kEntityAlexei, kEntityMertens, kAction100906246);

		setCallback(7);
		setup_playSound("CON1024");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(17, Alexei, chapter1)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		Entity::timeCheck(kTimeChapter1, params->param1, WRAP_SETUP_FUNCTION(Alexei, setup_atDinner));
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->entityPosition = kPosition_3969;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRestaurant;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(18, Alexei, atDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime1089000 && getEntities()->isSomebodyInsideRestaurantOrSalon()) {
			params->param2 = kItemNone;

			getData()->location = kLocationOutsideCompartment;
			getData()->inventoryItem = kItemNone;

			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 63);
			getInventory()->setLocationAndProcess(kItem17, kObjectLocation1);

			setCallback(1);
			setup_callSavepoint("005D", kEntityTables1, kActionDrawTablesWithChairs, "005E");
			break;
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param3, getState()->timeTicks, 90))
				break;

			getScenes()->loadSceneFromPosition(kCarRestaurant, 61);
		} else {
			params->param3 = 0;
		}
		break;

	case kAction1:
		params->param2 = kItemNone;
		getData()->inventoryItem = kItemNone;

		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventAlexeiDiner);
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAlexei, kEntityTables1, kAction136455232);
		getEntities()->drawSequenceLeft(kEntityAlexei, "005B");

		params->param2 = kItemInvalid;
		getData()->inventoryItem = kItemInvalid;
		break;

	case kActionDrawScene:
		params->param1 = getEntities()->isPlayerPosition(kCarRestaurant, 63) ? 1 : 0;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 63);
			setup_returnCompartment();
			break;

		case 2:
			getAction()->playAnimation(getProgress().jacket == kJacketGreen ? kEventAlexeiDiner : kEventAlexeiDinerOriginalJacket);
			getSavePoints()->push(kEntityAlexei, kEntityTables1, kActionDrawTablesWithChairs, "005E");

			getData()->entityPosition = kPosition_3650;
			getData()->location = kLocationOutsideCompartment;

			getEntities()->clearSequences(kEntityAlexei);
			getInventory()->get(kItem17)->location = kObjectLocation1;
			getScenes()->loadSceneFromPosition(kCarRestaurant, 63);

			setup_returnCompartment();
			break;
		}
		break;

	case kAction168046720:
		getData()->inventoryItem = kItemNone;
		break;

	case kAction168627977:
		getData()->inventoryItem = (InventoryItem)LOW_BYTE(params->param2);
		break;

	case kAction225182640:
		getData()->inventoryItem = kItemNone;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(19, Alexei, returnCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_draw("811DS");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_updateEntity(kCarGreenSleeping, kPosition_9460);
			break;

		case 2:
			setCallback(3);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 3:
			setCallback(4);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 4:
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(5);
			setup_draw("811US");
			break;

		case 5:
			setCallback(6);
			setup_draw("933");
			break;

		case 6:
			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 63);
			getScenes()->loadSceneFromItemPosition(kItem17);
			getSavePoints()->push(kEntityAlexei, kEntityTables1, kAction136455232);

			setCallback(7);
			setup_callSavepoint("005F", kEntityTables1, kActionDrawTablesWithChairs, "005G");
			break;

		case 7:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 63);
			getSavePoints()->push(kEntityAlexei, kEntityWaiter2, kAction302996448);

			setCallback(8);
			setup_draw("934");
			break;

		case 8:
			setCallback(9);
			setup_draw("811DS");
			break;

		case 9:
			setCallback(10);
			setup_enterComparment();
			break;

		case 10:
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			setCallback(11);
			setup_compartmentLogic(kTime1098000, "411");
			break;

		case 11:
			setup_goSalon();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(20, Alexei, goSalon)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_exitCompartment();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 2:
			setCallback(3);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 3:
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(4);
			setup_updatePosition("103A", kCarRestaurant, 52);
			break;

		case 4:
			getData()->location = kLocationInsideCompartment;
			setup_sitting();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(21, Alexei, sitting)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (Entity::updateParameterCheck(params->param2, getState()->time, params->param1) && getEntities()->isSomebodyInsideRestaurantOrSalon()) {
			getData()->location = kLocationOutsideCompartment;
			getData()->inventoryItem = kItemNone;

			setCallback(1);
			setup_updatePosition("103C", kCarRestaurant, 52);
		}
		break;

	case kAction1:
		getData()->inventoryItem = kItemNone;

		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventAlexeiSalonPoem);
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAlexei, "103B");
		params->param1 = 225 * (4 * rnd(3) + 4);

		if (!getEvent(kEventAlexeiSalonPoem))
			getData()->inventoryItem = kItemParchemin;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationInsideCompartment;
			setup_standingAtWindow();
			break;

		case 2:
			getAction()->playAnimation(kEventAlexeiSalonPoem);
			getData()->location = kLocationOutsideCompartment;

			getEntities()->drawSequenceRight(kEntityAlexei, "103D");
			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);
			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 52);

			setCallback(3);
			setup_callbackActionOnDirection();
			break;

		case 3:
			getEntities()->drawSequenceLeft(kEntityAlexei, "103B");
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 52);
			getData()->location = kLocationInsideCompartment;
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(22, Alexei, standingAtWindow)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (Entity::updateParameterCheck(params->param2, getState()->time, params->param1)) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				getData()->location = kLocationOutsideCompartment;
				getData()->inventoryItem = kItemNone;

				setCallback(1);
				setup_updatePosition("103D", kCarRestaurant, 52);
				break;
			}
		}

		if (params->param3 == kTimeInvalid || getState()->time <= kTime1111500)
			break;

		if (getState()->time > kTime1138500) {
			params->param3 = kTimeInvalid;
		} else {
			if ((!getEntities()->isInSalon(kEntityPlayer) && !getEntities()->isInRestaurant(kEntityPlayer)) || !params->param3)
				params->param3 = (uint)getState()->time;

			if (params->param3 >= getState()->time)
				break;

			params->param3 = kTimeInvalid;
		}

		getData()->inventoryItem = kItemNone;

		setup_waitingForTatiana();
		break;

	case kAction1:
		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventAlexeiSalonPoem);
		break;

	case kActionDefault:
		params->param1 = 225 * (4 * rnd(4) + 8);
		getEntities()->drawSequenceLeft(kEntityAlexei, "103E");
		if (!getEvent(kEventAlexeiSalonPoem))
			getData()->inventoryItem = kItemParchemin;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationInsideCompartment;
			setup_sitting();
			break;

		case 2:
			getAction()->playAnimation(kEventAlexeiSalonPoem);
			getData()->inventoryItem = kItemNone;
			getData()->location = kLocationOutsideCompartment;

			getEntities()->drawSequenceRight(kEntityAlexei, "103D");
			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 52);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);

			setCallback(3);
			setup_callbackActionOnDirection();
			break;

		case 3:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 52);
			getData()->location = kLocationInsideCompartment;

			setup_sitting();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(23, Alexei, waitingForTatiana)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		getData()->inventoryItem = (!getEntities()->isInRestaurant(kEntityTatiana) || getEvent(kEventAlexeiSalonPoem)) ? kItemNone : kItemParchemin;
		break;

	case kAction1:
		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventAlexeiSalonPoem);
		break;

	case kActionDefault:
		getData()->location = kLocationInsideCompartment;
		getSavePoints()->push(kEntityAlexei, kEntityTatiana, kAction124973510);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventAlexeiSalonVassili);

			getData()->location = kLocationOutsideCompartment;

			getEntities()->drawSequenceLeft(kEntityAlexei, "103F");
			getScenes()->processScene();

			setup_upset();
			break;

		case 2:
			getAction()->playAnimation(kEventAlexeiSalonPoem);

			getData()->inventoryItem = kItemNone;

			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);
			break;
		}
		break;

	case kAction157159392:
		if (getEntities()->isInSalon(kEntityPlayer)) {
			setCallback(1);
			setup_savegame(kSavegameTypeEvent, kEventAlexeiSalonVassili);
		} else {
			setup_upset();
		}
		break;

	case kAction188784532:
		setup_upset();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(24, Alexei, upset)
	switch (savepoint.action) {
	default:
		break;

	case kAction1:
		getData()->inventoryItem = kItemNone;
		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAlexeiSalonCath);
		break;

	case kActionDefault:
		if (getEvent(kEventAlexeiSalonVassili))
			getData()->inventoryItem = kItemInvalid;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventAlexeiSalonCath);
			getData()->car = kCarRedSleeping;
			getData()->entityPosition = kPosition_9460;
			getEntities()->clearSequences(kEntityAlexei);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);
			setup_returnCompartmentNight();
			break;

		case 2:
			setup_returnCompartmentNight();
			break;
		}
		break;

	case kAction135854208:
		getData()->inventoryItem = kItemNone;
		setCallback(2);
		setup_draw("103G");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(25, Alexei, returnCompartmentNight)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterComparment();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			setCallback(2);
			setup_compartmentLogic(kTime1179000, "411");
			break;

		case 2:
			setCallback(3);
			setup_compartmentLogic(kTime1323000, "412");
			break;

		case 3:
			setup_function26();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(26, Alexei, function26)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		Entity::timeCheck(kTime1512000, params->param1, WRAP_SETUP_FUNCTION(Alexei, setup_function27));
		break;

	case kActionDefault:
		getData()->entityPosition = kPosition_7500;
		getData()->car = kCarGreenSleeping;
		getData()->location = kLocationInsideCompartment;

		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);

		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
			getScenes()->loadSceneFromPosition(kCarGreenSleeping, 66);

		getEntities()->clearSequences(kEntityAlexei);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(27, Alexei, function27)
	if (savepoint.action == kActionDefault) {
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 66))
			getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

		getEntities()->drawSequenceLeft(kEntityAlexei, "412");
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(28, Alexei, chapter2)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_inCompartment2();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAlexei);

		getObjects()->update(kObjectCompartment2, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityAlexei, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->entityPosition = kPosition_7500;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarGreenSleeping;
		getData()->clothes = kClothesDefault;
		getData()->inventoryItem = kItemNone;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(29, Alexei, inCompartment2)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_compartmentLogic(kTime1791000, "411");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_exitCompartment();
			break;

		case 2:
			setCallback(3);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 3:
			setCallback(4);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 4:
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(5);
			setup_draw("811US");
			break;

		case 5:
			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 63);

			setCallback(6);
			setup_callSavepoint("018B", kEntityTables1, kAction136455232, "BOGUS");
			break;

		case 6:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 63);
			getSavePoints()->push(kEntityAlexei, kEntityTatiana, kAction290869168);
			setup_atBreakfast();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(30, Alexei, atBreakfast)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getData()->car = kCarRestaurant;
		getData()->location = kLocationInsideCompartment;

		getEntities()->drawSequenceLeft(kEntityAlexei, "018C");
		getSavePoints()->push(kEntityAlexei, kEntityTables1, kAction136455232);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 63);
			getSavePoints()->push(kEntityAlexei, kEntityTatiana, kAction156444784);
			getEntities()->drawSequenceLeft(kEntityAlexei, "018E");

			if (getEntities()->isInRestaurant(kEntityPlayer))
				getProgress().field_68 = 1;

			setCallback(2);
			setup_playSound("TAT2116");
			break;

		case 2:
			getSound()->playSound(kEntityAlexei, "TAT2116A");
			getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 63);

			setCallback(3);
			setup_callSavepoint("018F", kEntityTatiana, kAction123857088, "BOGUS");
			break;

		case 3:
			getEntities()->updatePositionExit(kEntityAlexei, kCarRestaurant, 63);
			setup_returnCompartment2();
			break;
		}
		break;

	case kAction236053296:
		getEntities()->drawSequenceRight(kEntityAlexei, "018D1");
		getEntities()->drawSequenceRight(kEntityTatiana, "018D2");
		getEntities()->updatePositionEnter(kEntityAlexei, kCarRestaurant, 63);

		if (savepoint.param.intValue)
			getScenes()->loadSceneFromPosition(kCarRestaurant, (Position)savepoint.param.intValue);

		setCallback(1);
		setup_callbackActionOnDirection();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(31, Alexei, returnCompartment2)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityAlexei, "811DS");
		if (getEntities()->isInRestaurant(kEntityPlayer))
			getEntities()->updateFrame(kEntityAlexei);

		setCallback(1);
		setup_callbackActionOnDirection();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterComparment();
			break;

		case 2:
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			setCallback(3);
			setup_compartmentLogic(kTimeEnd, "411");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(32, Alexei, chapter3)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_playingChess();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAlexei);

		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRestaurant;
		getData()->clothes = kClothesDefault;
		getData()->inventoryItem = kItemNone;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(33, Alexei, playingChess)
	switch (savepoint.action) {
	default:
		break;

	case kActionCallback:
		if (getCallback() == 1)
			setup_inPart3();
		break;

	case kAction122288808:
		getData()->entityPosition = kPosition_9270;
		getData()->location = kLocationOutsideCompartment;
		getData()->car = kCarRedSleeping;

		setCallback(1);
		setup_enterComparment();
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAlexei, "BLANK");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(34, Alexei, inPart3)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
			getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

		setCallback(1);
		setup_compartmentLogic(kTime2083500, "411");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_exitCompartment();
			break;

		case 2:
			setCallback(3);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 3:
			setCallback(4);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 4:
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(5);
			setup_updatePosition("103A", kCarRestaurant, 52);
			break;

		case 5:
			setCallback(6);
			setup_pacing3();
			break;

		case 6:
			setCallback(7);
			setup_enterComparment();
			break;

		case 7:
			getObjects()->update(kObject10, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 61))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 66);

			setCallback(8);
			setup_compartmentLogic(kTime2124000, "NONE");
			break;

		case 8:
			setCallback(9);
			setup_exitCompartment();
			break;

		case 9:
			setCallback(10);
			setup_goSalon3();
			break;

		case 10:
			getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 66))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			setCallback(11);
			setup_compartmentLogic(kTime16451100, "411");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(35, Alexei, pacing3)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getEntities()->isInSalon(kEntityPlayer)) {
			if (Entity::updateParameterCheck(params->param2, getState()->time, 2700)) {
				setCallback(1);
				setup_callbackActionRestaurantOrSalon();
				break;
			}
		} else {
			params->param2 = 0;
		}

		if (Entity::updateParameterCheck(params->param3, getState()->time, params->param1)) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				setCallback(3);
				setup_pacingAtWindow();
				break;
			}
		}

label_callback_3:
		if (!Entity::updateParameter(params->param4, getState()->time, 9000))
			break;

		setCallback(4);
		setup_callbackActionRestaurantOrSalon();
		break;

	case kActionDefault:
		params->param1 = 15 * rnd(120);
		getEntities()->drawSequenceLeft(kEntityAlexei, "103B");
		getData()->location = kLocationInsideCompartment;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
		case 4:
			getData()->location = kLocationOutsideCompartment;

			setCallback(getCallback() + 1);
			setup_updatePosition("124C", kCarRestaurant, 52);
			break;

		case 2:
		case 5:
			callbackAction();
			break;

		case 3:
			params->param1 = 15 * rnd(120);
			params->param3 = 0;
			goto label_callback_3;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(36, Alexei, goSalon3)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param3 || params->param2)
			break;

		if (!Entity::updateParameter(params->param4, getState()->timeTicks, params->param1))
			break;

		getEntities()->drawSequenceRight(kEntityAlexei, "124B");

		params->param2 = 1;
		params->param4 = 0;
		break;

	case kActionExitCompartment:
		if (params->param2) {
			getEntities()->drawSequenceLeft(kEntityAlexei, "124A");
			params->param1 = 5 * (3 * rnd(15) + 15);
			params->param2 = 0;
		}
		break;

	case kActionDefault:
		params->param1 = 5 * (3 * rnd(15) + 15);

		setCallback(1);
		setup_updateEntity(kCarRestaurant, kPosition_850);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 2:
			getSavePoints()->push(kEntityAlexei, kEntityAbbot, kAction222609266);
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(3);
			setup_updatePosition("103A", kCarRestaurant, 52);
			break;

		case 3:
			getData()->location = kLocationInsideCompartment;
			getEntities()->drawSequenceLeft(kEntityAlexei, "124A");
			break;

		case 4:
			callbackAction();
			break;
		}
		break;

	case kAction122288808:
		setCallback(4);
		setup_enterComparment();
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAlexei, "BLANK");
		params->param3 = 1;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(37, Alexei, chapter4)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_inCompartment4();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAlexei);

		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject10, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->entityPosition = kPosition_7500;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarGreenSleeping;
		getData()->inventoryItem = kItemNone;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(38, Alexei, inCompartment4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_compartmentLogic(kTime2354400, "411");
		break;

	case kActionCallback:
		if (getCallback() == 1)
			setup_meetTatiana();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(39, Alexei, meetTatiana)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param2)
			break;

		if (!params->param4) {
			params->param3 = (uint)getState()->time + 4500;
			params->param4 = (uint)getState()->time + 9000;
		}

		if (params->param5 != kTimeInvalid && params->param3 < getState()->time) {

			if (params->param4 >= getState()->time) {
				if (getEntities()->isInGreenCarEntrance(kEntityPlayer) || !params->param5)
					params->param5 = (uint)getState()->time;

				if (params->param5 >= getState()->time)
					break;
			}

			params->param5 = kTimeInvalid;

			getEntities()->updatePositionExit(kEntityAlexei, kCarGreenSleeping, 70);
			getEntities()->updatePositionExit(kEntityAlexei, kCarGreenSleeping, 71);

			if (getEntities()->isInGreenCarEntrance(kEntityPlayer)) {
				getSound()->excuseMe(kEntityAlexei);

				if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62))
					getScenes()->loadSceneFromPosition(kCarGreenSleeping, 72);
			}

			setup_leavePlatform();
		}
		break;

	case kActionExitCompartment:
		if (!params->param1 && !params->param2)
			getEntities()->drawSequenceLeft(kEntityAlexei, "306F");
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterExitCompartment("602FB", kObjectCompartment2);
		break;

	case kActionDrawScene:
		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62)) {
			if (params->param1) {
				if (!params->param2)
					break;
			} else if (!params->param2) {
				getEntities()->drawSequenceRight(kEntityAlexei, "306A");
				break;
			}

			setup_leavePlatform();
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
			getData()->location = kLocationOutsideCompartment;

			setCallback(2);
			setup_updateEntity(kCarGreenSleeping, kPosition_540);
			break;

		case 2:
			getEntities()->clearSequences(kEntityAlexei);

			if (getEntities()->isInGreenCarEntrance(kEntityPlayer)) {
				getSound()->excuseMe(kEntityAlexei);

				if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62))
					getScenes()->loadSceneFromPosition(kCarGreenSleeping, 72);
			}

			getEntities()->updatePositionEnter(kEntityAlexei, kCarGreenSleeping, 70);
			getEntities()->updatePositionEnter(kEntityAlexei, kCarGreenSleeping, 71);
			break;
		}
		break;

	case kAction123536024:
		params->param2 = 1;
		break;

	case kAction123712592:
		getEntities()->clearSequences(kEntityAlexei);
		params->param1 = 1;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(40, Alexei, leavePlatform)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_updateEntity(kCarGreenSleeping, kPosition_7500);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceRight(kEntityAlexei, "602Eb");
			getEntities()->enterCompartment(kEntityAlexei, kObjectCompartment2);

			getData()->location = kLocationInsideCompartment;

			if (getEntities()->isInsideCompartment(kEntityPlayer, kCarGreenSleeping, kPosition_7500)) {
				getAction()->playAnimation(isNight() ? kEventCathTurningNight : kEventCathTurningDay);
				getSound()->playSound(kEntityPlayer, "BUMP");
				getScenes()->loadSceneFromObject(kObjectCompartment2);
			}

			setCallback(2);
			setup_callbackActionOnDirection();
			break;

		case 2:
			getEntities()->exitCompartment(kEntityAlexei, kObjectCompartment2);
			getData()->entityPosition = kPosition_7500;
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityAlexei);

			setup_inCompartmentAgain();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(41, Alexei, inCompartmentAgain)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 66))
			getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

		setCallback(1);
		setup_compartmentLogic(kTime2403000, "411");
		break;

	case kActionCallback:
		if (getCallback() == 1)
			setup_goSalon4();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(42, Alexei, goSalon4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_exitCompartment();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSavePoints()->push(kEntityAlexei, kEntityTatiana, kAction191198209);

			setCallback(2);
			setup_updateEntity(kCarRestaurant, kPosition_850);
			break;

		case 2:
			setCallback(3);
			setup_updatePosition("103A", kCarRestaurant, 52);
			break;

		case 3:
			getData()->location = kLocationInsideCompartment;
			setup_pacing();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(43, Alexei, pacing)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time < kTime1806300 && Entity::updateParameterCheck(params->param2, getState()->time, params->param1)) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				setCallback(1);
				setup_pacingAtWindow();
				break;
			}
		}

label_callback_1:
		if (getState()->time > kTime2457000 && !params->param3) {
			params->param3 = 1;

			setCallback(2);
			setup_callbackActionRestaurantOrSalon();
		}
		break;

	case kActionDefault:
		params->param1 = 5 * (3 * rnd(120) + 180);
		getEntities()->drawSequenceLeft(kEntityAlexei, "103B");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			params->param1 = 5 * (3 * rnd(120) + 180);
			params->param2 = 0;
			goto label_callback_1;

		case 2:
			getData()->location = kLocationOutsideCompartment;

			setCallback(3);
			setup_updatePosition("124C", kCarRestaurant, 52);
			break;

		case 3:
			setup_goToPlatform();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(44, Alexei, goToPlatform)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime2475000 && !params->param1) {
			params->param1 = 1;

			getEntities()->updatePositionExit(kEntityAlexei, kCarGreenSleeping, 70);
			getEntities()->updatePositionExit(kEntityAlexei, kCarGreenSleeping, 71);

			if (getEntities()->isInGreenCarEntrance(kEntityPlayer)) {
				getSound()->excuseMe(kEntityAlexei);

				if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62))
					getScenes()->loadSceneFromPosition(kCarGreenSleeping, 72);

			}
			setup_returnCompartment4();
		}
		break;

	case kActionDefault:
		getData()->car = kCarRedSleeping;
		getData()->location = kLocationOutsideCompartment;
		getData()->entityPosition = kPosition_9460;

		setCallback(1);
		setup_updateEntity(kCarGreenSleeping, kPosition_540);
		break;

	case kActionDrawScene:
		if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62)) {
			setCallback(2);
			setup_draw("306A");
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->clearSequences(kEntityAlexei);

			if (getEntities()->isInGreenCarEntrance(kEntityPlayer)) {
				getSound()->excuseMe(kEntityAlexei);

				if (getEntities()->isPlayerPosition(kCarGreenSleeping, 62))
					getScenes()->loadSceneFromPosition(kCarGreenSleeping, 72);
			}

			getEntities()->updatePositionEnter(kEntityAlexei, kCarGreenSleeping, 70);
			getEntities()->updatePositionEnter(kEntityAlexei, kCarGreenSleeping, 71);
			break;

		case 2:
			getEntities()->drawSequenceLeft(kEntityAlexei, "306F");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(45, Alexei, returnCompartment4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterComparment();
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 66))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			if (getInventory()->hasItem(kItemBomb)) {
				setup_bombPlanB();
			} else {
				setCallback(2);
				setup_compartmentLogic(kTimeEnd, "412");
			}
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(46, Alexei, bombPlanB)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1 == kTimeInvalid)
			break;

		if (getState()->time <= kTime2493000) {

			if (getEntities()->isInSalon(kEntityPlayer) || getEntities()->isInSalon(kEntityAugust) || !params->param1)
				params->param1 = (uint)getState()->time;

			if (params->param1 >= getState()->time)
				break;
		}

		params->param1 = kTimeInvalid;

		getScenes()->loadSceneFromItemPosition(kItem22);

		if (getEntities()->isInSalon(kEntityPlayer)) {
			getSound()->excuseMe(kEntityAlexei);

			getScenes()->loadSceneFromPosition(kCarRestaurant, getScenes()->get(getState()->scene)->position);
		}

		setCallback(4);
		setup_enterComparment();
		break;

	case kActionDefault:
		setCallback(1);
		setup_compartmentLogic(kTime2488500, "411");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_exitCompartment();
			break;

		case 2:
			setCallback(3);
			setup_updateEntity(kCarRedSleeping, kPosition_9460);
			break;

		case 4:
			if (getEntities()->isPlayerPosition(kCarGreenSleeping, 66))
				getScenes()->loadSceneFromPosition(kCarGreenSleeping, 49);

			setCallback(5);
			setup_compartmentLogic(kTime2507400, "412");
			break;

		case 5:
			setCallback(6);
			setup_enterExitCompartment("602Fb", kObjectCompartment2);
			break;

		case 6:
			getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
			getData()->location = kLocationOutsideCompartment;

			setCallback(7);
			setup_updateEntity(kCarRedSleeping, kPosition_7500);
			break;

		case 7:
			getEntities()->drawSequenceRight(kEntityAlexei, "602Eb");
			getEntities()->enterCompartment(kEntityAlexei, kObjectCompartmentB);
			getData()->location = kLocationInsideCompartment;

			if (getEntities()->checkFields19(kEntityPlayer, kCarRedSleeping, kPosition_7850)) {
				getAction()->playAnimation(isNight() ? kEventCathTurningNight : kEventCathTurningDay);
				getSound()->playSound(kEntityPlayer, "BUMP");
				getScenes()->loadSceneFromObject(kObjectCompartmentB);
			}

			setCallback(8);
			setup_callbackActionOnDirection();
			break;

		case 8:
			getEntities()->exitCompartment(kEntityAlexei, kObjectCompartmentB);
			getEntities()->clearSequences(kEntityAlexei);
			getData()->entityPosition = kPosition_8200;
			getData()->location = kLocationInsideCompartment;
			getObjects()->update(kObjectCompartmentA, kEntityPlayer, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject48, kEntityPlayer, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(9);
			setup_playSound("TAT4167");
			break;

		case 9:
			getSavePoints()->push(kEntityAlexei, kEntityChapters, kAction156435676);
			setup_function47();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(47, Alexei, function47)
	if (savepoint.action == kActionDefault) {
		getEntities()->clearSequences(kEntityAlexei);

		getData()->entityPosition = kPositionNone;
		getData()->location = kLocationOutsideCompartment;
		getData()->car = kCarLocomotive;

		getObjects()->update(kObjectCompartment2, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectHandleInsideBathroom, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(48, Alexei, chapter5)
	if (savepoint.action == kActionDefault)
		getEntities()->clearSequences(kEntityAlexei);
IMPLEMENT_FUNCTION_END

} // End of namespace LastExpress
