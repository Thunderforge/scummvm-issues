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

#include "bladerunner/script/ai_script.h"

namespace BladeRunner {

AIScriptLance::AIScriptLance(BladeRunnerEngine *vm) : AIScriptBase(vm) {
}

void AIScriptLance::Initialize() {
	_animationFrame = 0;
	_animationState = 0;
	_animationStateNext = 0;
	_animationNext = 0;
}

bool AIScriptLance::Update() {
	return false;
}

void AIScriptLance::TimerExpired(int timer) {
	//return false;
}

void AIScriptLance::CompletedMovementTrack() {
	//return false;
}

void AIScriptLance::ReceivedClue(int clueId, int fromActorId) {
	//return false;
}

void AIScriptLance::ClickedByPlayer() {
	//return false;
}

void AIScriptLance::EnteredSet(int setId) {
	// return false;
}

void AIScriptLance::OtherAgentEnteredThisSet(int otherActorId) {
	// return false;
}

void AIScriptLance::OtherAgentExitedThisSet(int otherActorId) {
	// return false;
}

void AIScriptLance::OtherAgentEnteredCombatMode(int otherActorId, int combatMode) {
	// return false;
}

void AIScriptLance::ShotAtAndMissed() {
	// return false;
}

bool AIScriptLance::ShotAtAndHit() {
	return false;
}

void AIScriptLance::Retired(int byActorId) {
	// return false;
}

int AIScriptLance::GetFriendlinessModifierIfGetsClue(int otherActorId, int clueId) {
	return 0;
}

bool AIScriptLance::GoalChanged(int currentGoalNumber, int newGoalNumber) {
	return false;
}

bool AIScriptLance::UpdateAnimation(int *animation, int *frame) {
	return true;
}

bool AIScriptLance::ChangeAnimationMode(int mode) {
	return true;
}

void AIScriptLance::QueryAnimationState(int *animationState, int *animationFrame, int *animationStateNext, int *animationNext) {
	*animationState     = _animationState;
	*animationFrame     = _animationFrame;
	*animationStateNext = _animationStateNext;
	*animationNext      = _animationNext;
}

void AIScriptLance::SetAnimationState(int animationState, int animationFrame, int animationStateNext, int animationNext) {
	_animationState     = animationState;
	_animationFrame     = animationFrame;
	_animationStateNext = animationStateNext;
	_animationNext      = animationNext;
}

bool AIScriptLance::ReachedMovementTrackWaypoint(int waypointId) {
	return true;
}

void AIScriptLance::FledCombat() {
	// return false;
}

} // End of namespace BladeRunner
