#include <iostream>

#include "TestRunner.h"
#include "uiInteract.h"
#include "Game.h"
#include "uiDraw.h"       // for draw*
#include "TestRunner.h"   // for Running Tests
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING

using namespace std;


#define DEBU

void callBack(Interface * interface, void* pGame)
{
    Game* game = (Game*)pGame;

    game->update();
    game->draw();
    if (game->isDone())
        game->reset();
}

/********************************************************
 * READ FILE
 * Read a file where moves are encoded in Smith notation
 *******************************************************/
void readFile(const char* fileName, char* board)
{
    //// open the file
    //ifstream fin(fileName);
    //if (fin.fail())
    //    return;

    //// read the file, one move at a time
    //string textMove;
    //bool valid = true;
    //while (valid && fin >> textMove)
    //{
    //    int positionFrom;
    //    int positionTo;
    //    parse(textMove, positionFrom, positionTo);
    //    valid = move(board, positionFrom, positionTo);
    //}

    //// close and done
    //fin.close();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PSTR pCmdLine,
    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
#ifdef DEBUG
    TestRunner test;
    test.run();
    return 0;
#endif
    Interface ui("Chess");

#ifdef _WIN32
//    //  int    argc;
//    //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
//    //  string filename = argv[1];
    Game game(&ui, __argv[1], __argc);
#else // !_WIN32
    Game game(&ui, argv[1], argc);
#endif // !_WIN32

    // set everything into action
    ui.run(callBack, &game);

    return 0;
}
