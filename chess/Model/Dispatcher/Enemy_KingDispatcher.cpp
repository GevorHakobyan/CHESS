#include "Enemy_KingDispatcher.hpp"

EnemyKing_Dispatcher* EnemyKing_Dispatcher::m_Dispatcher{nullptr};

EnemyKing_Dispatcher::EnemyKing_Dispatcher() {
    m_Handler = new Barriers_Handler;
    m_Handler->setNextHandler(nullptr);
}

EnemyKing_Dispatcher* EnemyKing_Dispatcher::getInstance() {
    if (m_Dispatcher == nullptr) {
        m_Dispatcher = new EnemyKing_Dispatcher{};
    }
    return m_Dispatcher;
}

bool EnemyKing_Dispatcher::Dispatch(const Piece& myPiece) {
    const Color myPieceColor = myPiece.getColor();
    const wchar_t* King = (myPieceColor == Color::White) ? L"\u2654": L"\u265A";

    Location KingLocation = determineKingLocation(King);
    return isAvailableFor_Me(myPiece, KingLocation);
} 

bool EnemyKing_Dispatcher::isPawn(const Piece& myPiece) {
    const wchar_t* character = myPiece.getUnicodeCharacter();
    const wchar_t* blackPawn  = L"\u2659";
    const wchar_t* whitePawn  = L"\u265F";

    return (*character ==  *blackPawn || *character ==  *whitePawn) ? true : false;
}

bool EnemyKing_Dispatcher::isAvailableFor_Me(const Piece& myPiece, const Location& KingLocation) {
    if (isPawn(myPiece)) {
        return handlePawnCase(myPiece, KingLocation);
    }
    
    const AvailableCoordinates& availableCoordinates = myPiece.getAvailableCoordinates();
    for (const auto& coordinate : availableCoordinates) {
        if (coordinate == KingLocation) {
            if (m_Handler->handleRequest(myPiece, KingLocation) ) {
                return true;
            }
        }
    }
    return false;
}

bool EnemyKing_Dispatcher::handlePawnCase(const Piece& myPiece, const Location& KingLocation) {
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

bool EnemyKing_Dispatcher::isOnSameColum(const Location& myLocation, const Location& KingLocation) {
    return myLocation.second == KingLocation.second;
}