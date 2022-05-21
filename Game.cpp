#include "Game.h"
#include <iostream>

Game::Game(Interface* pUI, const char* filename, int filenameLen) : pUI(pUI)
{
}

void Game::update()
{
	std::cout << "Frame Rate: " << pUI->frameRate() << std::endl;
	std::cout << "Hover:    ( " << pUI->getHoverPosition().getX() << ", " << pUI->getHoverPosition().getY() << " )" << std::endl;
	std::cout << "Selected: ( " << pUI->getSelectPosition().getX() << ", " << pUI->getSelectPosition().getY() << " )" << std::endl;
	std::cout << "Previous: ( " << pUI->getPreviousPosition().getX() << ", " << pUI->getPreviousPosition().getY() << " )" << std::endl;

	auto selectPos = pUI->getSelectPosition();
	auto previousPos = pUI->getPreviousPosition();

	Piece* selectedPiece = nullptr;
	Piece* previousPiece = nullptr;

	if (selectPos.isValid())
		selectedPiece = board.get(selectPos);
	if (previousPos.isValid())
		previousPiece = board.get(previousPos);
	if (selectedPiece)
	{
		std::cout << selectedPiece->getLetter() << std::endl;
	}
	if (previousPiece)
	{
		std::cout << previousPiece->getLetter() << std::endl;
	}
	if (pUI->getHoverPosition().isValid())
	{
		std::cout << "( " << pUI->getHoverPosition().getX() << ", " << pUI->getHoverPosition().getY() << " )" << std::endl;
	}

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
