#include "Piece.hpp"
Piece::Piece(std::string color, const wchar_t* character) {
    setUnicodeCharacter(character);
    setColor(color);
}

Piece::~Piece() {};

Piece::Piece(Piece& other) noexcept{
    std::swap(this->m_Avialble_Coordinates, other.m_Avialble_Coordinates);
    std::swap(this->m_color, other.m_color);
    std::swap(this->m_Current_Location, other.m_Current_Location);
    std::swap(this->m_unicodeCharacter, other.m_unicodeCharacter);
}
Piece& Piece::operator=(Piece& other) noexcept{
    Piece tmp{other};
    SwapWithThis(tmp);
    return *this;
}

Piece& Piece::operator=(Piece&& other) noexcept{
    Piece tmp{other};
    SwapWithThis(tmp);
    return *this;
}

Piece::Piece(Piece&& other) noexcept {
    std::swap(this->m_Avialble_Coordinates, other.m_Avialble_Coordinates);
    std::swap(this->m_color, other.m_color);
    std::swap(this->m_Current_Location, other.m_Current_Location);
    std::swap(this->m_unicodeCharacter, other.m_unicodeCharacter);
}
void Piece::setCurrentLocation(int y, int x) {
    m_Current_Location.first = y;
    m_Current_Location.second = x;
}
CurrentLocation Piece::getCurrentLocation() const {
    return m_Current_Location;
}
void Piece::setUnicodeCharacter(const wchar_t* character) {
    m_unicodeCharacter = std::make_unique<const wchar_t*>(character);
}

const wchar_t* Piece::getUnicodeCharacter() const {
    const wchar_t* myPtr = *m_unicodeCharacter.get();
    return myPtr;
}

void Piece::setColor(const std::string& color) {
    color == "Black"? m_color = Color::Black : m_color = Color::White;
} 

std::string Piece::getColor() const {
    return m_color == Color::Black ? "Black" : "White";
}

void Piece::SwapWithThis(Piece& other) {
    CurrentLocation tmpLoc {other.m_Current_Location};
    std::swap(this->m_Current_Location, tmpLoc);

    AvailableCoordinates tmpCord{other.m_Avialble_Coordinates};
    std::swap(this->m_Avialble_Coordinates, tmpCord);

    std::unique_ptr<const wchar_t*> tmpUnicode{std::move(other.m_unicodeCharacter)};
    std::swap(this->m_unicodeCharacter, tmpUnicode);

    Color tmpCol{other.m_color};
    std::swap(this->m_color, tmpCol);  
} 
