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

#include "lastexpress/entities/anna.h"

#include "lastexpress/entities/vesna.h"

#include "lastexpress/fight/fight.h"

#include "lastexpress/game/action.h"
#include "lastexpress/game/entities.h"
#include "lastexpress/game/inventory.h"
#include "lastexpress/game/logic.h"
#include "lastexpress/game/object.h"
#include "lastexpress/game/savepoint.h"
#include "lastexpress/game/scenes.h"
#include "lastexpress/game/state.h"

#include "lastexpress/sound/queue.h"

#include "lastexpress/lastexpress.h"

namespace LastExpress {

Anna::Anna(LastExpressEngine *engine) : Entity(engine, kEntityAnna) {
	ADD_CALLBACK_FUNCTION(Anna, reset);
	ADD_CALLBACK_FUNCTION_S(Anna, draw);
	ADD_CALLBACK_FUNCTION_SII(Anna, updatePosition);
	ADD_CALLBACK_FUNCTION_SI(Anna, enterExitCompartment);
	ADD_CALLBACK_FUNCTION(Anna, callbackActionOnDirection);
	ADD_CALLBACK_FUNCTION_SIIS(Anna, callSavepoint);
	ADD_CALLBACK_FUNCTION_S(Anna, playSound);
	ADD_CALLBACK_FUNCTION(Anna, callbackActionRestaurantOrSalon);
	ADD_CALLBACK_FUNCTION_II(Anna, savegame);
	ADD_CALLBACK_FUNCTION_II(Anna, updateEntity);
	ADD_CALLBACK_FUNCTION_I(Anna, updateFromTime);
	ADD_CALLBACK_FUNCTION(Anna, practiceMusic);
	ADD_CALLBACK_FUNCTION_SSI(Anna, draw2);
	ADD_CALLBACK_FUNCTION_I(Anna, updateFromTicks);
	ADD_CALLBACK_FUNCTION_IS(Anna, compartmentLogic);
	ADD_CALLBACK_FUNCTION(Anna, chapter1);
	ADD_CALLBACK_FUNCTION_II(Anna, doWalkP1);
	ADD_CALLBACK_FUNCTION_I(Anna, diningLogic);
	ADD_CALLBACK_FUNCTION(Anna, fleeTyler);
	ADD_CALLBACK_FUNCTION(Anna, waitDinner);
	ADD_CALLBACK_FUNCTION(Anna, goDinner);
	ADD_CALLBACK_FUNCTION(Anna, function22);
	ADD_CALLBACK_FUNCTION(Anna, waitingDinner);
	ADD_CALLBACK_FUNCTION(Anna, waitingDinner2);
	ADD_CALLBACK_FUNCTION(Anna, eatingDinner);
	ADD_CALLBACK_FUNCTION(Anna, leaveDinner);
	ADD_CALLBACK_FUNCTION(Anna, freshenUp);
	ADD_CALLBACK_FUNCTION(Anna, goSalon);
	ADD_CALLBACK_FUNCTION(Anna, waitAugust);
	ADD_CALLBACK_FUNCTION(Anna, function30);
	ADD_CALLBACK_FUNCTION(Anna, leaveAugust);
	ADD_CALLBACK_FUNCTION(Anna, returnCompartment);
	ADD_CALLBACK_FUNCTION(Anna, readyForBed);
	ADD_CALLBACK_FUNCTION(Anna, asleep);
	ADD_CALLBACK_FUNCTION(Anna, wakeNight);
	ADD_CALLBACK_FUNCTION(Anna, goVassili);
	ADD_CALLBACK_FUNCTION(Anna, function37);
	ADD_CALLBACK_FUNCTION(Anna, speakTatiana);
	ADD_CALLBACK_FUNCTION_II(Anna, doWalk1019);
	ADD_CALLBACK_FUNCTION(Anna, leaveTatiana);
	ADD_CALLBACK_FUNCTION(Anna, goBackToSleep);
	ADD_CALLBACK_FUNCTION(Anna, chapter2);
	ADD_CALLBACK_FUNCTION(Anna, inPart2);
	ADD_CALLBACK_FUNCTION(Anna, chapter3);
	ADD_CALLBACK_FUNCTION_I(Anna, exitCompartment);
	ADD_CALLBACK_FUNCTION(Anna, practicing);
	ADD_CALLBACK_FUNCTION(Anna, goLunch);
	ADD_CALLBACK_FUNCTION(Anna, lunch);
	ADD_CALLBACK_FUNCTION(Anna, leaveTableWithAugust);
	ADD_CALLBACK_FUNCTION(Anna, leaveLunch);
	ADD_CALLBACK_FUNCTION(Anna, afterLunch);
	ADD_CALLBACK_FUNCTION(Anna, returnCompartment3);
	ADD_CALLBACK_FUNCTION(Anna, dressing);
	ADD_CALLBACK_FUNCTION(Anna, giveMaxToConductor2);
	ADD_CALLBACK_FUNCTION(Anna, goConcert);
	ADD_CALLBACK_FUNCTION(Anna, concert);
	ADD_CALLBACK_FUNCTION(Anna, leaveConcert);
	ADD_CALLBACK_FUNCTION(Anna, leaveConcertCathInCompartment);
	ADD_CALLBACK_FUNCTION(Anna, afterConcert);
	ADD_CALLBACK_FUNCTION(Anna, giveMaxBack);
	ADD_CALLBACK_FUNCTION(Anna, goBaggageCompartment);
	ADD_CALLBACK_FUNCTION(Anna, function62);
	ADD_CALLBACK_FUNCTION(Anna, deadBaggageCompartment);
	ADD_CALLBACK_FUNCTION(Anna, baggageFight);
	ADD_CALLBACK_FUNCTION(Anna, prepareVienna);
	ADD_CALLBACK_FUNCTION(Anna, chapter4);
	ADD_CALLBACK_FUNCTION(Anna, reading);
	ADD_CALLBACK_FUNCTION(Anna, sulking);
	ADD_CALLBACK_FUNCTION(Anna, goSalon4);
	ADD_CALLBACK_FUNCTION(Anna, returnCompartment4);
	ADD_CALLBACK_FUNCTION(Anna, enterCompartmentCathFollowsAnna);
	ADD_CALLBACK_FUNCTION_II(Anna, doWalkCathFollowsAnna);
	ADD_CALLBACK_FUNCTION(Anna, letDownHair);
	ADD_CALLBACK_FUNCTION(Anna, chapter5);
	ADD_CALLBACK_FUNCTION(Anna, tiedUp);
	ADD_CALLBACK_FUNCTION(Anna, function76);
	ADD_CALLBACK_FUNCTION(Anna, readyToScore);
	ADD_CALLBACK_FUNCTION(Anna, kidnapped);
	ADD_CALLBACK_FUNCTION(Anna, waiting);
	ADD_CALLBACK_FUNCTION(Anna, finalSequence);
	ADD_CALLBACK_FUNCTION(Anna, openFirebird);
}

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(1, Anna, reset)
	Entity::reset(savepoint, kClothes3, true);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_S(2, Anna, draw)
	Entity::draw(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SII(3, Anna, updatePosition, CarIndex, Position)
	Entity::updatePosition(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SI(4, Anna, enterExitCompartment, ObjectIndex)
	Entity::enterExitCompartment(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(5, Anna, callbackActionOnDirection)
	Entity::callbackActionOnDirection(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SIIS(6, Anna, callSavepoint, EntityIndex, ActionIndex)
	Entity::callSavepoint(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_S(7, Anna, playSound)
	Entity::playSound(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(8, Anna, callbackActionRestaurantOrSalon)
	Entity::callbackActionRestaurantOrSalon(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(9, Anna, savegame, SavegameType, uint32)
	Entity::savegame(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(10, Anna, updateEntity, CarIndex, EntityPosition)
	if (savepoint.action == kActionExcuseMeCath) {
		if (getEvent(kEventAugustPresentAnna) || getEvent(kEventAugustPresentAnnaFirstIntroduction) || getProgress().chapter >= kChapter2)
			getSound()->playSound(kEntityPlayer, "CAT1001");
		else
			getSound()->excuseMeCath();

		return;
	}

	Entity::updateEntity(savepoint, true);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(11, Anna, updateFromTime, uint32)
	Entity::updateFromTime(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(12, Anna, practiceMusic)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param2 && ENTITY_PARAM(0, 1))
			params->param2 = 1;

		if (params->param6) {
			if (Entity::updateParameter(params->param7, getState()->timeTicks, 75)) {
				getSavePoints()->push(kEntityAnna, kEntityAnna, kActionEndSound);

				params->param6 = 0;
				params->param7 = 0;
			}
		}

		if (params->param4) {
			if (!Entity::updateParameter(params->param8, getState()->timeTicks, 75))
				break;

			params->param4 = 0;
			params->param5 = 1;

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);

			--params->param1;

			getSavePoints()->push(kEntityAnna, kEntityAnna, kActionEndSound);
		}

		params->param8 = 0;
		break;

	case kActionEndSound:
		if (params->param2) {
			callbackAction();
			break;
		}

		++params->param1;

		switch (params->param1) {
		default:
			break;

		case 1:
			getSound()->playSound(kEntityAnna, "ANN2135A");
			break;

		case 2:
			getSound()->playSound(kEntityAnna, "ANN2135B");
			break;

		case 3:
			getSound()->playSound(kEntityAnna, "ANN2135C");
			break;

		case 4:
			getSound()->playSound(kEntityAnna, "ANN2135C");
			break;

		case 5:
			getSound()->playSound(kEntityAnna, "ANN2135L");
			break;

		case 6:
			getSound()->playSound(kEntityAnna, "ANN2135K");
			break;

		case 7:
			getSound()->playSound(kEntityAnna, "ANN2135H");
			break;

		case 8:
			getSound()->playSound(kEntityAnna, "ANN2135K");
			break;

		case 9:
			getSound()->playSound(kEntityAnna, "ANN2135I");
			break;

		case 10:
			getSound()->playSound(kEntityAnna, "ANN2135J");
			break;

		case 11:
			getSound()->playSound(kEntityAnna, "ANN2135M");
			break;

		case 12:
			getSound()->playSound(kEntityAnna, "ANN2135L");
			break;

		case 13:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			callbackAction();
			break;
		}
		break;

	case kActionKnock:
		if (params->param4) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);

			if (savepoint.param.intValue == 53) {
				getSound()->playSound(kEntityPlayer, getSound()->justAMinuteCath());
			} else if (getInventory()->hasItem(kItemPassengerList)) {
				if (rnd(2)) {
					getSound()->playSound(kEntityPlayer, getSound()->wrongDoorCath());
				} else {
					getSound()->playSound(kEntityPlayer, rnd(2) ? "CAT1506A" : "CAT1506");
				}
			} else {
				getSound()->playSound(kEntityPlayer, getSound()->wrongDoorCath());
			}

			params->param4 = 0;
			params->param5 = 1;
		} else {
			getSoundQueue()->stop(kEntityAnna);

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(1);
			setup_playSound("LIB012");
		}
		break;

	case kActionOpenDoor:
		getSoundQueue()->stop(kEntityAnna);
		setCallback(3);
		setup_playSound("LIB013");
		break;

	case kActionDefault:
		params->param1 = 1;
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 78))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 49);

		getEntities()->drawSequenceLeft(kEntityAnna, "418C");

		if (getSoundQueue()->isBuffered(kEntityAnna))
			getSoundQueue()->fade(kEntityAnna);

		getSound()->playSound(kEntityAnna, "ANN2135A");
		break;

	case kActionDrawScene:
		if (params->param5 || params->param4) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			params->param4 = 0;
			params->param5 = 0;
		}

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 60)) {
			++params->param3;
			if (params->param3 == 2) {
				setCallback(5);
				setup_draw("418B");
			}
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_playSound("Ann1016");
			break;

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorHand);
			params->param4 = 1;
			break;

		case 3:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(4);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 4:
			--params->param1;
			params->param6 = 1;
			break;

		case 5:
			getEntities()->drawSequenceLeft(kEntityAnna, "418A");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_SSI(13, Anna, draw2, EntityIndex)
	Entity::draw2(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(14, Anna, updateFromTicks, uint32)
	Entity::updateFromTicks(savepoint);
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_IS(15, Anna, compartmentLogic, TimeValue)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1 < getState()->time && !params->param7) {
			params->param7 = 1;

			getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

			callbackAction();
			break;
		}

		if (params->param5) {
			if (!Entity::updateParameter(params->param8, getState()->timeTicks, 75))
				break;

			params->param5 = 0;
			params->param6 = 1;

			CursorStyle cursor = getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal;

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);
		}

		params->param8 = 0;
		break;

	case kActionOpenDoor:
		if (getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070)) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(1);
			setup_playSound("LIB013");
			break;
		}
		// fall through

	case kActionKnock:
		if (params->param5) {
			CursorStyle cursor = getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal;

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);

			if (savepoint.param.intValue == kObject53) {
				setCallback(6);
				setup_playSound(getSound()->justAMinuteCath());
			} else {
				if (getInventory()->hasItem(kItemPassengerList)) {
					setCallback(7);
					setup_playSound(rnd(2) ? getSound()->wrongDoorCath() : (rnd(2) ? "CAT1506" : "CAT1506A"));
				} else {
					setCallback(8);
					setup_playSound(getSound()->wrongDoorCath());
				}
			}
		} else {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(savepoint.action == kActionKnock ? 3 : 4);
			setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		}
		break;


	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getEntities()->drawSequenceLeft(kEntityAnna, (char *)&params->seq);
		break;

	case kActionDrawScene:
		if (params->param6 || params->param5) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			params->param5 = 0;
			params->param6 = 0;
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(2);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			break;

		case 3:
		case 4:
			setCallback(5);
			setup_playSound("ANN1016");
			break;

		case 5:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param5 = 1;
			break;

		case 6:
		case 7:
		case 8:
			params->param5 = 0;
			params->param6 = 1;
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(16, Anna, chapter1)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		Entity::timeCheck(kTimeChapter1, params->param1, WRAP_SETUP_FUNCTION(Anna, setup_fleeTyler));
		break;

	case kActionDefault:
		getSavePoints()->addData(kEntityAnna, kAction291662081, 0);
		getSavePoints()->addData(kEntityAnna, kAction238936000, 1);

		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);

		getData()->entityPosition = kPosition_8200;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarGreenSleeping;
		getData()->clothes = kClothesDefault;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(17, Anna, doWalkP1, uint32, uint32)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		getData()->inventoryItem = (params->param3 && getEntities()->isDistanceBetweenEntities(kEntityAnna, kEntityPlayer, 2000)) ? (InventoryItem)LOW_BYTE(params->param3) : kItemNone;

		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2)) {
			getData()->inventoryItem = kItemNone;
			callbackAction();
		}
		break;

	case kAction1:
		if (savepoint.param.intValue == 8) {
			getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem & kItemToggleLow);
			params->param3 &= 0xFFFFFFF7;

			setCallback(1);
			setup_savegame(kSavegameTypeEvent, kEventAnnaGiveScarf);
		} else {
			setCallback(2);
			setup_savegame(kSavegameTypeEvent, kEventGotALight);
		}
		break;

	case kActionExcuseMeCath:
		if (getEvent(kEventAugustPresentAnna) || getEvent(kEventAugustPresentAnnaFirstIntroduction) || getProgress().chapter >= kChapter2)
			getSound()->playSound(kEntityPlayer, "CAT1001");
		else
			getSound()->excuseMeCath();
		break;

	case kActionExcuseMe:
		getSound()->excuseMe(kEntityAnna);
		break;

	case kActionDefault:
		getData()->inventoryItem = kItemNone;
		if (getProgress().jacket == kJacketGreen) {
			if (!getEvent(kEventGotALight) && !getEvent(kEventGotALightD) && !getEvent(kEventAugustPresentAnna) && !getEvent(kEventAugustPresentAnnaFirstIntroduction))
				params->param3 = kItemInvalid;

			if (!params->param3 && !getEvent(kEventAnnaGiveScarfAsk) && !getEvent(kEventAnnaGiveScarfDinerAsk) && !getEvent(kEventAnnaGiveScarfSalonAsk))
				params->param3 |= 8;
		}

		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2))
			callbackAction();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getEvent(kEventAnnaGiveScarf)
			 || getEvent(kEventAnnaGiveScarfDiner)
			 || getEvent(kEventAnnaGiveScarfSalon)
			 || getEvent(kEventAnnaGiveScarfMonogram)
			 || getEvent(kEventAnnaGiveScarfDinerMonogram)
			 || getEvent(kEventAnnaGiveScarfSalonMonogram))
				getAction()->playAnimation(kEventAnnaGiveScarfAsk);
			else if (getEvent(kEventAugustPresentAnna)
				  || getEvent(kEventAugustPresentAnnaFirstIntroduction))
				getAction()->playAnimation(kEventAnnaGiveScarfMonogram);
			else
				getAction()->playAnimation(kEventAnnaGiveScarf);

			getEntities()->loadSceneFromEntityPosition(getData()->car, (EntityPosition)(getData()->entityPosition + (750 * (getData()->direction == kDirectionUp ? -1 : 1))), getData()->direction == kDirectionUp);
			break;

		case 2:
			getAction()->playAnimation(getData()->direction == kDirectionUp ? kEventGotALightD : kEventGotALight);
			getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem & kItemToggleHigh);
			params->param3 &= 0xFFFFFF7F;

			if (getProgress().jacket == kJacketGreen && !getEvent(kEventAnnaGiveScarfAsk) && !getEvent(kEventAnnaGiveScarfDinerAsk) && !getEvent(kEventAnnaGiveScarfSalonAsk))
				params->param3 |= 8;

			getEntities()->loadSceneFromEntityPosition(getData()->car, (EntityPosition)(getData()->entityPosition + (750 * (getData()->direction == kDirectionUp ? -1 : 1))), getData()->direction == kDirectionUp);
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(18, Anna, diningLogic, TimeValue)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1 && params->param1 < getState()->time && getEntities()->isSomebodyInsideRestaurantOrSalon()) {
			getData()->inventoryItem = kItemNone;
			callbackAction();
			break;
		}

		if (params->param5 && !params->param4) {
			if (Entity::updateParameter(params->param6, getState()->time, 900)) {
				params->param2 |= kItemScarf;
				params->param5 = 0;
				params->param6 = 0;
			}
		}

		if (params->param3) {
			if (!Entity::updateParameter(params->param7, getState()->timeTicks, 90))
				break;

			getScenes()->loadSceneFromPosition(kCarRestaurant, 61);
		} else {
			params->param7 = 0;
		}
		break;

	case kAction1:
		setCallback(savepoint.param.intValue == 8 ? 1 : 2);
		setup_savegame(kSavegameTypeEvent, savepoint.param.intValue == 8 ? kEventAnnaGiveScarf : kEventDinerMindJoin);
		break;

	case kActionDefault:
		if (getProgress().jacket == kJacketGreen) {
			if (!getEvent(kEventDinerMindJoin) && !getEvent(kEventAugustPresentAnna) && !getEvent(kEventAugustPresentAnnaFirstIntroduction))
				params->param2 |= kItemInvalid;

			if (!params->param2 && !getEvent(kEventAnnaGiveScarfAsk) && !getEvent(kEventAnnaGiveScarfDinerAsk) && !getEvent(kEventAnnaGiveScarfSalonAsk))
				params->param2 |= 8;
		}

		getData()->inventoryItem = (InventoryItem)LOW_BYTE(params->param2);
		break;

	case kActionDrawScene:
		params->param3 = getEntities()->isPlayerPosition(kCarRestaurant, 62);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getEvent(kEventAnnaGiveScarf) || getEvent(kEventAnnaGiveScarfDiner) || getEvent(kEventAnnaGiveScarfSalon)
			 || getEvent(kEventAnnaGiveScarfMonogram) || getEvent(kEventAnnaGiveScarfDinerMonogram) || getEvent(kEventAnnaGiveScarfSalonMonogram)) {
				getAction()->playAnimation(kEventAnnaGiveScarfDinerAsk);
			} else {
				getAction()->playAnimation((getEvent(kEventAugustPresentAnna) || getEvent(kEventAugustPresentAnnaFirstIntroduction)) ? kEventAnnaGiveScarfDinerMonogram : kEventAnnaGiveScarfDiner);
				params->param5 = 1;
			}

			params->param2 &= 0xFFFFFFF7;
			getData()->inventoryItem = (InventoryItem)params->param2;
			getScenes()->loadSceneFromPosition(kCarRestaurant, 61);
			break;

		case 2:
			getAction()->playAnimation(kEventDinerMindJoin);

			params->param2 &= 0xFFFFFF7F;

			if (getProgress().jacket == kJacketGreen
			 && !getEvent(kEventAnnaGiveScarfAsk)
			 && !getEvent(kEventAnnaGiveScarfDinerAsk)
			 && !getEvent(kEventAnnaGiveScarfSalonAsk)) {
				params->param2 |= 8;
			}

			getData()->inventoryItem = (InventoryItem)LOW_BYTE(params->param2);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 61);
			break;
		}
		break;

	case kAction168046720:
		getData()->inventoryItem = kItemNone;
		params->param4 = 1;
		break;

	case kAction168627977:
		getData()->inventoryItem = (InventoryItem)LOW_BYTE(params->param2);
		params->param4 = 0;
		break;

	case kAction170016384:
	case kAction259136835:
	case kAction268773672:
		getData()->inventoryItem = kItemNone;
		callbackAction();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(19, Anna, fleeTyler)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterExitCompartment("618Ca", kObjectCompartment1);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->entityPosition = kPosition_8514;
			getData()->location = kLocationOutsideCompartment;

			setCallback(2);
			setup_updateEntity(kCarRedSleeping, kPosition_4070);
			break;

		case 2:
			setCallback(3);
			setup_enterExitCompartment("618Af", kObjectCompartmentF);
			break;

		case 3:
			getEntities()->clearSequences(kEntityAnna);
			getData()->entityPosition = kPosition_4070;
			getData()->location = kLocationInsideCompartment;

			setup_waitDinner();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(20, Anna, waitDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_compartmentLogic(kTime1093500, "NONE");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterExitCompartment("618Bf", kObjectCompartmentF);
			break;

		case 2:
			getData()->location = kLocationOutsideCompartment;
			getSavePoints()->push(kEntityAnna, kEntityMax, kAction71277948);
			setup_goDinner();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(21, Anna, goDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_doWalkP1(kCarRestaurant, kPosition_850);
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
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(3);
			setup_draw("801US");
			break;

		case 3:
			getEntities()->drawSequenceRight(kEntityAnna, "001B");
			if (getEntities()->isInSalon(kEntityPlayer))
				getEntities()->updateFrame(kEntityAnna);

			setCallback(4);
			setup_callbackActionOnDirection();
			break;

		case 4:
			setup_function22();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(22, Anna, function22)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAnna, "001A");
		getSavePoints()->push(kEntityAnna, kEntityPascale, kAction223262556);
		break;

	case kAction157370960:
		getData()->location = kLocationInsideCompartment;
		setup_waitingDinner();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(23, Anna, waitingDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAnna, "001D");
		getSavePoints()->push(kEntityAnna, kEntityWaiter1, kAction270410280);
		getSavePoints()->push(kEntityAnna, kEntityTables0, kAction136455232);

		setCallback(1);
		setup_diningLogic(kTimeNone);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceLeft(kEntityAnna, "001E");
			setCallback(2);
			setup_playSound("ANN1048");
			break;

		case 2:
			setCallback(3);
			setup_draw("001F");
			break;

		case 3:
			getSavePoints()->push(kEntityAnna, kEntityWaiter1, kAction203859488);
			setup_waitingDinner2();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(24, Anna, waitingDinner2)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAnna, "001G");

		setCallback(1);
		setup_diningLogic(kTimeNone);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceLeft(kEntityAnna, "001H");
			setCallback(2);
			setup_playSound("ANN1049");
			break;

		case 2:
			getSavePoints()->push(kEntityAnna, kEntityWaiter1, kAction136702400);
			setup_eatingDinner();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(25, Anna, eatingDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAnna, "001J");
		getProgress().field_28 = 1;

		setCallback(1);
		setup_diningLogic(kTimeNone);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 2:
			setCallback(3);
			setup_callbackActionRestaurantOrSalon();
			break;

		case 3:
			setup_leaveDinner();
			break;
		}
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAnna, "BLANK");
		break;

	case kAction201437056:
		getEntities()->drawSequenceLeft(kEntityAnna, "001J");
		setCallback(2);
		setup_diningLogic(kTime1138500);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(26, Anna, leaveDinner)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->location = kLocationOutsideCompartment;
		getEntities()->updatePositionEnter(kEntityAnna, kCarRestaurant, 62);

		setCallback(1);
		setup_callSavepoint("001L", kEntityTables0, kActionDrawTablesWithChairs, "001M");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->updatePositionExit(kEntityAnna, kCarRestaurant, 62);
			getSavePoints()->push(kEntityAnna, kEntityWaiter1, kAction237485916);
			getEntities()->drawSequenceRight(kEntityAnna, "801DS");

			if (getEntities()->isInRestaurant(kEntityPlayer))
				getEntities()->updateFrame(kEntityAnna);

			setCallback(2);
			setup_callbackActionOnDirection();
			break;

		case 2:
			setCallback(3);
			setup_doWalkP1(kCarRedSleeping, kPosition_4070);
			break;

		case 3:
			setCallback(4);
			setup_enterExitCompartment("618Af", kObjectCompartmentF);
			break;

		case 4:
			getEntities()->clearSequences(kEntityAnna);
			getData()->entityPosition = kPosition_4070;
			getData()->location = kLocationInsideCompartment;

			setup_freshenUp();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(27, Anna, freshenUp)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityMax, kAction101687594);
		setCallback(1);
		setup_compartmentLogic(kTime1156500, "NONE");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
		case 2:
			if (getProgress().field_14 == 29) {
				params->param1 = (uint)(getState()->time + 900);
				setCallback(2);
				setup_compartmentLogic((TimeValue)params->param1, "NONE");
			} else {
				setCallback(3);
				setup_enterExitCompartment("618Bf", kObjectCompartmentF);
			}
			break;

		case 3:
			getData()->location = kLocationOutsideCompartment;
			getSavePoints()->push(kEntityAnna, kEntityMax, kAction71277948);
			setup_goSalon();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(28, Anna, goSalon)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_doWalkP1(kCarRestaurant, kPosition_850);
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
			getData()->location = kLocationOutsideCompartment;
			getData()->entityPosition = kPosition_1540;
			getScenes()->loadSceneFromItemPosition(kItem3);

			setCallback(3);
			setup_updatePosition("104A", kCarRestaurant, 56);
			break;

		case 3:
			getData()->location = kLocationInsideCompartment;
			setup_waitAugust();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(29, Anna, waitAugust)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param2) {
			if (Entity::updateParameter(params->param3, getState()->time, 900)) {
				getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem | kItemScarf);
				params->param2 = 0;
				params->param3 = 0;
			}
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param4, getState()->timeTicks, 90))
				break;

			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);
		} else {
			params->param4 = 0;
		}
		break;

	case kAction1:
		setCallback(savepoint.param.intValue == 8 ? 1 : 2);
		setup_savegame(kSavegameTypeEvent, savepoint.param.intValue == 8 ? kEventAnnaGiveScarf : kEventAnnaIntroductionRejected);
		break;

	case kActionDefault:
		getData()->inventoryItem = kItemNone;

		if (getProgress().jacket == kJacketGreen
		 && !getEvent(kEventAnnaConversationGoodNight)
		 && !getEvent(kEventAnnaIntroductionRejected))
			getData()->inventoryItem = kItemInvalid;

		if (getProgress().jacket == kJacketGreen
		 && getData()->inventoryItem == kItemNone
		 && !getEvent(kEventAnnaGiveScarfAsk)
		 && !getEvent(kEventAnnaGiveScarfDinerAsk)
		 && !getEvent(kEventAnnaGiveScarfSalonAsk))
			getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem | kItemScarf);

		getEntities()->drawSequenceLeft(kEntityAnna, "104B");
		break;

	case kActionDrawScene:
		params->param1 = getEntities()->isPlayerPosition(kCarRestaurant, 56);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getEvent(kEventAnnaGiveScarf)
			 || getEvent(kEventAnnaGiveScarfDiner)
			 || getEvent(kEventAnnaGiveScarfSalon)
			 || getEvent(kEventAnnaGiveScarfMonogram)
			 || getEvent(kEventAnnaGiveScarfDinerMonogram)
			 || getEvent(kEventAnnaGiveScarfSalonMonogram)) {
				getAction()->playAnimation(kEventAnnaGiveScarfSalonAsk);
			} else {
				getAction()->playAnimation((getEvent(kEventAugustPresentAnna) || getEvent(kEventAugustPresentAnnaFirstIntroduction)) ? kEventAnnaGiveScarfSalonMonogram : kEventAnnaGiveScarfSalon);
				params->param2 = 1;
			}

			getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem & kItemToggleLow);

			getScenes()->loadSceneFromPosition(kCarRestaurant, 51);
			break;

		case 2:
			getAction()->playAnimation((getEvent(kEventAugustPresentAnna) || getEvent(kEventAugustPresentAnnaFirstIntroduction)) ? kEventAnnaConversationGoodNight : kEventAnnaIntroductionRejected);

			getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem & kItemToggleHigh);

			if (getProgress().jacket == kJacketGreen
			 && !getEvent(kEventAnnaGiveScarfAsk)
			 && !getEvent(kEventAnnaGiveScarfDinerAsk)
			 && !getEvent(kEventAnnaGiveScarfSalonAsk))
				 getData()->inventoryItem = (InventoryItem)(getData()->inventoryItem | kItemScarf);

			getScenes()->loadSceneFromPosition(kCarRestaurant, 51);
			break;
		}
		break;

	case kAction123712592:
		getData()->inventoryItem = kItemNone;
		setup_function30();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(30, Anna, function30)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param3 != kTimeInvalid && getState()->time) {
			if (getState()->time > kTime1188000) {
				params->param3 = kTimeInvalid;
				getSound()->playSound(kEntityAnna, "AUG1004");
			} else {
				if (!getEntities()->isInSalon(kEntityPlayer) || !params->param3)
					params->param3 = (uint)(getState()->time + 450);

				if (params->param3 < getState()->time) {
					params->param3 = kTimeInvalid;
					getSound()->playSound(kEntityAnna, "AUG1004");
				}
			}
		}

		if (params->param2 && params->param4 != kTimeInvalid && getState()->time > kTime1179000) {

			if (getState()->time > kTime1192500) {
				params->param4 = kTimeInvalid;
				setup_leaveAugust();
				break;
			}

			if (!getEntities()->isInSalon(kEntityPlayer) || !params->param4)
				params->param4 = (uint)(getState()->time + 150);

			if (params->param4 < getState()->time) {
				params->param4 = kTimeInvalid;
				setup_leaveAugust();
				break;
			}
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param5, getState()->timeTicks, 90))
				break;

			getScenes()->loadSceneFromPosition(kCarRestaurant, 55);
		} else {
			params->param5 = 0;
		}
		break;

	case kActionEndSound:
		params->param2 = 1;
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityAugust, kAction122358304);
		getEntities()->drawSequenceLeft(kEntityAnna, "106B");
		break;

	case kActionDrawScene:
		params->param1 = getEntities()->isPlayerPosition(kCarRestaurant, 56);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(31, Anna, leaveAugust)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_callbackActionRestaurantOrSalon();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;
			getSound()->playSound(kEntityAnna, "AUG1005");

			setCallback(2);
			setup_updateFromTicks(150);
			break;

		case 2:
			getEntities()->updatePositionEnter(kEntityAnna, kCarRestaurant, 56);

			setCallback(3);
			setup_draw2("106C1", "106C2", kEntityAugust);
			break;

		case 3:
			getEntities()->updatePositionExit(kEntityAnna, kCarRestaurant, 56);
			getInventory()->setLocationAndProcess(kItem3, kObjectLocation1);
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction159332865);

			setup_returnCompartment();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(32, Anna, returnCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_doWalkP1(kCarRedSleeping, kPosition_4070);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterExitCompartment("618Af", kObjectCompartmentF);
			break;

		case 2:
			getEntities()->clearSequences(kEntityAnna);

			getData()->entityPosition = kPosition_4070;
			getData()->location = kLocationInsideCompartment;

			setup_readyForBed();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(33, Anna, readyForBed)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityMax, kAction101687594);

		params->param1 = (uint)(getState()->time + 4500);
		setCallback(1);
		setup_compartmentLogic((TimeValue)params->param1, "NONE");
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getObjects()->updateModel(kObjectCompartmentF, kObjectModel1);
			setup_asleep();
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(34, Anna, asleep)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param1 && getEntities()->isPlayerPosition(kCarRedSleeping, 60)) {
			if (Entity::updateParameter(params->param2, getState()->time, 150)) {
				setCallback(1);
				setup_draw("419B");
				break;
			}
		}

