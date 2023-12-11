#ifndef BOARD_HPP
#define BOARD_HPP

class BarriersHandler;

#include "Knight.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include <ncurses.h>
///#include "AbstractHandler.hpp"
//#include "BarriersHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "PieceExistanceHandler.hpp"
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
    void movePiece(Location, Location);
    void setMap(Location&, Index&);
    std::pair<bool, Color> isEmpty(Location);
    std::map<Location, Index> m_PieceMap;
    bool isZero(const Location&, const Location&);
    private:
    ~Board();
    Board();
    void setWhitePieces();
    void setBlackPieces();
    
    static Board* m_Board;
    PieceList m_pieceList;
    PieceExistanceHandler* m_ExistanceHandler{nullptr};
    AvailableCoordinates_Handler* m_AvailableHandler{nullptr};
};
#endif