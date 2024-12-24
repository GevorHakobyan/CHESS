#ifndef BOARD_HPP
#define BOARD_HPP

#include "Knight.hpp"
#include "Piece.hpp"
#include "Bishop.hpp"
#include "King.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include <array>
#include "Rook.hpp"
#include <map>
#include <vector>

using  PieceList = std::array<std::array<std::unique_ptr<Piece>,8>,8>;
using Location = std::pair<int, int>;
using Index = std::pair<int, int>;
enum class PieceTypes{Rook, Queen, Knight};

class Board {
    public:
    using Color = Piece::Color;
    static Board* getInstance();
    Board(Board&) =  delete;
    Board& operator=(const Board&) = delete;
    const PieceList& getPieceList() const;
    std::pair<bool, Color> isEmpty(Index);
    void updateMatrix(Index&, Index&);
    void updatePieceData(Location&);
    //SPECIAL CASE
    void swapPawnWith(const Index&, wchar_t*, const Index&);
    PieceTypes determineCharacter(const wchar_t*);

    private: 
    ~Board();
    Board();
    void setWhitePieces();
    void setBlackPieces();
    
    static Board* m_Board;
    PieceList m_pieceList;
};
#endif 