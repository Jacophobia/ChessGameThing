#include "Board.h"

void Board::setup() 
{
    board = {
        new Rook(1, 8, false), new Bishop(2, 8, false), new Knight(3, 8, false), new King(4, 8, false), new Queen(5, 8, false), new Knight(6, 8, false), new Bishop(7, 8, false), new Rook(8, 8, false),
        new Pawn(1, 7, false), new   Pawn(2, 7, false), new   Pawn(3, 7, false), new Pawn(4, 7, false), new  Pawn(5, 7, false), new   Pawn(6, 7, false), new   Pawn(7, 7, false), new Pawn(8, 7, false),
               nullptr,                 nullptr,                 nullptr,               nullptr,                nullptr,                 nullptr,                 nullptr,               nullptr,
               nullptr,                 nullptr,                 nullptr,               nullptr,                nullptr,                 nullptr,                 nullptr,               nullptr,
               nullptr,                 nullptr,                 nullptr,               nullptr,                nullptr,                 nullptr,                 nullptr,               nullptr,
               nullptr,                 nullptr,                 nullptr,               nullptr,                nullptr,                 nullptr,                 nullptr,               nullptr,
        new Pawn(1, 2, true),  new   Pawn(2, 2, true),  new   Pawn(3, 2, true),  new Pawn(4, 2, true),  new  Pawn(5, 2, true),  new   Pawn(6, 2, true),  new   Pawn(7, 2, true),  new Pawn(8, 2, true),
        new Rook(1, 1, true),  new Bishop(2, 1, true),  new Knight(3, 1, true),  new King(4, 1, true),  new Queen(5, 1, true),  new Knight(6, 1, true),  new Bishop(7, 1, true),  new Rook(8, 1, true),
    };
}

void Board::clear() 
{
    for (Piece*& piece : board)
    {
        if (piece != nullptr)
        {
            delete piece;
            piece = nullptr;
        }
    }
}

void Board::swap(Position pos1, Position pos2) 
{
    auto temp = at(pos1);
    at(pos1) = at(pos2);
    at(pos2) = temp;
}

void Board::move(Move move) 
{
    Position src = move.getSrc();
    Position des = move.getDes();

    Piece* srcPiece = get(src);
    if (srcPiece == nullptr)
    {
        assert(false); // Validation shouldn't allow them to try to move nothing
        return;
    }
    Piece* desPiece = get(des);
    if (desPiece != nullptr)
    {
        if (desPiece->isWhite() == srcPiece->isWhite())
        {
            // They are matching colors making this an invalid move that should
            //  have been registered as invalid before this function was called
            assert(false);
            return;
        }
        delete desPiece;
    }
    at(des) = srcPiece;
    at(src) = nullptr;
    at(des)->move(des, getCurrentMove());
    currentMove++;
}

void Board::draw(ogstream & gout, Position selectPos, Position hoverPos)
{
    gout.drawBoard();
    gout.drawSelected(selectPos);
    gout.drawHover(hoverPos);
    for (auto& element : board)
    {
        if (element) {
            element->draw(gout);
        }
    }
}
