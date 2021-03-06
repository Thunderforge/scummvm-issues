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

#include "mutationofjb/tasks/sequentialtask.h"

#include "mutationofjb/tasks/taskmanager.h"

namespace MutationOfJB {

SequentialTask::SequentialTask(const TaskPtrs &tasks) : _tasks(tasks) {
}

void SequentialTask::start() {
	setState(RUNNING);
	runTasks();
}

void SequentialTask::update() {
	runTasks();
}

void SequentialTask::runTasks() {
	while (true) {
		if (_tasks.empty()) {
			setState(FINISHED);
			return;
		}

		const TaskPtr &task = _tasks.front();
		switch (task->getState()) {
		case IDLE:
			getTaskManager()->startTask(task);
			break;
		case RUNNING:
		default:
			return;
		case FINISHED:
			_tasks.remove_at(0);
			break;
		}
	}
}

}
