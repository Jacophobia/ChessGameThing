#include "Game.h"

Game::Game(Interface* pUI, const char* filename, int filenameLen) : pUI(pUI)
{
}

void Game::update()
{
	//auto selectedPiece = board.get(pUI->getSelectPosition());
	//auto previousPiece = board.get(pUI->getPreviousPosition());

	//if (!(selectedPiece && previousPiece))
	//	pUI->clearSelectPosition();

}

void Game::draw()
{
	board.draw(gout, pUI->getSelectPosition(), pUI->getHoverPosition());
}

void Game::reset()
{
	board.reset();
}

bool Game::isDone()
{
	return false;
}
