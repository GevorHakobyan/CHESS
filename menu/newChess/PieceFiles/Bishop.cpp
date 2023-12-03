#include "Bishop.hpp"

Bishop::Bishop(const std::string& color, const wchar_t* character, Location startLocation) 
: Piece(color, character, startLocation) {};

void Bishop::updateAvailableCoordinates() {    
  return;
}

void Bishop::setAvailableCoordinates() {
    auto[y, x] = m_Current_Location;
    Location coordinate1{y + 1, x};
    Location coordinate2{y + 2, x};

    m_Avialble_Coordinates.push_back(coordinate1);
    m_Avialble_Coordinates.push_back(coordinate2);
}