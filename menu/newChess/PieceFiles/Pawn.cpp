#include "Pawn.hpp"
#include <optional>

Pawn::Pawn(const std::string& color, const wchar_t* character, Location startLocation)
 : Piece(color, character, startLocation) 
 {
    //checkIf_End();
    setAvailableCoordinates();
 };

void Pawn::updateAvailableCoordinates() {
    m_Avialble_Coordinates.clear();
    setAvailableCoordinates();
}

void Pawn::setAvailableCoordinates() {
    int maxCount{2};
    int Count{0};
    int maxBoardSize{8};

    int step = (this->m_color == Color::Black) ? -1 : 1;
    auto[y, x] = m_Current_Location;
    Location coordinate;
    
    while (y < maxBoardSize && Count < maxCount) {
        ++Count;
        coordinate.first = (y + (Count * step));
        coordinate.second = x;
        m_Avialble_Coordinates.push_back(coordinate);   
    }
    //prependiculars;
    maxCount = 2;
    Count = 1;

    coordinate.first = (y + (Count * step));
    coordinate.second = (x + 1 < maxBoardSize) ? (x + 1) : -1;
    if (coordinate.second != -1) {
        m_Avialble_Coordinates.push_back(coordinate);
    }

    coordinate.first = (y + (Count * step));
    coordinate.second = (x - 1 < maxBoardSize) ? (x - 1) : -1;
    if (coordinate.second != -1) {
        m_Avialble_Coordinates.push_back(coordinate);
    }
}