label_callback_1:
		Entity::timeCheck(kTime1489500, params->param3, WRAP_SETUP_FUNCTION(Anna, setup_wakeNight));
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		setCallback(savepoint.action == kActionKnock ? 2 : 3);
		setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 78))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 49);

		getData()->car = kCarRedSleeping;
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationOutsideCompartment;

		getEntities()->drawSequenceLeft(kEntityAnna, "419A");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceLeft(kEntityAnna, "419C");
			params->param1 = 1;
			goto label_callback_1;

		case 2:
		case 3:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(4);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 4:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(35, Anna, wakeNight)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param1)
			break;

		if (!Entity::updateParameter(params->param3, getState()->timeTicks, 75))
			break;

		switch (params->param2) {
		default:
			break;

		case 0:
			getSound()->playSound(kEntityAnna, "ANN2135E");
			break;

		case 1:
			getSound()->playSound(kEntityAnna, "ANN2135F");
			break;

		case 2:
			getSound()->playSound(kEntityAnna, "ANN2135G");
			break;

		case 3:
			getSound()->playSound(kEntityAnna, "ANN2135D");
			break;
		}

		params->param1 = 0;
		params->param3 = 0;
		break;

	case kActionEndSound:
		++params->param2;

		if (params->param2 > 3)
			params->param2 = 0;

		params->param1 = 1;
		break;

	case kActionKnock:
	case kActionOpenDoor:
		if (getSoundQueue()->isBuffered(kEntityAnna))
			getSoundQueue()->fade(kEntityAnna);

		if (savepoint.action == kActionKnock)
			getSound()->playSound(kEntityPlayer, "LIB012");

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaVisitToCompartmentGun);
		break;

	case kActionDefault:
		getData()->clothes = kClothes1;
		params->param1 = 1;
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventAnnaVisitToCompartmentGun);
			getSound()->playSound(kEntityPlayer, "LIB015");
			getData()->location = kLocationOutsideCompartment;
			getData()->entityPosition = kPosition_4840;

			getEntities()->updateEntity(kEntityAnna, kCarRedSleeping, kPosition_8200);
			getScenes()->loadSceneFromObject(kObjectCompartmentF, true);
			getSavePoints()->push(kEntityAnna, kEntityVassili, kAction339669520);
			getSavePoints()->push(kEntityAnna, kEntityVerges, kAction339669520);
			getSavePoints()->push(kEntityAnna, kEntityCoudert, kAction339669520);
			getSavePoints()->push(kEntityAnna, kEntityMax, kAction71277948);

			setup_goVassili();
			break;

		case 2:
			setup_goVassili();
			break;
		}
		break;

	case kAction226031488:
		if (getSoundQueue()->isBuffered(kEntityAnna))
			getSoundQueue()->fade(kEntityAnna);

		getSavePoints()->push(kEntityAnna, kEntityMax, kAction71277948);
		break;

	case kAction238358920:
		setCallback(2);
		setup_enterExitCompartment("608Cf", kObjectCompartmentF);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(36, Anna, goVassili)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		setCallback(1);
		setup_updateEntity(kCarRedSleeping, kPosition_8200);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getObjects()->update(kObjectCompartmentA, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);

			setCallback(2);
			setup_enterExitCompartment("608Aa", kObjectCompartmentA);
			break;

		case 2:
			getObjects()->update(kObjectCompartmentA, kEntityPlayer, kObjectLocation2, kCursorKeepValue, kCursorKeepValue);
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityAnna);

			setup_function37();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(37, Anna, function37)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->entityPosition = kPosition_8200;
		getData()->location = kLocationOutsideCompartment;
		getData()->car = kCarRedSleeping;
		break;

	case kAction191477936:
		setup_speakTatiana();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(38, Anna, speakTatiana)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->entityPosition = kPosition_7500;

		setCallback(1);
		setup_playSound("ANN1010");
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getSound()->playSound(kEntityPlayer, "MUS043");
			setup_leaveTatiana();
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(39, Anna, doWalk1019, CarIndex, EntityPosition)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2)) {
			getData()->inventoryItem = kItemNone;

			callbackAction();
		}
		break;

	case kAction1:
		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaGoodNight);
		break;

	case kActionExcuseMe:
		getSound()->playSound(kEntityAnna, "ANN1107A");
		break;

	case kActionDefault:
		getData()->inventoryItem = kItemNone;
		if (!getEvent(kEventAnnaGoodNight) && !getEvent(kEventAnnaGoodNightInverse))
			getData()->inventoryItem = kItemInvalid;

		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2)) {
			getData()->inventoryItem = kItemNone;

			callbackAction();
		}
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getAction()->playAnimation(getData()->direction == kDirectionUp ? kEventAnnaGoodNight : kEventAnnaGoodNightInverse);
			getData()->inventoryItem = kItemNone;

			getEntities()->loadSceneFromEntityPosition(getData()->car, (EntityPosition)(getData()->entityPosition + (750 * (getData()->direction == kDirectionUp ? -1 : 1))), getData()->direction == kDirectionUp);
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(40, Anna, leaveTatiana)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_enterExitCompartment("608Cb", kObjectCompartmentB);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;

			setCallback(2);
			setup_doWalk1019(kCarRedSleeping, kPosition_4070);
			break;

		case 2:
			setCallback(3);
			setup_enterExitCompartment("608Bf", kObjectCompartmentF);
			break;

		case 3:
			getEntities()->clearSequences(kEntityAnna);
			getData()->location = kLocationInsideCompartment;

			setCallback(4);
			setup_updateFromTime(150);
			break;

		case 4:
			setCallback(5);
			setup_enterExitCompartment("608Cf", kObjectCompartmentF);
			break;

		case 5:
			getData()->location = kLocationOutsideCompartment;

			setCallback(6);
			setup_doWalk1019(kCarRedSleeping, kPosition_7500);
			break;

		case 6:
			setCallback(7);
			setup_enterExitCompartment("608Bb", kObjectCompartmentB);
			break;

		case 7:
			getEntities()->clearSequences(kEntityAnna);
			getData()->location = kLocationInsideCompartment;

			setCallback(8);
			setup_updateFromTime(150);
			break;

		case 8:
			setCallback(9);
			setup_enterExitCompartment("608Cb", kObjectCompartmentB);
			break;

		case 9:
			getData()->location = kLocationOutsideCompartment;

			setCallback(10);
			setup_doWalk1019(kCarRedSleeping, kPosition_4070);
			break;

		case 10:
			setCallback(11);
			setup_enterExitCompartment("608Bf", kObjectCompartmentF);
			break;

		case 11:
			getEntities()->clearSequences(kEntityAnna);
			getData()->location = kLocationInsideCompartment;
			getData()->entityPosition = kPosition_4070;

			setup_goBackToSleep();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(41, Anna, goBackToSleep)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!Entity::updateParameter(params->param2, getState()->time, 2700))
			break;

		params->param1++;
		switch (params->param1) {
		default:
			break;

		case 1:
			getEntities()->drawSequenceLeft(kEntityAnna, "419A");
			break;

		case 2:
			getEntities()->drawSequenceLeft(kEntityAnna, "419B");
			break;

		case 3:
			getEntities()->drawSequenceLeft(kEntityAnna, "419C");
			params->param1 = 0;
			break;
		}

		params->param2 = 0;
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		setCallback(savepoint.action == kActionKnock ? 1 : 2);
		setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityMax, kAction101687594);
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getEntities()->drawSequenceLeft(kEntityAnna, "419C");
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
		case 2:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(3);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 3:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(42, Anna, chapter2)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_inPart2();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);

		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothes1;
		getData()->inventoryItem = kItemNone;

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(43, Anna, inPart2)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		setCallback(1);
		setup_practiceMusic();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_compartmentLogic(kTime1786500, "418C");
			break;

		case 2:
			setCallback(3);
			setup_practiceMusic();
			break;

		case 3:
			setCallback(4);
			setup_compartmentLogic(kTime1818000, "418C");
			break;

		case 4:
			setCallback(5);
			setup_practiceMusic();
			break;

		case 5:
			setCallback(6);
			setup_compartmentLogic(kTimeEnd, "418C");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(44, Anna, chapter3)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_practicing();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);

		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothes3;
		getData()->inventoryItem = kItemNone;

		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_I(45, Anna, exitCompartment, bool)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->location = kLocationOutsideCompartment;

		setCallback(1);
		setup_enterExitCompartment("625Bf", kObjectCompartmentF);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSavePoints()->push(kEntityAnna, kEntityCoudert, params->param1 ? kAction185737168 : kAction185671840);
			getSound()->playSound(kEntityAnna, "Ann3147");
			getEntities()->drawSequenceLeft(kEntityAnna, "625EF");
			getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF, true);
			break;

		case 2:
			getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF, true);
			callbackAction();
			break;
		}
		break;

	case kAction157894320:
		setCallback(2);
		setup_updateFromTime(75);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(46, Anna, practicing)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		if (getEntities()->isPlayerPosition(kCarRedSleeping, 60))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 49);

		setCallback(1);
		setup_practiceMusic();
		break;

	case kActionCallback:
		if (getCallback() == 1 || getCallback() == 2) {
			if (ENTITY_PARAM(0, 1)) {
				setup_goLunch();
			} else {
				setCallback(2);
				setup_compartmentLogic((TimeValue) (getState()->time + 4500), "418C");
			}
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(47, Anna, goLunch)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		setCallback(1);
		setup_enterExitCompartment("688Bf", kObjectCompartmentF);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationOutsideCompartment;
			getSavePoints()->push(kEntityAnna, kEntityMax, kAction71277948);

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
			setup_draw("801VS");
			break;

		case 4:
			getSound()->playSound(kEntityAnna, getEvent(kEventAugustLunch) ? "Ann3136" : "Ann3136A", kSoundVolumeEntityDefault, 30);
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction122358304);

			setCallback(5);
			setup_draw2("026B1", "026B2", kEntityAugust);
			break;

		case 5:
			getEntities()->drawSequenceLeft(kEntityAugust, "BLANK");
			setup_lunch();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(48, Anna, lunch)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param1)
			break;

		if (params->param3 != kTimeInvalid && getState()->time > kTime1969200) {
			if (Entity::updateParameterTime(kTime1983600, (!getEntities()->isInRestaurant(kEntityPlayer) || getSoundQueue()->isBuffered(kEntityBoutarel)), params->param3, 150)) {
				setCallback(3);
				setup_playSound("Aug3007A");
				break;
			}
		}

