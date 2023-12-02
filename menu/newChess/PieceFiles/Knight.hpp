#ifndef  KNIGHT_HPP
#define  KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece {
    public:
    Knight() = default;
    Knight(std::string, const wchar_t*);
};

#endif