//
// Created by Jacob on 5/7/2022.
//

#pragma once

#include <array>
#include <cassert>

#include "Piece.h"
#include "Position.h"
#include "Move.h"

class Board
{
public:
    Board(/* ogstream gout, reset */) : board()
    {
        setup();
    }
    Board(const Board& rhs)
    {
        // safely delete everything
        clear();
        // copy the right hand side
        board = rhs.board;
        currentMove = rhs.currentMove;
    }
    ~Board()
    {
        clear();
    }
    unsigned int getCurrentMove() const
    {
        return currentMove + 1;
    }
    bool isWhiteTurn()
    {
        return getCurrentMove() % 2;
    }
    Piece* get(Position pos) 
    { 
        return at(pos);
    }
    void reset() 
    {
        clear();
        setup();
        currentMove = 0;
    }
    void move(Move move);
    void draw(ogstream & gout, Position selectPos, Position hoverPos);
private:
    std::array<Piece*, 64> board;
    unsigned int currentMove;

    Piece*& at(int x, int y) 
    {
        return board[(x - 1) + ((y - 1) * 8)];
    }

    Piece*& at(Position pos)
    {
        return at(pos.getX(), pos.getY());
    }

    void swap(Position pos1, Position pos2);


    void clear();
    void setup();
    friend class TestBoard;
    friend class TestPawn;
};