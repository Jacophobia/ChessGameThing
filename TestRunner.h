#pragma once

#include "TestPawn.h"
#include "TestBoard.h"


class TestRunner
{
public:
	void run()
	{
		runTestBoard();
		runTestPawn();
	}
private:
	void runTestBoard()
	{
		TestBoard test;
		test.run();
	}
	void runTestPawn()
	{
		TestPawn test;
		test.run();
	}
};