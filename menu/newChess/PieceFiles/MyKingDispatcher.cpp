#include "MyKIngDispatcher.hpp"

MyKingDispatcher* MyKingDispatcher::m_Dispatcher{nullptr};

MyKingDispatcher::MyKingDispatcher() {
    m_Handler = new Barriers_Handler;
    m_Handler->setNextHandler(nullptr);
}
MyKingDispatcher* MyKingDispatcher::getInstance() {
    if (m_Dispatcher == nullptr) {
        m_Dispatcher = new MyKingDispatcher;
    }
    return m_Dispatcher;
}

bool MyKingDispatcher::Dispatch(const Color myPieceColor) {
    const wchar_t* King = (myPieceColor == Color::Black) ? L"\u2654": L"\u265A";
    Location KingLocation = determineKingLocation(King);
    Color enemyColor = (myPieceColor == Color::Black) ? Color::White : Color::Black;
    if (isAvailableFor_Enemy(KingLocation, enemyColor)) {
        return true;
    } 
    return false;
}


bool MyKingDispatcher::isAvailableFor_Enemy(const Location& KingLocation, const Color enemyColor) {
    Board* m_Board{Board::getInstance()};
    const PieceList& pieceList {m_Board->getPieceList()};

    for (int i{0}; i < 8; ++i) {
        for (const auto& Piece : pieceList[i]) {
            if (Piece != nullptr && Piece.get()->getColor() == enemyColor) {
                if(SearchInAvailable_Coordinates(*Piece, KingLocation)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool MyKingDispatcher::SearchInAvailable_Coordinates(const Piece& myPiece, const Location& KingLocation) {
    const AvailableCoordinates& m_Avaialble = myPiece.getAvailableCoordinates();

    for (const auto& coordinate : m_Avaialble) { 
        if (coordinate == KingLocation) {
            if (m_Handler->handleRequest(myPiece, KingLocation)) {
                return true;
            }
            
        }
    }
    return false;
}