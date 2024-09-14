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
     if (isPawn(myPiece)) {
        return handlePawnCase(myPiece, KingLocation);
    }
    
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

bool MyKingDispatcher::isPawn(const Piece& myPiece) {
    const wchar_t* character = myPiece.getUnicodeCharacter();
    const wchar_t* blackPawn  = L"\u2659";
    const wchar_t* whitePawn  = L"\u265F";

    return (*character ==  *blackPawn || *character ==  *whitePawn) ? true : false;
}

bool MyKingDispatcher::isOnSameColum(const Location& myLocation, const Location& KingLocation) {
    return myLocation.second == KingLocation.second;
}

bool MyKingDispatcher::handlePawnCase(const Piece& myPiece, const Location& KingLocation) {
    const AvailableCoordinates& availableCoordinates = myPiece.getAvailableCoordinates();

    for (const auto& coordinate : availableCoordinates) {
        if (coordinate == KingLocation && !isOnSameColum(coordinate, KingLocation)) {
            if (m_Handler->handleRequest(myPiece, KingLocation) ) {
                return true;
            }
        }
    }
    return false;
}