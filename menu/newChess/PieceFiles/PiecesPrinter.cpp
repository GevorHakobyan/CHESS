#include "PiecesPrinter.hpp"

Index PiecesPrinter::m_pieceIndex{0,0};

PiecesPrinter::PiecesPrinter(const PieceList& myPieceList)
: m_PieceMap{std::make_unique<std::map<Location, Index>>()},
  m_PieceList {myPieceList} {};

void PiecesPrinter::getLocation(Location& location, const SquareIdentity& identities, int index) {
     location.first = std::get<0>(identities[index]);
     location.second = std::get<1>(identities[index]);
}

void PiecesPrinter::setPieceMap(Location& location) {
     m_PieceMap->insert(std::make_pair(location, m_pieceIndex));
}

void PiecesPrinter::print(const SquareIdentity& identities) {
    int index{0};
    Location location;

    for (int i{0}; i < 8; ++i) {
        for (int j{0}; j < 8; ++j) {
            m_pieceIndex.first = i;
            m_pieceIndex.second = j;
        
            getLocation(location, identities, index);
            setPieceMap(location);

            if (m_PieceList[i][j] != nullptr) {
                printCharacter(m_PieceList[i][j]->getUnicodeCharacter(), location);
            }
            ++index;
        }
    } 

}

void PiecesPrinter::printCharacter(const wchar_t* character, const Location& location) {
    move (location.first - 1, location.second - 3); 
    addwstr(character);
}

void PiecesPrinter::moveMapTo_View(Map& viewMap) {
    viewMap = std::move(m_PieceMap);
    m_PieceMap.reset();
}