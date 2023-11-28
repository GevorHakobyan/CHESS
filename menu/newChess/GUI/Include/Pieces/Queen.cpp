#include "Queen.hpp"

Queen::Queen(std::string color, const wchar_t* character) : Piece(color, character) {};

/*void Queen::move() {
    return; 
}*/

Queen& Queen::operator=(Queen& other) {
    Queen tmp{other};
    std::swap(this->m_Avialble_Coordinates, tmp.m_Avialble_Coordinates);
    std::swap(this->m_Current_Coordinates, tmp.m_Current_Coordinates);
    std::swap(this->m_unicodeCharacter, tmp.m_unicodeCharacter);
    return *this;
}

Queen::Queen(Queen& other) {
    std::swap(this->m_Avialble_Coordinates, other.m_Avialble_Coordinates);
    std::swap(this->m_Current_Coordinates, other.m_Current_Coordinates);
    std::swap(this->m_unicodeCharacter, other.m_unicodeCharacter);
}