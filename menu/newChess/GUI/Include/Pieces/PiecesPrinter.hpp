#ifndef PIECES_PRINTER_HPP
#define PIECES_PRINTER_HPP

#include "PieceFactory.hpp"
#include "BoardPrinter.hpp"
#include <ncurses.h>

class PiecesPrinter {
    public:
    PiecesPrinter() = default;
    static void print(const SquareIdentity&);
};

#endif