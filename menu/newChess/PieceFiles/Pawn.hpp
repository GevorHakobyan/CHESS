#ifndef PAWN_HPP
#define PAWN_HPP

#include "Board.hpp"
#include "Piece.hpp"
#include <optional>

enum class PawnPosition{Up, Down};

class Pawn : public Piece{
    public:
    Pawn(const std::string& color, const wchar_t*, Location startLocation);
    private:
    private: //Methods
    PawnPosition detectPosition();
    void updateAvailableCoordinates() override; 
    AvailableCoordinates standardUpdate(Location);
    std::optional<AvailableCoordinates> updateWithChecks(Location);
    void detectEnemies(Location, std::pair<bool, bool>&, Location, Location);
    void setAvailableCoordinates() override;
};

#endif