#pragma once
//
// Created by Brandon on 5/7/2022.
//


#include <memory>
#include <cassert>
#include <algorithm>
#include "Board.h"
#include "Piece.h"

class TestPawn
{
public:
    void run() {
        test_constructor();
        test_move();
        test_assign();
        test_isWhite_success();
        test_isWhite_failure();
        test_nMoves_none();
        test_nMoves_one();
        test_nMoves_high();
        test_justMoved_failure();
        test_justMoved_success();
        test_getMoves_wPawnCanMoveForward();
        test_getMoves_bPawnCanMoveBackward();
        test_getMoves_wPawnCanMoveTwo();
        test_getMoves_bPawnCanMoveTwo();
        test_getMoves_wPawnCanNotMoveTwo();
        test_getMoves_bPawnCanNotMoveTwo();
        test_getMoves_captureForward();
        test_getMoves_captureDiagonel();
        test_getMoves_moveDiagonel();
        test_getMoves_enPassant();
    }
private:
    void test_constructor() {
        // setup, exercise
        Pawn piece(1, 1, true);
        // assert
        assert(piece.getLetter() == 'p');
        assert(piece.getPosition() == Position(1, 1));
    } // teardown

    void test_move() {
        // setup
        Pawn piece(1, 1, true);
        // exercise
        piece.move(Position(2, 2), 5);
        // assert
        assert(piece.position == Position(2, 2));
        assert(piece.nMoves == 1);
        assert(piece.lastMove == 5);
        // teardown
    }

    void test_assign() {
        // setup
        Piece board[1];
        Pawn pawn(5, 5, true);
        board[0] = pawn;
        Queen queen;
        // exercise
        queen.assign(pawn);
        // assert
        assert(queen.getLetter() == 'q');
        assert(pawn.position == Position(5, 5));
        assert(pawn.fWhite == true);
        // teardown
    }

    void test_isWhite_success() {
        // setup, exercise
        Pawn piece(1, 1, true);
        // assert
        assert(piece.isWhite() == true);
        // teardown
    }

    void test_isWhite_failure() {
        // setup, exercise
        Pawn piece(1, 1, false);
        // assert
        assert(piece.isWhite() == false);
        // teardown
    }

    void test_nMoves_none() {
        // setup, exercise
        Pawn piece(1, 1, true);
        // assert
        assert(piece.getNMoves() == 0);
        // teardown
    }

    void test_nMoves_one() {
        // setup
        Pawn piece(1, 1, true);
        // exercise
        piece.move(Position(1, 2), 1);
        // assert
        assert(piece.getNMoves() == 1);
    }

    void test_nMoves_high() {
        // setup
        Pawn piece(1, 1, true);
        // exercise
        piece.nMoves = 999;
        // assert
        assert(piece.getNMoves() == 999);
        // teardown
    }

    void test_justMoved_failure() {
        // setup, exercise
        Pawn piece(1, 1, true);
        // assert
        assert(piece.justMoved(1) == false);
        // teardown
    }

    void test_justMoved_success() {
        // setup
        Pawn piece(1, 1, true);
        // exercise
        piece.move(Position(1, 2), 1);
        // assert
        assert(piece.justMoved(2) == true);
    }

