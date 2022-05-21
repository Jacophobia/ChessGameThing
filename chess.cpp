#include <iostream>

#include "TestRunner.h"
#include "uiInteract.h"
#include "Game.h"
#include "uiDraw.h"
#include "TestRunner.h"

#define DEBU

void callBack(Interface * pUI, void* pGame)
{
    Game* game = (Game*)pGame;

    game->update();
    game->draw();
    if (game->isDone())
        game->reset();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char** argv)
{
#ifdef DEBUG
    TestRunner test;
    test.run();
    return 0;
#endif
    Interface ui("Chess");
    Game game(&ui, argv[1], argc);
    ui.run(callBack, &game);

    return 0;
}
