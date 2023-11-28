#ifndef  KING_HPP
#define  KING_HPP

#include "Piece.hpp"

class King : public Piece {
    public:
    King() = default;
    King(King&);
    ~King() override;
    King& operator=(King&);
    King(std::string, const wchar_t*);
    private:
    //void move() override;
};

#endif