    void test_getMoves_wPawnCanMoveForward() {
        // setup
        Pawn piece(1, 1, true);
        Board board;
        board.clear();
        Move move;
        move.setSrc(Position(1, 1));
        move.setDes(Position(1, 2));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 1));
        move1.setDes(Position(1, 2));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end());
        assert(*it == move1);
        // teardown
    }

    void test_getMoves_bPawnCanMoveBackward() {
        // setup
        Pawn piece(1, 8, false);
        Board board;
        board.clear();
        Move move;
        move.setSrc(Position(1, 8));
        move.setDes(Position(1, 7));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 8));
        move1.setDes(Position(1, 7));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end());
        assert(*it == move1);
        // teardown
    }

    void test_getMoves_wPawnCanMoveTwo() {
        // setup
        Pawn piece(1, 1, true);
        Board board;
        board.clear();
        Move move;
        move.setSrc(Position(1, 1));
        move.setDes(Position(1, 3));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 1));
        move1.setDes(Position(1, 3));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end());
        assert(*it == move1);
        // teardown
    }

    void test_getMoves_bPawnCanMoveTwo() {
        // setup
        Pawn piece(1, 8, false);
        Board board;
        board.clear();
        Move move;
        move.setSrc(Position(1, 8));
        move.setDes(Position(1, 6));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 8));
        move1.setDes(Position(1, 6));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end());
        assert(*it == move1);
        // teardown
    }

    void test_getMoves_wPawnCanNotMoveTwo() {
        // setup
        Pawn piece(1, 1, true);
        Board board;
        board.clear();
        Move move;
        piece.move(Position(1, 7), 1);
        move.setSrc(Position(1, 2));
        move.setDes(Position(1, 4));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 2));
        move1.setDes(Position(1, 4));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it == possibleMoves.end()); // invalid move
        // teardown
    }

    void test_getMoves_bPawnCanNotMoveTwo() {
        // setup
        Pawn piece(1, 8, false);
        Board board;
        board.clear();
        Move move;
        piece.move(Position(1, 7), 1);
        move.setSrc(Position(1, 7));
        move.setDes(Position(1, 5));
        move.complete(&board);
        // exercise
        auto possibleMoves = piece.getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(1, 7));
        move1.setDes(Position(1, 5));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it == possibleMoves.end()); // invalid move
        // teardown
    }

    void test_getMoves_captureForward() {
        // setup
        Board board;
        setupStandardFixture(board);
        Piece *wPawn = board.board[36];
        Move move;
        move.setSrc(Position(5, 5));
        move.setDes(Position(5, 6));
        move.complete(&board);
        // exercise
        auto possibleMoves = wPawn->getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(5, 5));
        move1.setDes(Position(5, 6));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it == possibleMoves.end()); // invalid move
        // teardown
        teardownStandardFixture(board);
    }

    void test_getMoves_captureDiagonel() {
        // setup
        Board board;
        setupStandardFixture(board);
        Piece* wPawn = board.board[36];
        Move move;
        move.setSrc(Position(5, 5));
        move.setDes(Position(4, 6));
        move.complete(&board);
        // exercise
        auto possibleMoves = wPawn->getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(5, 5));
        move1.setDes(Position(4, 6));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end()); 
        assert(*it == move1);
        // teardown
        teardownStandardFixture(board);
    }

    void test_getMoves_moveDiagonel() {
        // setup
        Board board;
        setupStandardFixture(board);
        Piece* wPawn = board.board[36];
        Move move;
        move.setSrc(Position(5, 5));
        move.setDes(Position(6, 6));
        move.complete(&board);
        // exercise
        auto possibleMoves = wPawn->getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(5, 5));
        move1.setDes(Position(6, 6));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it == possibleMoves.end());
        // teardown
        teardownStandardFixture(board);
    }

    void test_getMoves_enPassant() {
        // setup
        Board board;
        setupStandardFixture(board);
        Piece* wPawn = board.board[36];
        Move move;
        Piece* bPawn = board.board[53];
        Move bMove;
        bMove.setSrc(Position(6, 7));
        bMove.setDes(Position(6, 5));
        board.move(bMove);
        move.setSrc(Position(5, 5));
        move.setDes(Position(6, 6));
        move.complete(&board);
        
        // exercise
        auto possibleMoves = wPawn->getMoves(&board);
        // assert
        auto it = std::find(possibleMoves.begin(), possibleMoves.end(), move);
        Move move1;
        move1.setSrc(Position(5, 5));
        move1.setDes(Position(6, 6));
        move1.complete(&board);
        assert(move == move1); // move didn't change
        assert(it != possibleMoves.end());
        assert(*it == move1);
        // teardown
        teardownStandardFixture(board);
    }

    void setupStandardFixture(Board& board)
    {
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   | p |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   | p | p |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   | P |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        //  |   |   |   |   |   |   |   |   |
        //  + - + - + - + - + - + - + - + - +
        board.clear();
        Pawn* wPawn = new Pawn(5, 5, true);
        Pawn* bPawn1 = new Pawn(4, 6, false);
        Pawn* bPawn2 = new Pawn(5, 6, false);
        Pawn* bPawn3 = new Pawn(6, 7, false);

        board.board[36] = wPawn;
        board.board[43] = bPawn1;
        board.board[44] = bPawn2;
        board.board[53] = bPawn3;
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
};