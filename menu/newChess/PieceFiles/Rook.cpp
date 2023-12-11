#include "Rook.hpp"

Rook::Rook(const std::string& color, const wchar_t* character, Location startLocation) 
: Piece(color, character, startLocation) 
{
    setAvailableCoordinates();
};

void Rook::updateAvailableCoordinates() {
   for (int i{0}; i < m_Avialble_Coordinates.size(); ++i) {
    m_Avialble_Coordinates[i]= m_Current_Location;
   }
   
   setRowCoordinates();
   setColumCoordinates();
}

void Rook::setAvailableCoordinates() {
    Location defaultLocactions{m_Current_Location.first, m_Current_Location.second};
    m_Avialble_Coordinates.resize(16, defaultLocactions);
    setRowCoordinates();
    setColumCoordinates();
}

void Rook::setRowCoordinates() {
    auto[y, x] = m_Current_Location;

    for (int i{0}; i < x; ++i) {
        m_Avialble_Coordinates[i].second = i;
    }

    for (int i{x + 1}; i < 8; ++i) {
        m_Avialble_Coordinates[i].second = i;
    }
}

void Rook::setColumCoordinates() {
     auto[y, x] = m_Current_Location;

    for (int i{8}; i < y + 8; ++i) {
        m_Avialble_Coordinates[i].first = i - 8;
    }

    for (int i{y + 9}; i < 16; ++i) {
        m_Avialble_Coordinates[i].first = i - 8;
    }
}



