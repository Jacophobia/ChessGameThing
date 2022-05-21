#pragma once
#include "position.h"

class Board;

class Move {
private:
	Position source;
	Position destination;
	Position capturePos;
	bool promotion = false;
	bool whiteMove = true;
	bool enPassant = false;
public:
	void setSrc(Position pos) {
		source = pos;
	}
	void setDes(Position pos) {
		destination = pos;
	}
	void setCapture(Position pos) {
		capturePos = pos;
	}
	void addPromotion() {
		promotion = true;
	}
	void setEnPassant() {
		enPassant = true;
	}
	void setWhiteMove(bool isWhite) {
		whiteMove = isWhite;
	}
	Position getSrc() { return source; }
	Position getDes() { return destination; }
	void complete(Board* board) {}
	bool Move::operator==(Move rhs) {
		return source == rhs.getSrc() && destination == rhs.getDes();
	}
};