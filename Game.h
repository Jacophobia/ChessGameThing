#pragma once

#include "uiDraw.h"
#include "uiInteract.h"
#include "Board.h"

class Game
{
public:
	Game(Interface* pUI, const char * filename = "", int filenameLen = 0);
	void update();
	void draw();
	void reset();
	bool isDone();
private:
	ogstream gout;
	Interface* pUI;
	Board board;
};

