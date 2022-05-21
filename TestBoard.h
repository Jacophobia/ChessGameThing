//
// Created by Jacob on 5/7/2022.
//

#pragma once

#include <memory>
#include <cassert>

#include "Board.h"
#include "Piece.h"

class TestBoard
{
public:
    void run()
    {
        test_getCurrentMove_moveZero();
        test_getCurrentMove_moveOne();
        test_getCurrentMove_highMove();
        test_isWhiteTurn_moveZero();
        test_isWhiteTurn_moveOne();
        test_isWhiteTurn_highMove();
        test_swap_bottomLeftWithTopRight();
        test_swap_pieceWithNull();
        test_swap_nullWithNull();
        test_reset();
        test_move();
        test_get_bottomLeft();
        test_get_topRight();
        test_destruct();
        test_clear();
    }
private:
    void test_getCurrentMove_moveZero()
    {
        // setup
        Board board;
        board.currentMove = 0;
        // exercise
        int result = board.getCurrentMove();
        // verify
        assert(result == 1); // we want the turn number to begin at one, but the stored value will begin at zero for fidelity purposes
    }  // teardown

    void test_getCurrentMove_moveOne()
    {
        // setup
        Board board;
        board.currentMove = 1;
        // exercise
        int result = board.getCurrentMove();
        // verify
        assert(result == 2);
    }  // teardown

    void test_getCurrentMove_highMove()
    {
        // setup
        Board board;
        board.currentMove = 999;
        // exercise
        int result = board.getCurrentMove();
        // verify
        assert(result == 1000);
    }  // teardown

    void test_isWhiteTurn_moveZero()
    {
        // setup
        Board board;
        board.currentMove = 0;
        // exercise
        bool result = board.isWhiteTurn();
        // verify
        assert(result == true);
    }  // teardown

    void test_isWhiteTurn_moveOne()
    {
        // setup
        Board board;
        board.currentMove = 1;
        // exercise
        bool result = board.isWhiteTurn();
        // verify
        assert(result == false);
    }  // teardown

    void test_isWhiteTurn_highMove()
    {
        // setup
        Board board;
        board.currentMove = 999;
        // exercise
        bool result = board.isWhiteTurn();
        // verify
        assert(result == false);
    }  // teardown

    void test_swap_bottomLeftWithTopRight()
    {
        // setup
        Board board;
        setupStandardFixture(board);

        Position pos1(1, 1); // id of 1
        Position pos2(8, 8); // id of 4
        // exercise
        board.swap(pos1, pos2);
        // verify
        assert(board.board[0] != nullptr);
        assert(board.board[63] != nullptr);
        assert(board.board[0]->id == 4);
        assert(board.board[63]->id == 1);
        // teardown
        teardownStandardFixture(board);
    }
    void test_swap_pieceWithNull()
    {
        // setup
        Board board;
        setupStandardFixture(board);

        Position pos1(1, 1); // id of 1
        Position pos2(2, 1); // id of 4
        // exercise
        board.swap(pos1, pos2);
        // verify
        assert(board.board[0] == nullptr);
        assert(board.board[1] != nullptr);
        assert(board.board[1]->id == 1);
        // teardown
        teardownStandardFixture(board);
    }
    void test_swap_nullWithNull()
    {
        // setup
        Board board;
        setupStandardFixture(board);

        Position pos1(2, 1);
        Position pos2(3, 1);
        // exercise
        board.swap(pos1, pos2);
        // verify
        assert(board.board[1] == nullptr);
        assert(board.board[2] == nullptr);
        // teardown
        teardownStandardFixture(board);
    }

    void test_reset()
    {
        // setup
        Board board;
        setupStandardFixture(board);
        // exercise
        board.reset();
        // verify
        int i = 0;
        for (; i < 16; i++)
            assert(board.board[i] != nullptr);
        for (; i < 48; i++)
            assert(board.board[i] == nullptr);
        for (; i < 64; i++)
            assert(board.board[i] != nullptr);
        // teardown
        teardownStandardFixture(board);
    }

    void test_move()
    {
        // setup
        Board board;
        Move move;
        move.setSrc(Position(1, 1));
        move.setDes(Position(2, 1));
        setupStandardFixture(board);
        // exercise
        board.move(move);
        // verify
        assert(board.board[0] == nullptr);
        assert(board.board[1] != nullptr);
        assert(board.board[1]->id == 1);
        // teardown
        teardownStandardFixture(board);
    }

    void test_get_bottomLeft()
    {
        // setup
        Board board;
        Position bottomLeft(1, 1);
        setupStandardFixture(board);
        // exercise
        Piece* result = board.get(bottomLeft);
        // verify
        assert(result != nullptr);
        assert(result->id == 1);
        // teardown
        teardownStandardFixture(board);
    }
    void test_get_topRight()
    {
        // setup
        Board board;
        Position topRight(8, 8);
        setupStandardFixture(board);
        // exercise
        Piece* result = board.get(topRight);
        // verify
        assert(result != nullptr);
        assert(result->id == 4);
        // teardown
        teardownStandardFixture(board);
    }

    void test_destruct()
    {
        // setup
        Board* board;
        std::allocator<Board> alloc;
        board = alloc.allocate(1);
        alloc.construct(board);

        setupStandardFixture(*board);
        // exercise
        alloc.destroy(board);
        // verify
        assertEmptyFixture(*board);
        // teardown
        teardownStandardFixture(*board);
        alloc.deallocate(board, 1);
    }

    void test_clear()
    {
        // setup
        Board board;
        setupStandardFixture(board);
        // exercise
        board.clear();
        // verify
        assertEmptyFixture(board);
        // teardown
        teardownStandardFixture(board);
    }

    void setupStandardFixture(Board& board)
    {
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   | 4 |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   | 2 | 3 |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  | 1 |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        teardownStandardFixture(board);

        Piece* piece1 = new Piece();
        Piece* piece2 = new Piece();
        Piece* piece3 = new Piece();
        Piece* piece4 = new Piece();

        // Since Piece is not the class under test here, we are using a
        // dummy in the place of piece so that we can test the
        // functionality of the board class without relying on a
        // functional Piece class. ID is not going to be one of Pieces
        // final member variables, but is used only in this mock.
        piece1->id = 1;
        piece2->id = 2;
        piece3->id = 3;
        piece4->id = 4;

        board.board[0] = piece1;
        board.board[35] = piece2;
        board.board[36] = piece3;
        board.board[63] = piece4;
    }

    void teardownStandardFixture(Board& board)
    {
        for (Piece*& piece : board.board)
        {
            if (piece != nullptr)
            {
                delete piece;
                piece = nullptr;
            }
        }
    }

    void assertEmptyFixture(Board& board)
    {
        for (Piece*& piece : board.board)
        {
            assert(piece == nullptr);
        }
    }
};