label_callback_4:
		if (ENTITY_PARAM(0, 2)) {
			if (!params->param2)
				params->param2 = (uint)(getState()->time + 4500);

			if (params->param4 != kTimeInvalid) {
				if (params->param2 >= getState()->time) {
					if (!getEntities()->isInRestaurant(kEntityPlayer) || !params->param4)
						params->param4 = (uint)(getState()->time + 450);

					if (params->param4 >= getState()->time)
						break;
				}

				params->param4 = kTimeInvalid;

				setup_leaveLunch();
			}
		}
		break;

	case kActionDefault:
		getEntities()->drawSequenceLeft(kEntityAnna, "026c");
		getData()->location = kLocationInsideCompartment;

		setCallback(1);
		setup_updateFromTime(450);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_playSound("Ann3137B");
			break;

		case 2:
			getSavePoints()->push(kEntityAnna, kEntityWaiter1, kAction218983616);
			break;

		case 3:
			setCallback(4);
			setup_playSound("Aug3006A");
			break;

		case 4:
			goto label_callback_4;

		case 5:
			setCallback(6);
			setup_updateFromTime(900);
			break;

		case 6:
			setCallback(7);
			setup_playSound("Aug3006");
			break;

		case 7:
			setCallback(8);
			setup_updateFromTime(2700);
			break;

		case 8:
			getEntities()->drawSequenceLeft(kEntityAnna, "026H");
			params->param1 = 1;
			break;
		}
		break;

	case kAction122288808:
		getEntities()->drawSequenceLeft(kEntityAnna, "026C");

		setCallback(5);
		setup_playSound("Ann3138A");
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAnna, "BLANK");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(49, Anna, leaveTableWithAugust)
	switch (savepoint.action) {
	default:
		break;

	case kActionExitCompartment:
		getSavePoints()->push(kEntityAnna, kEntityTables3, kActionDrawTablesWithChairs, "010M");
		getEntities()->clearSequences(kEntityAugust);

		callbackAction();
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityTables3, "026J3");
		getEntities()->drawSequenceRight(kEntityAugust, "026J2");
		getEntities()->drawSequenceRight(kEntityAnna, "026J1");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(50, Anna, leaveLunch)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_playSound("Ann3141");
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
			getData()->location = kLocationOutsideCompartment;
			setCallback(3);
			setup_leaveTableWithAugust();
			break;

		case 3:
			setup_afterLunch();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(51, Anna, afterLunch)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1) {
			if (getEntities()->isSomebodyInsideRestaurantOrSalon()) {
				getSound()->playSound(kEntityAnna, "Aug3008");
				getData()->location = kLocationOutsideCompartment;

				setCallback(2);
				setup_draw2("112E1", "112E2", kEntityAugust);
			}
		}
		break;

	case kActionDefault:
		getSound()->playSound(kEntityAnna, "Ann3142", kSoundVolumeEntityDefault, 30);
		getEntities()->updatePositionEnter(kEntityAnna, kCarRestaurant, 57);
		getEntities()->drawSequenceRight(kEntityAnna, "112A");
		if (getEntities()->isInRestaurant(kEntityPlayer))
			getEntities()->updateFrame(kEntityAnna);

		setCallback(1);
		setup_callbackActionOnDirection();
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getData()->location = kLocationInsideCompartment;
			getEntities()->drawSequenceLeft(kEntityAnna, "112B");
			getEntities()->updatePositionExit(kEntityAnna, kCarRestaurant, 57);
			getSavePoints()->push(kEntityAnna, kEntityWaiter2, kAction219377792);
			break;

		case 2:
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction122288808);

			setup_returnCompartment3();
			break;

		case 3:
			getEntities()->drawSequenceLeft(kEntityAnna, "112D");

			if (getState()->time >= kTimeEnterAttnangPuchheim) {
				params->param1 = 1;
			} else {
				setCallback(4);
				setup_playSound("Ann3142A");
			}
			break;

		case 4:
			setCallback(5);
			setup_updateFromTime(1800);
			break;

		case 5:
			setCallback(6);
			setup_playSound("Aug3007");
			break;

		case 6:
			params->param1 = 1;
			break;
		}
		break;

	case kAction101169422:
		if (getEvent(kEventKronosVisit)) {
			setCallback(3);
			setup_updatePosition("112J", kCarRestaurant, 57);
			break;
		}

		if (getState()->time >= kTimeEnterAttnangPuchheim) {
			params->param1 = 1;
		} else {
			setCallback(4);
			setup_playSound("Ann3142A");
		}
		break;

	case kAction122288808:
		getEntities()->drawSequenceLeft(kEntityAnna, "112D");
		getSavePoints()->push(kEntityAnna, kEntityKronos, kAction157159392);
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAnna, "BLANK");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(52, Anna, returnCompartment3)
	switch (savepoint.action) {
	default:
		break;

	case kActionExitCompartment:
		getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF);
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;

		getEntities()->clearSequences(kEntityAnna);

		setup_dressing();
		break;

	case kActionDefault:
		setCallback(1);
		setup_updateEntity(kCarRedSleeping, kPosition_4070);
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getEntities()->drawSequenceRight(kEntityAnna, "688Af");
			getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF);
			getData()->location = kLocationInsideCompartment;

			if (getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4070) || getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4455)) {
				getAction()->playAnimation(isNight() ? kEventCathTurningNight : kEventCathTurningDay);
				getSound()->playSound(kEntityPlayer, "BUMP");
				getScenes()->loadSceneFromObject(kObjectCompartmentF);
			}
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(53, Anna, dressing)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getProgress().field_48 && params->param5 != kTimeInvalid) {
			if (Entity::updateParameterTime(kTime2065500, !getEntities()->isPlayerInCar(kCarRedSleeping), params->param5, 150)) {
				setup_giveMaxToConductor2();
				break;
			}
		}

		if (params->param3) {
			if (Entity::updateParameter(params->param6, getState()->time, 9000)) {
				params->param4 = !params->param4;
				getEntities()->drawSequenceLeft(kEntityAnna, params->param4 ? "417A" : "417B");
				params->param6 = 0;
			}
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param7, getState()->timeTicks, 75))
				break;

			CursorStyle cursor = getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal;

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);

			params->param1 = 0;
			params->param2 = 1;
		}

		params->param7 = 0;
		break;

	case kActionOpenDoor:
		if (getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070)) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(1);
			setup_playSound("LIB013");
			break;
		}
		// fall through

	case kActionKnock:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		if (params->param1) {
			if (savepoint.param.intValue == 53) {
				setCallback(6);
				setup_playSound(getSound()->justAMinuteCath());
				break;
			}

			if (getInventory()->hasItem(kItemPassengerList)) {
				setCallback(7);
				setup_playSound(rnd(2) ? getSound()->wrongDoorCath() : (rnd(2) ? "CAT1506" : "CAT1506A"));
				break;
			}

			setCallback(8);
			setup_playSound(getSound()->wrongDoorCath());
			break;
		}

		setCallback(savepoint.action == kActionKnock ? 3 : 4);
		setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityMax, kAction101687594);
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->clothes = kClothes2;
		break;

	case kActionDrawScene:
		if (params->param1 || params->param2) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			params->param1 = 0;
			params->param2 = 0;
		}

		if (!params->param3 && (getEntities()->isPlayerPosition(kCarRedSleeping, 60) || getState()->time > kTime2034000)) {
			params->param3 = 1;

			setCallback(9);
			setup_draw("416");
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(2);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			break;

		case 3:
		case 4:
			setCallback(5);
			setup_playSound("ANN1016");
			break;

		case 5:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param1 = 1;
			break;

		case 6:
		case 7:
		case 8:
			if (getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070)) {
				getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
				getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
			}

			params->param1 = 0;
			params->param2 = 1;
			break;

		case 9:
			if (getEntities()->isPlayerPosition(kCarRedSleeping, 60))
				getScenes()->loadSceneFromPosition(kCarRedSleeping, 78);
			getEntities()->drawSequenceLeft(kEntityAnna, "417B");
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(54, Anna, giveMaxToConductor2)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param3) {
			if (Entity::timeCheck(kTime2079000, params->param5, WRAP_SETUP_FUNCTION(Anna, setup_goConcert)))
				break;

			if (Entity::updateParameter(params->param6, getState()->time, 9000)) {
				params->param4 = !params->param4;
				getEntities()->drawSequenceLeft(kEntityAnna, params->param4 ? "417A" : "417B");
				params->param6 = 0;
			}
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param7, getState()->timeTicks, 75))
				break;

			CursorStyle cursor = getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal;

			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, cursor);

			params->param1 = 0;
			params->param2 = 1;
		}

		params->param7 = 0;
		break;

	case kActionOpenDoor:
		if (getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070)) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

			setCallback(1);
			setup_playSound("LIB013");
			break;
		}
		// fall through

	case kActionKnock:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		if (params->param1) {
			if (savepoint.param.intValue == 53) {
				setCallback(6);
				setup_playSound(getSound()->justAMinuteCath());
				break;
			}

			if (getInventory()->hasItem(kItemPassengerList)) {
				setCallback(7);
				setup_playSound(rnd(2) ? getSound()->wrongDoorCath() : (rnd(2) ? "CAT1506" : "CAT1506A"));
				break;
			}

			setCallback(8);
			setup_playSound(getSound()->wrongDoorCath());
			break;
		}

		setCallback(savepoint.action == kActionKnock ? 3 : 4);
		setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		break;

	case kActionDefault:
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);
		if (getEntities()->isPlayerPosition(kCarRedSleeping, 60))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 78);

		getSavePoints()->push(kEntityAnna, kEntityCoudert, kAction189750912);
		break;

	case kActionDrawScene:
		if (params->param1 || params->param2) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			params->param1 = 0;
			params->param2 = 0;
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (!getSoundQueue()->isBuffered(kEntityMax)) {
				setCallback(2);
				setup_playSound("MAX1120");
				break;
			}
			// fall through

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			break;

		case 3:
		case 4:
			setCallback(5);
			setup_playSound("ANN1016");
			break;

		case 5:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param1 = 1;
			break;

		case 6:
		case 7:
		case 8:
			if (getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070)) {
				getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
				getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorHand);
			}

			params->param1 = 0;
			params->param2 = 1;
			break;

		case 9:
			getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF, true);
			getEntities()->clearSequences(kEntityAnna);

			getData()->location = kLocationInsideCompartment;
			getData()->entityPosition = kPosition_4070;
			params->param3 = 1;

			getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

			if (getEntities()->isPlayerPosition(kCarRedSleeping, 78))
				getScenes()->loadSceneFromPosition(kCarRedSleeping, 49);
			getEntities()->drawSequenceLeft(kEntityAnna, "417B");
			break;
		}
		break;

	case kAction123733488:
		setCallback(9);
		setup_enterExitCompartment("629Ef", kObjectCompartmentF);
		break;

	case kAction156049968:
		getEntities()->drawSequenceLeft(kEntityAnna, "629DF");
		getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF, true);
		break;

	case kAction253868128:
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(55, Anna, goConcert)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation2, kCursorKeepValue, kCursorKeepValue);

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 78))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 49);

		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getInventory()->setLocationAndProcess(kItemKey, kObjectLocation1);

		setCallback(1);
		setup_exitCompartment(true);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
			setCallback(2);
			setup_updateEntity(kCarKronos, kPosition_9270);
			break;

		case 2:
			setup_concert();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(56, Anna, concert)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);
		getData()->entityPosition = kPosition_6000;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarKronos;
		break;

	case kAction191668032:
		setup_leaveConcert();
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(57, Anna, leaveConcert)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getData()->car = kCarGreenSleeping;
		getData()->entityPosition = kPosition_850;
		getData()->location = kLocationOutsideCompartment;

		setCallback(1);
		setup_updateEntity(kCarGreenSleeping, kPosition_5790);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction191668032);

			setCallback(2);
			setup_updateEntity(kCarRedSleeping, kPosition_4070);
			break;

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorNormal, kCursorNormal);
			getSavePoints()->push(kEntityAnna, kEntityCoudert, kAction205033696);
			getEntities()->drawSequenceLeft(kEntityAnna, "625Ef");
			getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF, true);
			break;

		case 3:
			getEntities()->drawSequenceLeft(kEntityAnna, "625Gf");
			getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF, true);
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction169032608);
			break;

		case 4:
			if (getSoundQueue()->isBuffered(kEntityAugust)) {
				setCallback(4);
				setup_updateFromTime(75);
			} else {
				setCallback(5);
				setup_playSound("Aug3009");
			}
			break;

		case 5:
			getSound()->playSound(kEntityAnna, "Aug3009A");

			setCallback(6);
			setup_enterExitCompartment("628Bf", kObjectCompartmentF);
			break;

		case 6:
			getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF, true);
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction122288808);

			setup_afterConcert();
			break;
		}
		break;

	case kAction123712592:
		getEntities()->drawSequenceLeft(kEntityAnna, "628Af");

		if (getSoundQueue()->isBuffered(kEntityAugust)) {
			setCallback(4);
			setup_updateFromTime(75);
		} else {
			setCallback(5);
			setup_playSound("Aug3009");
		}
		break;

	case kAction192063264:
		if (getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4070)
		 || getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4455)) {
			getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF, true);
			setup_leaveConcertCathInCompartment();
		} else {
			setCallback(3);
			setup_enterExitCompartment("625Ff", kObjectCompartmentF);
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(58, Anna, leaveConcertCathInCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaSearchingCompartment);
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getAction()->playAnimation(kEventAnnaSearchingCompartment);
			getEntities()->clearSequences(kEntityAnna);
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 8);
			getSound()->playSound(kEntityAnna, "lib015");
			getSavePoints()->push(kEntityAnna, kEntityAugust, kAction122288808);
			setup_afterConcert();
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(59, Anna, afterConcert)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getInventory()->hasItem(kItemKey) && params->param4 != kTimeInvalid && getState()->time > kTime2218500) {
			if (getState()->time > kTime2248200) {
				params->param4 = kTimeInvalid;
				setup_goBaggageCompartment();
				break;
			}

			if (!params->param3
			 || (!getEntities()->isPlayerInCar(kCarRedSleeping)
			 && !getEntities()->isInSalon(kEntityPlayer)
			 && !getEntities()->isInRestaurant(kEntityPlayer))
			 || !params->param4)
				params->param4 = (uint)getState()->time;

			if (params->param4 < getState()->time) {
				params->param4 = kTimeInvalid;
				setup_goBaggageCompartment();
				break;
			}
		}

		if (params->param1) {
			if (!Entity::updateParameter(params->param5, getState()->timeTicks, 75))
				break;

			CursorStyle style = getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal;
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, style);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, style);

			params->param1= 0;
			params->param2 = 1;
		}

		params->param5 = 0;
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		if (params->param1) {
			if (savepoint.param.intValue == 53) {
				setCallback(4);
				setup_playSound(getSound()->justAMinuteCath());
			} else if (getInventory()->hasItem(kItemPassengerList)) {
				setCallback(5);
				setup_playSound(rnd(2) ? getSound()->wrongDoorCath() : (rnd(2) ? "CAT1506" : "CAT1506A"));
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
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		getEntities()->clearSequences(kEntityAnna);

		getObjects()->update(kObject107, kEntityPlayer, kObjectLocation2, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 60))
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 78);
		break;

	case kActionDrawScene:
		if (params->param1 || params->param2) {
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			params->param1 = 0;
			params->param2 = 0;
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
		case 2:
			setCallback(3);
			setup_playSound("ANN1016");
			break;

		case 3:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param1 = 1;
			break;

		case 4:
		case 5:
		case 6:
			params->param1 = 0;
			params->param2 = 1;
			break;

		case 7:
			getSavePoints()->push(kEntityAnna, kEntityTatiana, kAction100906246);
			break;
		}
		break;

	case kAction156622016:
		if (params->param3) {
			setCallback(8);
			setup_giveMaxBack();
		}
		break;

	case kAction236241630:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		setCallback(7);
		setup_playSound("Ann1016A");
		break;

	case kAction236517970:
		params->param3 = 1;
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(60, Anna, giveMaxBack)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityMax, kAction122358304);
		getSound()->playSound(kEntityAnna, rnd(2) ? "Ann3126" : "Ann3127");

		setCallback(1);
		setup_enterExitCompartment("630Cf", kObjectCompartmentF);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterExitCompartment("630Df", kObjectCompartmentF);
			break;

		case 2:
			getEntities()->clearSequences(kEntityAnna);
			getSavePoints()->push(kEntityAnna, kEntityCoudert, kAction189026624);
			break;

		case 3:
			getData()->entityPosition = kPosition_4070;
			getData()->location = kLocationInsideCompartment;
			getEntities()->clearSequences(kEntityAnna);

			callbackAction();
			break;
		}
		break;

	case kAction156049968:
		setCallback(3);
		setup_enterExitCompartment("629EF", kObjectCompartmentF);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(61, Anna, goBaggageCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getState()->timeDelta = 3;

		setCallback(1);
		setup_savegame(kSavegameTypeTime, 0);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

			setCallback(2);
			setup_exitCompartment(false);
			break;

		case 2:
			getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

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
			setup_draw("802US");
			break;

		case 5:
			getEntities()->drawSequenceRight(kEntityAnna, "802UD");
			if (getEntities()->isInSalon(kEntityPlayer))
				getEntities()->updateFrame(kEntityAnna);

			setCallback(6);
			setup_callbackActionOnDirection();
			break;

		case 6:
			getEntities()->clearSequences(kEntityAnna);
			setup_function62();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(62, Anna, function62)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1 && getState()->time > kTime2259000 && !params->param2) {
			params->param2 = 1;
			getSavePoints()->push(kEntityAnna, kEntityVesna, kAction189299008);
			setup_deadBaggageCompartment();
		}
		break;

	case kActionDefault:
		getData()->car = kCarBaggage;
		getProgress().field_54 = 1;
		break;

	case kAction235856512:
		params->param1 = 1;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(63, Anna, deadBaggageCompartment)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getSavePoints()->push(kEntityAnna, kEntityChapters, kAction171843264);
		break;

	// Game over with Anna killed!
	case kActionCallback:
		if (getCallback() == 1) {
			getAction()->playAnimation(kEventAnnaKilled);
			getLogic()->gameOver(kSavegameTypeTime, kTime2250000, kSceneGameOverAnnaDied, true);
		}
		break;

	// Anna will get killed...
	case kAction272177921:
		if (getSoundQueue()->isBuffered("MUS012"))
			getSoundQueue()->fade("MUS012");

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaKilled);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(64, Anna, baggageFight)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaBaggageArgument);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventAnnaBaggageArgument);

			setCallback(2);
			setup_savegame(kSavegameTypeTime, (EventIndex)kTimeNone);
			break;

		case 2:
			params->param1 = getFight()->setup(kFightAnna);

			if (params->param1)
				getLogic()->gameOver(kSavegameTypeIndex, 0, kSceneNone, params->param1 == Fight::kFightEndLost);
			else {
				getState()->time = (TimeValue)(getState()->time + 1800);

				setCallback(3);
				setup_savegame(kSavegameTypeEvent, kEventAnnaBagagePart2);
			}
			break;

		case 3:
			getAction()->playAnimation(kEventAnnaBagagePart2);
			getScenes()->loadSceneFromPosition(kCarBaggage, 96);

			getProgress().field_54 = 0;
			RESET_ENTITY_STATE(kEntityVesna, Vesna, setup_inCompartment);
			getState()->time = kTime2266200;

			setup_prepareVienna();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(65, Anna, prepareVienna)
	if (savepoint.action == kActionDefault) {
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothes3;
		getData()->inventoryItem = kItemNone;

		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);

		setCallback(1);
		setup_compartmentLogic(kTimeEnd, "NONE");
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(66, Anna, chapter4)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_reading();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);

		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarRedSleeping;
		getData()->clothes = kClothes2;
		getData()->inventoryItem = kItemNone;

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(67, Anna, reading)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getEntities()->isPlayerPosition(kCarRedSleeping, 46)) {
			if (!Entity::updateParameter(params->param4, getState()->timeTicks, 30))
				goto label_next;

			getScenes()->loadSceneFromPosition(kCarRedSleeping, 8);
		}

		params->param4 = 0;

