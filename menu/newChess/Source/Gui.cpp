#include "Board.hpp"
#include "GUI.hpp"
#include <ncurses.h>

void printRow(Row&);
void printLine(std::array<std::string,3>&);
void printBoard(BoardMatrix&);

void Gui::drawBoard() {
    initscr();
    Board myChessBoard(8,8);
    BoardMatrix myBoardMatrix = myChessBoard.getBoard();
    printBoard(myBoardMatrix);
    refresh();
    getch();
    endwin();
}

void printRow(Row& row) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < row.size(); ++j) {
            printLine(row[j][i]);
            wrefresh(stdscr);
        }
        printw("\n");
        wrefresh(stdscr);
    }
}

void printLine(std::array<std::string, 3>& line) {
    for (auto square : line) {
         printw("%s ", square.c_str());
         wrefresh(stdscr);
    }
    printw(" ");
    wrefresh(stdscr);
}

void printBoard(BoardMatrix& myBoard) {
      for (int i = 0; i < myBoard.size(); ++i) {
        printRow(myBoard[i]);
        printw("\n");
        wrefresh(stdscr);
    }
}