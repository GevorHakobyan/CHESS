#ifndef PIECES_PRINTER_HPP
#define PIECES_PRINTER_HPP

#include "BoardView.hpp"
#include "Board.hpp"
#include <ncurses.h>

class PiecesPrinter {
    public:
    PiecesPrinter() = default;
    void print(const SquareIdentity&);
    static void printPiece(const wchar_t*, const Location&);
    static void printAvailables();
    private:
    void getLocation(Location&, const SquareIdentity&, int);
    void setBoardMap(Location&, Board*);
    static Index m_pieceIndex;
};

#endif