label_next:
		if (params->param1) {
			if (!Entity::updateParameter(params->param5, getState()->timeTicks, 75))
				break;

			params->param1 = 0;
			params->param2 = 1;

			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, getEntities()->isInsideCompartment(kEntityMax, kCarRedSleeping, kPosition_4070) ? kCursorHand : kCursorNormal);
		}

		params->param5 = 0;
		break;

	case kAction1:
		getData()->inventoryItem = kItemNone;
		getEntityData(kEntityPlayer)->location = kLocationInsideCompartment;

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaConversation_34);
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorNormal, kCursorNormal);

		if (params->param1) {
			setCallback(5);
			setup_playSound(getSound()->justAMinuteCath());
		} else {
			setCallback(savepoint.action == kActionKnock ? 2 : 3);
			setup_playSound(savepoint.action == kActionKnock ? "LIB012" : "LIB013");
		}
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation2, kCursorNormal, kCursorNormal);
		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocation1, kCursorKeepValue, kCursorKeepValue);
		getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getEntities()->drawSequenceLeft(kEntityAnna, "511B");
		break;

	case kActionDrawScene:
		if (params->param1 || params->param2) {
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
			params->param1 = 0;
			params->param2 = 0;
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventAnnaConversation_34);
			getSound()->playSound(kEntityPlayer, "LIB015");
			getScenes()->loadSceneFromPosition(kCarRedSleeping, 8);

			setup_sulking();
			break;

		case 2:
		case 3:
			setCallback(4);
			setup_playSound("ANN1016");
			break;

		case 4:
			getObjects()->update(kObject53, kEntityAnna, kObjectLocation1, kCursorTalk, kCursorNormal);
			params->param1 = 1;
			break;

		case 5:
			params->param1 = 0;
			params->param2 = 1;
			break;
		}
		break;

	case kAction191001984:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
		getData()->inventoryItem = kItemNone;

		setup_goSalon4();
		break;

	case kAction219971920:
		params->param3 = 1;
		getData()->inventoryItem = kItemInvalid;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(68, Anna, sulking)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!params->param1) {
			setCallback(1);
			setup_compartmentLogic(kTime2511900, "NONE");
		}
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);
		getObjects()->update(kObject53, kEntityPlayer, kObjectLocation1, kCursorHandKnock, kCursorHand);

		getData()->car = kCarRedSleeping;
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationInsideCompartment;
		break;

	case kAction191001984:
		getObjects()->update(kObjectCompartmentF, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
		setup_goSalon4();
		break;

	case kAction201431954:
		params->param1 = 1;
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(69, Anna, goSalon4)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param1) {
			if (!Entity::updateParameter(params->param2, getState()->time, 4500))
				break;

			getData()->car = kCarRedSleeping;
			getData()->entityPosition = kPosition_9270;
			getData()->location = kLocationOutsideCompartment;

			setup_returnCompartment4();
			break;
		}

		Entity::timeCheckCallback(kTime2535300, params->param3, 4, WRAP_SETUP_FUNCTION(Anna, setup_callbackActionRestaurantOrSalon));
		break;

	case kActionDefault:
		getData()->car = kCarRedSleeping;
		getData()->entityPosition = kPosition_4070;
		getData()->location = kLocationOutsideCompartment;

		setCallback(1);
		setup_updateEntity(kCarRestaurant, kPosition_850);
		break;

	case kActionDrawScene:
		if (params->param1 && getEntities()->isInsideTrainCar(kEntityPlayer, kCarRedSleeping)) {
			getData()->car = kCarRedSleeping;
			getData()->entityPosition = kPosition_8200;
			getData()->location = kLocationOutsideCompartment;

			setup_returnCompartment4();
		}
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
			getData()->entityPosition = kPosition_1540;
			getData()->location = kLocationOutsideCompartment;

			setCallback(3);
			setup_updatePosition("127A", kCarRestaurant, 56);
			break;

		case 3:
			getData()->location = kLocationInsideCompartment;
			getEntities()->drawSequenceLeft(kEntityAnna, "127B");
			getSavePoints()->push(kEntityAnna, kEntityWaiter2, kAction258136010);
			break;

		case 4:
			getData()->location = kLocationOutsideCompartment;

			setCallback(5);
			setup_updatePosition("127G", kCarRestaurant, 56);
			break;

		case 5:
			setup_returnCompartment4();
			break;
		}
		break;

	case kAction100969180:
		getEntities()->clearSequences(kEntityAnna);
		params->param1 = 1;
		break;

	case kAction122288808:
		getEntities()->drawSequenceLeft(kEntityAnna, "127E");
		getSavePoints()->push(kEntityAnna, kEntityAbbot, kAction203073664);
		break;

	case kAction122358304:
		getEntities()->drawSequenceLeft(kEntityAnna, "BLANK");
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(70, Anna, returnCompartment4)
	switch (savepoint.action) {
	default:
		break;

	case kActionDefault:
		setCallback(1);
		setup_doWalkCathFollowsAnna(kCarRedSleeping, kPosition_4070);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			setCallback(2);
			setup_enterCompartmentCathFollowsAnna();
			break;

		case 2:
			getData()->location = kLocationOutsideCompartment;
			getEntities()->clearSequences(kEntityAnna);
			setup_letDownHair();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(71, Anna, enterCompartmentCathFollowsAnna)
	switch (savepoint.action) {
	default:
		break;

	case kActionExitCompartment:
		getEntities()->exitCompartment(kEntityAnna, kObjectCompartmentF);
		getData()->entityPosition = kPosition_4070;

		callbackAction();
		break;

	case kActionDefault:
		getEntities()->drawSequenceRight(kEntityAnna, "625Af");

		if (getEntities()->isPlayerPosition(kCarRedSleeping, 7)
		 || getEntities()->isPlayerPosition(kCarRedSleeping, 28)
		 || getEntities()->isPlayerPosition(kCarRedSleeping, 56))
			getScenes()->loadScene(getScenes()->processIndex(getState()->scene));

		getEntities()->enterCompartment(kEntityAnna, kObjectCompartmentF);

		getData()->location = kLocationInsideCompartment;

		if (getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4070)
		 || getEntities()->isInsideCompartment(kEntityPlayer, kCarRedSleeping, kPosition_4455)) {
			getAction()->playAnimation(isNight() ? kEventCathTurningNight : kEventCathTurningDay);
			getSound()->playSound(kEntityPlayer, "BUMP");
			getScenes()->loadSceneFromObject(kObjectCompartmentF, true);
		}
		break;

	case kActionDrawScene:
		if (!getEvent(kEventAnnaTiredKiss)
		 && getEntities()->isDistanceBetweenEntities(kEntityPlayer, kEntityAnna, 2000)
		 && getEntities()->hasValidFrame(kEntityAnna)
		 && getData()->entityPosition < getEntityData(kEntityPlayer)->entityPosition) {
			setCallback(1);
			setup_savegame(kSavegameTypeEvent, kEventAnnaTiredKiss);
		}
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getAction()->playAnimation(kEventAnnaTiredKiss);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 29);
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION_II(72, Anna, doWalkCathFollowsAnna, CarIndex, EntityPosition)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getEvent(kEventAnnaTired) || getEntities()->isWalkingOppositeToPlayer(kEntityAnna))
			getData()->inventoryItem = kItemNone;
		else
			getData()->inventoryItem = kItemInvalid;

		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2)) {
			getData()->inventoryItem = kItemNone;
			callbackAction();
		}
		break;

	case kAction1:
		getData()->inventoryItem = kItemNone;

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaTired);
		break;

	case kActionDefault:
		if (getEntities()->updateEntity(kEntityAnna, (CarIndex)params->param1, (EntityPosition)params->param2)) {
			callbackAction();
		} else if (!getEvent(kEventAnnaTired))
			getData()->inventoryItem = kItemInvalid;
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			getAction()->playAnimation(kEventAnnaTired);

			getEntities()->loadSceneFromEntityPosition(getData()->car, (EntityPosition)(getData()->entityPosition + (750 * (getData()->direction == kDirectionUp ? -1 : 1))), getData()->direction == kDirectionUp);
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(73, Anna, letDownHair)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (params->param3 == kTimeInvalid || params->param1 >= getState()->time)
			break;

		if (params->param2 >= getState()->time) {
			if (!((getEntities()->isPlayerInCar(kCarGreenSleeping) || getEntities()->isPlayerInCar(kCarRedSleeping)) && params->param3))
				params->param3 = (uint)getState()->time;

			if (params->param3 >= getState()->time)
				break;
		}

		params->param3 = kTimeInvalid;

		if (!getEntities()->isPlayerInCar(kCarGreenSleeping) && !getEntities()->isPlayerInCar(kCarRedSleeping))
			getSound()->playSound(kEntityPlayer, "BUMP");

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventTrainHijacked);
		break;

	case kActionKnock:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocationNone, kCursorNormal, kCursorNormal);

		setCallback(2);
		setup_playSound("LIB012");
		break;

	case kActionOpenDoor:
		setCallback(4);
		setup_savegame(kSavegameTypeEvent, kEventAnnaKissTrainHijacked);
		break;

	case kActionDefault:
		getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocationNone, kCursorHandKnock, kCursorHand);
		getState()->timeDelta = 1;

		params->param1 = (uint)(getState()->time + 4500);
		params->param2 = (uint)(getState()->time + 9000);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventTrainHijacked);
			getSavePoints()->push(kEntityAnna, kEntityChapters, kAction139254416);
			break;

		case 2:
			setCallback(3);
			setup_playSound("Ann4200");
			break;

		case 3:
			getObjects()->update(kObjectCompartmentF, kEntityAnna, kObjectLocationNone, kCursorHandKnock, kCursorHand);
			break;

		case 4:
			getAction()->playAnimation(kEventAnnaKissTrainHijacked);
			getSavePoints()->push(kEntityAnna, kEntityChapters, kAction139254416);
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(74, Anna, chapter5)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		setup_tiedUp();
		break;

	case kActionDefault:
		getEntities()->clearSequences(kEntityAnna);

		getData()->entityPosition = kPosition_3969;
		getData()->location = kLocationInsideCompartment;
		getData()->car = kCarBaggageRear;
		getData()->clothes = kClothes3;
		getData()->inventoryItem = kItemNone;

		getObjects()->update(kObjectOutsideAnnaCompartment, kEntityPlayer, kObjectLocationNone, kCursorKeepValue, kCursorKeepValue);

		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(75, Anna, tiedUp)
	switch (savepoint.action) {
	default:
		break;

	case kActionCallback:
		if (getCallback() == 1) {
			if (getProgress().field_C)
				getAction()->playAnimation(getEvent(kEventAnnaKissTrainHijacked) ? kEventAnnaBaggageTies2 : kEventAnnaBaggageTies);
			else
				getAction()->playAnimation(getEvent(kEventAnnaKissTrainHijacked) ? kEventAnnaBaggageTies3 : kEventAnnaBaggageTies4);

			getScenes()->loadSceneFromPosition(kCarBaggageRear, 88);
			setup_function76();
		}
		break;

	case kAction272177921:
		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventAnnaBaggageTies);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(76, Anna, function76)
	if (savepoint.action == kAction158480160)
		setup_readyToScore();
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(77, Anna, readyToScore)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (getState()->time > kTime3645000 && !params->param2) {
			params->param2 = 1;
			getState()->timeDelta = 0;
		}
		break;

	case kActionKnock:
	case kActionOpenDoor:
		getSound()->playSound(kEntityPlayer, savepoint.action == kActionKnock ? "LIB012" : "LIB014");

		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventAnnaDialogGoToJerusalem);
		break;

	case kActionDefault:
		getObjects()->update(kObject106, kEntityAnna, kObjectLocation1, kCursorHandKnock, kCursorHand);
		break;

	case kActionDrawScene:
		if (!params->param1 && getEntities()->isInsideTrainCar(kEntityPlayer, kCarBaggage)) {
			setCallback(1);
			setup_savegame(kSavegameTypeTime, kTimeNone);
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			params->param1 = 1;
			break;

		case 2:
			getObjects()->update(kObject106, kEntityPlayer, kObjectLocationNone, kCursorHandKnock, kCursorHand);
			getAction()->playAnimation(kEventAnnaDialogGoToJerusalem);

			getState()->time = kTime4914000;
			getState()->timeDelta = 0;

			getSavePoints()->push(kEntityAnna, kEntityTatiana, kAction236060709);

			getScenes()->loadSceneFromPosition(kCarBaggage, 97, 1);

			setCallback(3);
			setup_savegame(kSavegameTypeTime, kTimeNone);
			break;

		case 3:
			setup_kidnapped();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(78, Anna, kidnapped)
	switch (savepoint.action) {
	default:
		break;

	case kActionDrawScene:
		if ((getEntities()->isInRestaurant(kEntityPlayer) || getEntities()->isInSalon(kEntityPlayer)) && getInventory()->hasItem(kItemFirebird)) {
			setup_finalSequence();
			break;
		}

		if (getEntities()->isInSalon(kEntityPlayer)) {
			getState()->time = kTime4920300;

			setCallback(getInventory()->get(kItemFirebird)->location == kObjectLocation4 ? 2 : 1);
			setup_savegame(kSavegameTypeEvent, getInventory()->get(kItemFirebird)->location == kObjectLocation4 ? kEventKronosHostageAnna : kEventKronosHostageAnnaNoFirebird);
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventKronosHostageAnnaNoFirebird);
			getLogic()->gameOver(kSavegameTypeEvent2, kEventAugustUnhookCarsBetrayal, kSceneNone, true);
			break;

		case 2:
			getAction()->playAnimation(kEventKronosHostageAnna);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 61, 1);
			getSound()->playSound(kEntityAnna, "Mus024", kVolumeFull);
			setup_waiting();
			break;
		}
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(79, Anna, waiting)
	switch (savepoint.action) {
	default:
		break;

	case kActionEndSound:
		getState()->time = kTime4923000;
		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventKahinaPunchBaggageCarEntrance);
		break;

	case kActionDrawScene:
		if (getEntities()->isInRestaurant(kEntityPlayer) && getInventory()->hasItem(kItemFirebird)) {
			setup_finalSequence();
			break;
		}

		if (getEntities()->isInSalon(kEntityPlayer) && !getEvent(kEventKahinaPunch)) {
			getState()->time = kTime4923000;
			setCallback(2);
			setup_savegame(kSavegameTypeEvent, kEventKahinaPunch);
		}
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getEntities()->isInSalon(kEntityPlayer))
				getAction()->playAnimation(kEventKahinaPunchSalon);
			else if (getEntities()->isInRestaurant(kEntityPlayer))
				getAction()->playAnimation(kEventKahinaPunchRestaurant);
			else if (getEntities()->isInKitchen(kEntityPlayer))
				getAction()->playAnimation(kEventKahinaPunchKitchen);
			else if (getEntities()->isInBaggageCarEntrance(kEntityPlayer))
				getAction()->playAnimation(kEventKahinaPunchBaggageCarEntrance);
			else if (getEntities()->isInsideTrainCar(kEntityPlayer, kCarBaggage))
				getAction()->playAnimation(kEventKahinaPunchBaggageCar);
			break;

		case 2:
			getAction()->playAnimation(kEventKahinaPunch);
			break;
		}

		getLogic()->gameOver(kSavegameTypeIndex, 1, kSceneNone, true);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(80, Anna, finalSequence)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!Entity::updateParameter(params->param1, getState()->timeTicks, 450))
			break;

		getSound()->playSound(kEntityPlayer, "Kro5001", kVolumeFull);
		break;

	case kActionEndSound:
		getSound()->playSound(kEntityPlayer, "Kro5002", kVolumeFull);
		getState()->time = kTime4929300;

		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventKahinaPunch);
		break;

	case kActionDefault:
		getState()->time = kTime4923000;

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventKronosBringFirebird);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			if (getSoundQueue()->isBuffered(kEntityAnna))
				getSoundQueue()->fade(kEntityAnna);

			getAction()->playAnimation(kEventKronosBringFirebird);
			getScenes()->loadSceneFromItem(kItemFirebird);
			getSound()->playSound(kEntityAnna, "Mus025", kVolumeFull);
			break;

		case 2:
			getAction()->playAnimation(kEventKahinaPunch);
			getLogic()->gameOver(kSavegameTypeIndex, 1, kSceneNone, true);
			break;

		case 3:
			getProgress().isEggOpen = true;

			if (getSoundQueue()->isBuffered(kEntityAnna))
				getSoundQueue()->fade(kEntityAnna);

			getAction()->playAnimation(kEventKronosOpenFirebird);
			getScenes()->loadSceneFromPosition(kCarRestaurant, 3);

			setup_openFirebird();
			break;
		}
		break;

	case kAction205294778:
		getState()->time = kTime4929300;

		setCallback(3);
		setup_savegame(kSavegameTypeEvent, kEventKronosOpenFirebird);
		break;
	}
