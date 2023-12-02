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

using PieceList = std::array<std::unique_ptr<Piece>, 16>;
class PieceFactory {
    public:
    PieceFactory();
    PieceList& getWhitePieces();
    PieceList& getBlackPieces();
    private:
    void setBlackPieces();
    void setWhitePieces();
    private:
    PieceList m_blackPieces{};
    PieceList m_whitePieces{};
};
#endif