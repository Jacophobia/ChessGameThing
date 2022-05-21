#include "piece.h"
#include "board.h"

#include <iostream> 

std::vector<Move> Pawn::getMoves(Board* board) {
	std::vector<Move> moves;
	short int direction = isWhite() ? 1 : -1;
	Position posMove(position.getX(), position.getY() + direction);
	Position posCheck;
	Position posCapture;
	Move move;
	if (posMove.isValid() && board->get(posMove) == nullptr) {
		move.setSrc(position);
		move.setDes(posMove);
		move.setWhiteMove(isWhite());

		if (posMove.getY() == 1 || posMove.getY() == 8) {
			move.addPromotion();
		}
		moves.push_back(move);
	}
	if (getNMoves() == 0) {
		posMove = Position(position.getX(), position.getY() + direction * 2);
		posCheck = Position(position.getX(), position.getY() + direction);

		if (board->get(posMove) == nullptr && board->get(posCheck) == nullptr) {
			move.setSrc(position);
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			moves.push_back(move);
		}
	}
	for (const auto& i : { -1, 1 }) {
		// capture
		posMove = Position(position.getX() + i, position.getY() + direction);
		if (posMove.isValid() && board->get(posMove) != nullptr && !(board->get(posMove)->isWhite())) {
			move.setSrc(position);
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(posMove);
			if (posMove.getY() == 1 || posMove.getY() == 8) {
				move.addPromotion();
			}
			moves.push_back(move);
		}
		// en passant
		posMove = Position(position.getX() + i, position.getY() + direction);
		posCapture = Position(position.getX() + i, position.getY());
		if (posMove.isValid() && position.getY() == (isWhite() ? 5 : 4) 
				&& board->get(posCapture)
				&& board->get(posCapture)->getLetter() == 'p' 
				&& board->get(posCapture)->getNMoves() == 1 
				&& board->get(posCapture)->justMoved(board->getCurrentMove())) {
			move.setSrc(position);
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(posCapture);
			move.setEnPassant();
			moves.push_back(move);
		}
	}

	return moves;
}