IMPLEMENT_FUNCTION_END

//////////////////////////////////////////////////////////////////////////
IMPLEMENT_FUNCTION(81, Anna, openFirebird)
	switch (savepoint.action) {
	default:
		break;

	case kActionNone:
		if (!Entity::updateParameter(params->param1, getState()->timeTicks, 180))
			break;

		getSound()->playSound(kEntityTrain, "LIB069", kVolumeFull);
		getLogic()->gameOver(kSavegameTypeIndex, 0, kSceneNone, true);
		break;

	case kActionCallback:
		switch (getCallback()) {
		default:
			break;

		case 1:
			getAction()->playAnimation(kEventCathCloseEggNoBackground);
			getAction()->playAnimation(kEventKronosGiveFirebird);

			if (getInventory()->hasItem(kItemWhistle))
				getLogic()->gameOver(kSavegameTypeIndex, 1, kSceneGameOverTrainExplosion, true);
			else if (getInventory()->get(kItemWhistle)->location == kObjectLocation1)
				getLogic()->gameOver(kSavegameTypeEvent2, kEventAnnaDialogGoToJerusalem, kSceneNone, true);
			else
				getLogic()->gameOver(kSavegameTypeEvent2, kEventAugustUnhookCarsBetrayal, kSceneGameOverTrainExplosion2, true);
			break;

		case 2:
			getInventory()->removeItem(kItemWhistle);
			getLogic()->playFinalSequence();
			break;
		}
		break;

	case kAction224309120:
		getProgress().isEggOpen = false;
		getState()->time = kTimeCityConstantinople;

		setCallback(1);
		setup_savegame(kSavegameTypeEvent, kEventKronosGiveFirebird);
		break;

	case kActionUseWhistle:
		getProgress().isEggOpen = false;
		setGlobalTimer(0);
		getState()->time = kTimeCityConstantinople;

		setCallback(2);
		setup_savegame(kSavegameTypeEvent, kEventFinalSequence);
		break;
	}
IMPLEMENT_FUNCTION_END

} // End of namespace LastExpress
