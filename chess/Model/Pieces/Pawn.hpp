#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"
//#include "Model.hpp"
#include "Board.hpp"
#include <optional>

class Pawn : public Piece{
    public:
    Pawn(const std::string& color, const wchar_t*, Location startLocation);
    private:
    void updateAvailableCoordinates() override;
    void setAvailableCoordinates() override; 
};

#endif