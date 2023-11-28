#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece{
    public:
    Pawn(std::string, const wchar_t*);
    private:
    //void move() override;
};

#endif