#ifndef PIECE_FACTORY_HPP
#define PIECE_FACTORY_HPP

#include "Knight.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include <vector>

using  PieceList = std::array<std::array<std::unique_ptr<Piece>,8>,8>;

class Board {
    public:
    static Board* getInstance();
    Board(Board&) =  delete;
    Board& operator=(const Board&) = delete;
    const PieceList& getPieceList() const;
    private:
    Board();
    void setWhitePieces();
    void setBlackPieces();
    static Board* m_Board;
    PieceList m_pieceList{};
};
#endif