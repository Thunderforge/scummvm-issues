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

#ifndef TESTBED_FS_H
#define TESTBED_FS_H

#include "common/fs.h"

#include "testbed/testsuite.h"

namespace Testbed {

namespace FStests {

// Note: These tests require a game-data directory
// So would work if game-path is set in the launcher or invoked as ./scummvm --path="path-to-testbed-data" testbed
// from commandline

// Helper functions for FS tests
bool readDataFromFile(Common::FSDirectory *directory, const char *file);

// will contain function declarations for FS tests
TestExitStatus testReadFile();
TestExitStatus testWriteFile();
TestExitStatus testCreateDir();
TestExitStatus testOpeningSaveFile();
// add more here

} // End of namespace FStests

class FSTestSuite : public Testsuite {
public:
	/**
	 * The constructor for the FSTestSuite
	 * For every test to be executed one must:
	 * 1) Create a function that would invoke the test
	 * 2) Add that test to list by executing addTest()
	 *
	 * @see addTest()
	 */
	FSTestSuite();
	~FSTestSuite() override {}
	const char *getName() const override {
		return "FS";
	}
	const char *getDescription() const override {
		return "File system tests (Navigation, Read/Write)";
	}
	void enable(bool flag) override;
};

} // End of namespace Testbed

#endif // TESTBED_FS_H
