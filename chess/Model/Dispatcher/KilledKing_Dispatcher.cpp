#include "KilledKing_Dispatcher.hpp"

void KilledKingDispatcher::searchKing(const Piece& myPiece)  {
    const wchar_t* kingCharacter = (myPiece.getColor() == Color::Black) ? L"\u265A": L"\u2654";
    Board* m_Board{Board::getInstance()};
    const PieceList& pieceList {m_Board->getPieceList()};

    for (size_t i{0}; i < 8; ++i) {
        for (const auto& piece : pieceList[i]) {
            if (isKing(*piece->getUnicodeCharacter(), *kingCharacter)) {
                m_isKilled = isKingKilled(*piece);
                return;
            }
        }
    }

}

bool KilledKingDispatcher::isKing(const wchar_t character, const wchar_t kingcharacter) const {
    return character == kingcharacter;
}

bool KilledKingDispatcher::isKingKilled(const Piece& king) {
    const auto availabeCoordinates = king.getAvailableCoordinates();
    bool isUnderCheck{true};
    
    for (const auto& coordinate : availabeCoordinates) {
        if (!isUnderCheck) {
            return false;
        }
        isUnderCheck = isCoordinateUnderCheck(coordinate);
    }
}

bool KilledKingDispatcher::isCoordinateUnderCheck(const Location& coordinate) {
    Board* m_Board{Board::getInstance()};
    const PieceList& pieceList {m_Board->getPieceList()};
    bool isUnderCheck{false};

    for (size_t i{0}; i < 8; ++i) {
        for (const auto& piece : pieceList[i]) {
            if (isUnderCheck) {
                return true;
            }
            isUnderCheck = SearchInAvailable_Coordinates(*piece, coordinate);
        }
    }    
}
