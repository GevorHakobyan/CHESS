#ifndef PIECES_PRINTER_HPP
#define PIECES_PRINTER_HPP

#include "BoardView.hpp"
#include "Board.hpp"
#include <ncurses.h>
#include <memory>
#include <map>

using Map = std::unique_ptr<std::map<Location, Index>>;

class PiecesPrinter {
    public:
    PiecesPrinter(const PieceList&);
    void print(const SquareIdentity&);
    static void printCharacter(const wchar_t*, const Location&);
    void moveMapTo_View(Map&); 
    private:
    void getLocation(Location&, const SquareIdentity&, int);
    void setPieceMap(Location&);
    const PieceList& m_PieceList;
    Map m_PieceMap;
    static Index m_pieceIndex;
};
#endif //PIECES_PRINTER_HPP