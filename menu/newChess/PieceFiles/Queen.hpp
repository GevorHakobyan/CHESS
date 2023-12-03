#ifndef QUEEN_HPP
#define  QUEEN_HPP

#include "Piece.hpp"

class Queen : public Piece {
    public:
    Queen(const std::string& color, const wchar_t*, Location startLocation);
    void updateAvailableCoordinates() override;
    void setAvailableCoordinates() override;
};

#endif