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

    const AvailableCoordinates& m_availables = myPiece.getAvailableCoordinates();
    Location KingLocation = determineKingLocation(King);
    return isAvailableFor_Me(myPiece, KingLocation);
} 

bool EnemyKing_Dispatcher::isAvailableFor_Me(const Piece& myPiece, const Location& KingLocation) {
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