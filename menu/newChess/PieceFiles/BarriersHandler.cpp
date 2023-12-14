#include "BarriersHandler.hpp"

bool Barriers_Handler::handleRequest(const Piece& myPiece, const Location& mydesiredLocation) {
    setPiece(const_cast<Piece&>(myPiece));
    setLocation(const_cast<Location&>(mydesiredLocation)); //to change every time
    if (isHorse()) {
        return true;
    }

    if (isOnSameColum()) {
        return handleOnSameColum()? AbstractHandler::handleRequest(myPiece, mydesiredLocation) : false;
    }

    if (isOnSameRow()) {
        return handleOnSameRow() ? AbstractHandler::handleRequest(myPiece, mydesiredLocation) : false;
    }

    if (handlePrependicular()) {
        return handlePrependicular() ? AbstractHandler::handleRequest(myPiece, mydesiredLocation): false;
    }
    return false;
}

bool Barriers_Handler::isHorse() {
    const wchar_t* blackHorse = L"\u2658";
    const wchar_t* whiteHorse = L"\u265E";
    if (m_Piece->getColor() == Color::Black && *m_Piece->getUnicodeCharacter() == *blackHorse) {
        return true;
    }

    if (m_Piece->getColor() == Color::White && *m_Piece->getUnicodeCharacter() == *whiteHorse) {
        return true;
    }
    return false;
}

bool Barriers_Handler::handleOnSameColum() {
     if (isAbove()) {
        return goUp();
     }
     return goDown();
}

bool Barriers_Handler::handleOnSameRow() {
    if (isOnRight()) {
        return goRight();
    }
    return goLeft();
}

bool Barriers_Handler::handlePrependicular() {
    if (isAbove()) {
        return isOnLeftAboveCorner() ? goLeftUp() : goRightUp();
    }

    return isOnRightBeneathCorner() ?  goRightDown() : goLeftDown();
}

bool Barriers_Handler::goUp() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Location desiredLocation = *m_desiredLocation;

     for (int i{startY + 1}; i < desiredY; ++i) {
        desiredLocation.first = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goDown() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Location desiredLocation = *m_desiredLocation;

     for (int i{startY - 1}; i > desiredY; --i) {
        desiredLocation.first = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goRight() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Location desiredLocation = *m_desiredLocation;

     for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.second = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeft() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Location desiredLocation = *m_desiredLocation;

     for (int i{startX - 1}; i > desiredX; --i) {
        desiredLocation.second = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goRightUp() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Board* myBoard{Board::getInstance()}; 
    Location desiredLocation = *m_desiredLocation;

    for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.first = ++desiredY;
        desiredLocation.second = ++desiredX;
        if (!(myBoard->isEmpty(desiredLocation).first)) {
            return false;
        }
     }
    return true;
}

bool Barriers_Handler::goRightDown() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Board* myBoard{Board::getInstance()}; 
    Location desiredLocation = *m_desiredLocation;

    for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.first = --startY;
        desiredLocation.second = ++startX;
        if (!(myBoard->isEmpty(*m_desiredLocation).first)) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeftUp() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Board* myBoard{Board::getInstance()}; 
    Location desiredLocation = *m_desiredLocation;

    for (int i{startX - 1}; i > desiredX; --i) {
        desiredLocation.first = ++desiredY;
        desiredLocation.second = --desiredX;
        if (!myBoard->isEmpty(*m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeftDown() {
     auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = *m_desiredLocation;
    Board* myBoard{Board::getInstance()}; 
    Location desiredLocation = *m_desiredLocation;

    for (int i{startX - 1}; i > desiredX; --i) {
        desiredLocation.first = --desiredY;
        desiredLocation.second = --desiredX;
        if (!myBoard->isEmpty(*m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::isOnRight() {
   return  m_desiredLocation->second > m_Piece->getCurrentLocation().second ? true : false;
}

bool Barriers_Handler::isAbove() {
    return (m_desiredLocation->first > m_Piece->getCurrentLocation().first) ? true : false;
}

bool Barriers_Handler::isOnSameColum() {
    return m_Piece->getCurrentLocation().second == m_desiredLocation->second ? true : false;
}

bool Barriers_Handler::isOnSameRow() {
     return m_Piece->getCurrentLocation().first == m_desiredLocation->first ? true : false;
}

bool Barriers_Handler::isOnRightBeneathCorner() {
    if (!isAbove() && isOnRight()) {
        return true;
    }

    return false;
}

bool Barriers_Handler::isOnLeftAboveCorner() {
    if (isAbove() && !isOnRight()) {
        return true;
    }
    return false;
}

void Barriers_Handler::setPiece(Piece& myPiece) {
    m_Piece = &myPiece;
}

void Barriers_Handler::setLocation(Location& myLocation) {
    m_desiredLocation = &myLocation;
}