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

bool MyKingDispatcher::Dispatch(const Piece& myPiece) {
    const wchar_t* King = (myPiece.getColor() == Color::Black) ? L"\u2654": L"\u265A";
    Location KingLocation = determineKingLocation(King);
    Color enemyColor = (myPiece.getColor() == Color::Black) ? Color::White : Color::Black;

    if (isAvailableFor_Enemy(KingLocation, enemyColor)) {
        return true;
    } 
    return false;
}


bool MyKingDispatcher::isAvailableFor_Enemy(const Location& KingLocation, const Color enemyColor) {
    return isKingAvailable(KingLocation, enemyColor);
}

     