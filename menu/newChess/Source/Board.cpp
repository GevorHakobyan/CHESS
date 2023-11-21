#include "Board.hpp"

void StartRowWithBlack(Row&);
void StartRowWithWhite(Row&);
void fillBlack(Square&);
void fillWhite(Square&);

Board::Board(int rows, int colums)
: m_colums{colums}, m_rows{rows}  
{
    buildBoard();
}

void Board::buildBoard() {
    for (int i = 0; i < m_board.size() - 1; i += 2) {
        StartRowWithBlack(m_board[i]);
        StartRowWithWhite(m_board[i + 1]);
    } 
}

BoardMatrix Board::getBoard() const {
    return m_board;
}

void StartRowWithBlack(Row& row) {
  for (int i = 0; i < row.size() - 1; i += 2) {
    fillBlack(row[i]);
    fillWhite(row[i + 1]);
  }
}

 void StartRowWithWhite(Row& row) {
     for (int i = 0; i < row.size() - 1; i += 2) {
    fillWhite(row[i]);
    fillBlack(row[i + 1]);
  }
 }

void fillBlack(Square& square) {
    for (auto row : square) {
        row.fill("\u25A1");
    }
}

void fillWhite(Square& square) {
    for (auto row : square) {
        row.fill("\u25A0");
    }
}