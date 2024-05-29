#include "Dispatcher.hpp"


Location Dispatcher::determineKingLocation(const wchar_t* King) {
    Board* m_Board{Board::getInstance()};
    const PieceList& pieceList {m_Board->getPieceList()};
    Location KingLocation; 

   for (int i{0}; i < 8; ++i) {
    for (const auto& Piece : pieceList[i]) {
        if (Piece != nullptr) {
            if (*Piece.get()->getUnicodeCharacter() == *King) {
                KingLocation = Piece.get()->getCurrentLocation();
            }
        }
    }
   }

   return KingLocation;
}