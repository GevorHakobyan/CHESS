#include "Board.hpp"
#include <iostream>

void StartRowWithBlack(Row&);
void StartRowWithWhite(Row&);
void fillBlack(Square&);
void fillWhite(Square&);

Board::Board(int rows, int colums)
: m_colums{colums}, m_rows{rows}  
{
    buildBoard();
    fillLetters();
    fillNumbers();
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

Letters Board::getLetters() const {
    return m_letters;
}

Numbers Board::getNumbers() const {
    return m_numbers;
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
    for (auto& row : square) {
        row.fill(L"\u25A1");
    }
}

void fillWhite(Square& square) {
    for (auto& row : square) {
        row.fill(L"\u25A0");
    }
}

void Board::fillLetters() {
    int elem = 65;
    for (int i = 0; i < m_rows; ++i) {
        m_letters.push_back(elem);
        ++elem;
    }
}

 void Board::fillNumbers() {
    int elem {1};
    for (int i = 0; i < m_colums; ++i) {
        m_numbers.push_back(elem);
        ++elem;
    }
 }   

void Board::setSquareIdentity(std::tuple<int, int, int> value) {
    m_squaresIdentity[std::get<2>(value)] = value;
}

const SquareIdentity& Board::getSquaresIdentity() const {
    return m_squaresIdentity;
}