#include "King.hpp"

King::King(std::string color, const wchar_t* character) : Piece(color, character) {};

/*void King::move() {
    
}*/

King::~King() {};

King& King::operator=(King& other) {
    King tmp{other};
    std::swap(this->m_Avialble_Coordinates, tmp.m_Avialble_Coordinates);
    std::swap(this->m_Current_Coordinates, tmp.m_Current_Coordinates);
    std::swap(this->m_unicodeCharacter, tmp.m_unicodeCharacter);
    return *this;
}

King::King(King& other) {
    std::swap(this->m_Avialble_Coordinates, other.m_Avialble_Coordinates);
    std::swap(this->m_Current_Coordinates, other.m_Current_Coordinates);
    std::swap(this->m_unicodeCharacter, other.m_unicodeCharacter);
}