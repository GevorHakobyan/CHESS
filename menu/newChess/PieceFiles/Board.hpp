#ifndef BOARD_HPP
#define BOARD_HPP

#include "Knight.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include <ncurses.h>
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
    std::pair<bool, Color> isEmpty(Index);
    void updateMatrix(Index&, Index&);
    void updatePieceData(Location&);

    private: 
    ~Board();
    Board();
    void setWhitePieces();
    void setBlackPieces();
    
    static Board* m_Board;
    int a{0};
    PieceList m_pieceList;
};
#endif 