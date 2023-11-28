#ifndef  KNIGHT_HPP
#define  KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece {
    public:
    Knight() = default;
    Knight(Knight&);
    Knight& operator=(Knight&);
    Knight(std::string, const wchar_t*);
    private:
    //void move() override;
};

#endif