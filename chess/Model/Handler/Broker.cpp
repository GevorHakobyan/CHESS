#include "Broker.hpp"

Broker::MyKingDispatcherPtr Broker::m_KingDispatcher{MyKingDispatcher::getInstance()};
Broker::EnemyKingDispatcherPtr Broker::m_EnemyKingDispatcher{EnemyKing_Dispatcher::getInstance()};
Broker::GameStatePtr Broker::m_GameStateDispatcher{GameStateDispatcher::getInstance()};

bool Broker::isMyKingUnderCheck(const Piece& myPiece) {
    return m_KingDispatcher->Dispatch(myPiece);
}

bool Broker::isEnemyKingUnderCheck(const Piece& myPiece) {
    return m_EnemyKingDispatcher->Dispatch(myPiece);
}

bool Broker::isKingKilled(const Piece& Invador) {
    m_GameStateDispatcher->setInvadingPath(m_EnemyKingDispatcher->getInvadingPath());
    const auto canEscape = m_GameStateDispatcher->Dispatch(Invador);
    if(canEscape) {
        return false;
    }

    const auto defenders = m_GameStateDispatcher->getDefenders();
    for (const auto& defender : defenders) {
        if (canDefend(defender)) {
            return false;
        }
    }
    return true;
}

bool Broker::canDefend(const std::pair<Location, Location>& defender) {
    const auto m_board = Board::getInstance();
    const auto& pieceList = m_board->getPieceList();

    moveDefender(defender.first, defender.second);
    const auto[newX, newY] = defender.second;

    if(!m_KingDispatcher->Dispatch(*pieceList[newX][newY])) {
        resetDefender(defender.second, defender.first);
        return true;
    }
    resetDefender(defender.second, defender.first);
    return false;
}

void Broker::moveDefender(const Location& currentLocation, const Location& newLocation) {
    const auto m_board = Board::getInstance();
    const auto& pieceList = m_board->getPieceList();
    const auto[currentX, currentY] = currentLocation;

    pieceList[currentX][currentY]->setCurrentLocation(newLocation);
}

void Broker::resetDefender(const Location& currentLocation, const Location& newLocation) {
    moveDefender(currentLocation, newLocation);
}
