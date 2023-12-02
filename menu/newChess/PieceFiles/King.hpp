#ifndef  KING_HPP
#define  KING_HPP

#include "Piece.hpp"

class King : public Piece {
    public:
    King() = default;
    King(std::string, const wchar_t*);
};

#endif