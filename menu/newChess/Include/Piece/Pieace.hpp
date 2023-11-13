#ifndef PIECE_HPP
#define PIECE_HPP

#include <vector>
#include <string>

using AvailableCoordinates = std::vector<int>;

class Piece {
    public:
    virtual ~Piece() = 0;
    virtual void move() = 0;

    protected:
    int x_coordinate{0};
    int y_coordinate{0};
    AvailableCoordinates m_coordinates{};
    std::string m_unicodeCharacter{"\u2654"};
};

#endif