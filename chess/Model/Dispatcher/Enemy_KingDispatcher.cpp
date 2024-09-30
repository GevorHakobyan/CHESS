#include "Enemy_KingDispatcher.hpp"

EnemyKing_Dispatcher::thisPtr EnemyKing_Dispatcher::m_Dispatcher{nullptr};

EnemyKing_Dispatcher::EnemyKing_Dispatcher() {
    m_Handler->setNextHandler(nullptr);
}

EnemyKing_Dispatcher::thisPtr EnemyKing_Dispatcher::getInstance() {
    if (m_Dispatcher == nullptr) {
        m_Dispatcher.reset(new EnemyKing_Dispatcher);
    }
    return m_Dispatcher;
}

const EnemyKing_Dispatcher::Path& EnemyKing_Dispatcher::getInvadingPath() const {
    return m_InvadingPath;
}

bool EnemyKing_Dispatcher::Dispatch(const Piece& myPiece) {
    const wchar_t* King = (myPiece.getColor() == Color::Black) ? L"\u265A": L"\u2654";
    Location KingLocation = determineKingLocation(King);

    return isAvailableFor_Me(myPiece, KingLocation);
} 

bool EnemyKing_Dispatcher::isAvailableFor_Me(const Piece& myPiece, const Location& KingLocation) {
    bool answer = SearchInAvailable_Coordinates(myPiece, KingLocation);
    m_InvadingPath = (answer) ? m_Handler->getInvadingPath() : m_InvadingPath;
    return answer;
}



