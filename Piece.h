#pragma once
#include "Position.h"
#include "uiDraw.h"
#include "Move.h"
#include <vector>


class Piece {
private:
	friend class TestPawn;
	bool fWhite = true;
	unsigned int nMoves = 0;
	unsigned int lastMove;
protected:
	Position position;
public:
	int id = -1;
	Piece() {

	}
	Piece(int x, int y, bool isWhite) {
		position = Position(x, y);
		fWhite = isWhite;
	}
	Piece(Position pos, bool isWhite) : Piece(pos.getX(), pos.getY(), isWhite) {}

	void assign(Piece & rhs) {
		position = rhs.getPosition();
		fWhite = rhs.isWhite();
		nMoves = rhs.getNMoves();
		lastMove = rhs.getLastMove();
	}

	void move(Position pos, int totalMoves) {
		position = pos;
		nMoves += 1;
		lastMove = totalMoves;
	}

	bool isWhite() { return fWhite; };
	int getNMoves() { return nMoves; }
	int getLastMove() { return lastMove; }
	Position getPosition() { return position; }
	bool justMoved(int moves) { return lastMove == moves - 1; }
	virtual char getLetter() { return '0'; }
	virtual std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	virtual void draw(ogstream& gout) {}
	
};

class Pawn : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'p'; }
	std::vector<Move> getMoves(Board* board);
	void draw(ogstream & gout)
	{
		gout.drawPawn(getPosition(), !isWhite());
	}
};

class King : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'k'; }
	std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	void draw(ogstream & gout)
	{
		gout.drawKing(getPosition(), !isWhite());
	}
};

class Queen : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'q'; }
	std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	void draw(ogstream & gout)
	{
		gout.drawQueen(getPosition(), !isWhite());
	}
};

class Bishop : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'b'; }
	std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	void draw(ogstream & gout)
	{
		gout.drawBishop(getPosition(), !isWhite());
	}
};

class Knight : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'n'; }
	std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	void draw(ogstream & gout)
	{
		gout.drawKnight(getPosition(), !isWhite());
	}
};

class Rook : public Piece {
public:
	using Piece::Piece;
	char getLetter() { return 'r'; }
	std::vector<Move> getMoves(Board* board) {
		std::vector<Move> moves = {};
		return moves;
	}
	void draw(ogstream & gout)
	{
		gout.drawRook(getPosition(), !isWhite());
	}
};