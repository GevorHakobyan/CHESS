#ifndef  ROOK_HPP
#define  ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece {
    public:
    Rook(const std::string&, const wchar_t*, Location);
    void updateAvailableCoordinates() override;
    void setAvailableCoordinates() override;
    private:
};

#endif