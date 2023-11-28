#include "Piece.hpp"

Piece::Piece(std::string color, const wchar_t* character) {
    setUnicodeCharacter(color, character);
}

Piece::~Piece() {};

Piece::Piece(Piece& other) {
    std::swap(this->m_Avialble_Coordinates, other.m_Avialble_Coordinates);
    std::swap(this->m_Current_Coordinates, other.m_Current_Coordinates);
    std::swap(this->m_unicodeCharacter, other.m_unicodeCharacter);
}

void Piece::setCoordinates(int y, int x) {
    m_Current_Coordinates.first = y;
    m_Current_Coordinates.second = x;
}

void Piece::setUnicodeCharacter(std::string color, const wchar_t* character) {
    if ("Black" == color) {
        m_unicodeCharacter = std::make_unique<const wchar_t*>(character);
        return;
    }
    m_unicodeCharacter = std::make_unique<const wchar_t*>(character);
}

const wchar_t* Piece::getUnicodeCharacter() const {
    const wchar_t* myPtr = *m_unicodeCharacter.get();
    return myPtr;
}
