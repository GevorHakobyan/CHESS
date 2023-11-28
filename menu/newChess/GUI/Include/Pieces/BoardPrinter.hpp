#ifndef BOARD_PRINTER_HPP
#define BOARD_PRINTER_HPP

#include "Board.hpp"
#include <memory>
#include <ncurses.h>
#include <optional>
#include <locale.h>
#include "PiecesPrinter.hpp"

using CursorPositon = std::pair<int, int>;

class BoardPrinter{
    public:
    BoardPrinter(Board&);
    void Print();
    private:
    void printRow(Row&, int);
    void printSquareLine(std::array<const wchar_t*,3>&, int);
    void printBoardLine(Row&, int);
    void printMatrix(); 
    void printRowNumber(int);
    void printColumLetter();
    void printPeaces();

    void setCursorLocation();
    CursorPositon getCursorLocation();
    void setSquareLocations(int);

    private:
    std::unique_ptr<Board> m_board{nullptr};
    int m_boardSize{0};
    CursorPositon m_cursor;
    int m_activeSquare{0};
};
#endif