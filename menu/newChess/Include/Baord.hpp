#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>

class Board {
    Board(int colums, int lines);
    void draw();
    private:
    int m_colums{0};
    int m_rows{0};
    std::string blackBlock{"\u25A1"};
};

#endif