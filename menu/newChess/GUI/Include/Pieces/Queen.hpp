#ifndef QUEEN_HPP
#define  QUEEN_HPP

#include "Piece.hpp"

class Queen : public Piece {
    public:
    Queen() = default;
    Queen(std::string, const wchar_t*);
    Queen(Queen&); 
    Queen& operator=(Queen&);
    private:
    //void move() override;
};

#endif