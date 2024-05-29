#ifndef BOARDVIEW_HPP
#define BOARDVIEW_HPP

#include <string>
#include <vector>
#include <array>
#include <tuple>

using Square = std::array<std::array<const wchar_t*, 3>, 3>;
using Row = std::vector<Square>;
using BoardMatrix = std::vector<Row>;
using Letters = std::vector<char>;
using Numbers  = std::vector<int>;
using SquareIdentity = std::array<std::tuple<int, int, int>, 64>;

class BoardView {
    public:
    static BoardView* getInstance();
    BoardView(BoardView&) =  delete;
    BoardView& operator=(const BoardView&) = delete;
    BoardMatrix getBoard() const;
    Letters getLetters() const;
    Numbers getNumbers() const;
    void buildBoard();
    void fillLetters();
    void fillNumbers();
    void setSquareIdentity(std::tuple<int, int, int>);
    const SquareIdentity& getSquaresIdentities() const;
   

    private: 
    BoardView(int colums, int rows);
    static BoardView* m_BoardView;
    BoardMatrix m_board {8, Row(8)};
    int m_colums{0};
    int m_rows{0};
    Letters m_letters{};
    Numbers m_numbers{0};
    SquareIdentity m_squaresIdentity{};
};

#endif