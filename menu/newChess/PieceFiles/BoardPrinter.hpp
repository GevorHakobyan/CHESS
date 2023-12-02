#ifndef BOARD_PRINTER_HPP
#define BOARD_PRINTER_HPP

#include "BoardView.hpp"
#include <memory>
#include <ncurses.h>
#include <optional>
#include <locale.h>
#include "PiecesPrinter.hpp"

using CursorPositon = std::pair<int, int>;

class BoardPrinter{
    public:
    BoardPrinter(BoardView&);
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
    std::unique_ptr<BoardView> m_board{nullptr};
    int m_boardSize{0};
    CursorPositon m_cursor;
    int m_activeSquare{0};
};
#endif