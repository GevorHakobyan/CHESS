#ifndef  BISHOP_HPP
#define  BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece {
    public:
    Bishop() = default;
    Bishop(std::string, const wchar_t*);
};

#endif