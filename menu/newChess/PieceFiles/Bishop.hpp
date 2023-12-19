#ifndef  BISHOP_HPP
#define  BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece {
    public:
    Bishop(const std::string& color, const wchar_t*, Location startLocation);
    void updateAvailableCoordinates() override;
    void setAvailableCoordinates() override;
    private:
    void setRightUpCoordinates();
    void setLeftUpCoordinates();
    void setRightDownCoordinates();
    void setLeftDownCoordinates();
    int a{0};
};

#endif