#ifndef PIECES_PRINTER_HPP
#define PIECES_PRINTER_HPP

#include "BoardView.hpp"
#include "Board.hpp"
#include <ncurses.h>

class PiecesPrinter {
    public:
    PiecesPrinter() = default;
    static void print(const SquareIdentity&);
    static void printPiece(const wchar_t*, std::pair<int, int>);
};

#endif