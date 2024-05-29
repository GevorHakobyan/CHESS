#ifndef  KING_HPP
#define  KING_HPP

#include "Piece.hpp"

class King : public Piece {
    public:
    King(const std::string& color, const wchar_t* character, Location currentLocaton);
    void updateAvailableCoordinates() override;
    void setAvailableCoordinates() override;
    private:
    bool doesExist(Location);
    void setUpCoordinates();
    void setDownCoordinates();
    void setOnSameLine();
};

#endif