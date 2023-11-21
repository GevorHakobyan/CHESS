#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
#include <array>

using Square = std::array<std::array<std::string, 3>, 3>;
using Row = std::vector<Square>;
using BoardMatrix = std::vector<Row>;

class Board {
    public:
    Board(int colums, int rows);
    BoardMatrix getBoard() const;
    private:
    void buildBoard();
    private:
    int m_colums{0};
    int m_rows{0};
    BoardMatrix m_board {8, Row(8)};
};

#endif