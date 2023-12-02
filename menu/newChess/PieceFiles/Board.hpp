#ifndef BOARD_HPP
#define BOARD_HPP

#include "Knight.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include <map>
#include <vector>

using  PieceList = std::array<std::array<std::unique_ptr<Piece>,8>,8>;
using Location = std::pair<int, int>;
using Index = std::pair<int, int>;

class Board {
    public:
    static Board* getInstance();
    Board(Board&) =  delete;
    Board& operator=(const Board&) = delete;
    const PieceList& getPieceList() const;
    void setMap(Location&, Index&);
    std::map<Location, Index> m_PieceMap;
    private:
    Board();
    void setWhitePieces();
    void setBlackPieces();
    static Board* m_Board;
    PieceList m_pieceList{};
};
#endif