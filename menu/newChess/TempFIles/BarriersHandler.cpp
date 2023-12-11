#include "BarriersHandler.hpp"

Barriers_Handler::Barriers_Handler() {};

bool Barriers_Handler::handleRequest(const Piece& m_Piece, const Location& m_desiredLocation) {
    if (isHorse()) {
        return true;
    }

    if (isOnSameColum()) {
        return handleOnSameColum();
    }

    if (isOnSameRow()) {
        return handleOnSameRow();
    }

    return handlePrependicular();
}

bool Barriers_Handler::isHorse() {
    const wchar_t* blackHorse = L"\u2658";
    const wchar_t* whiteHorse = L"\u265E";
    if (m_Piece->getColor() == Color::Black && m_Piece->getUnicodeCharacter() == blackHorse) {
        return true;
    }

    if (m_Piece->getColor() == Color::White && m_Piece->getUnicodeCharacter() == whiteHorse) {
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
    auto [desiredY, desiredX] = m_desiredLocation;

     for (int i{startY + 1}; i < desiredY; ++i) {
        m_desiredLocation.first = i;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goDown() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_desiredLocation;

     for (int i{startY - 1}; i > desiredY; --i) {
        m_desiredLocation.first = i;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goRight() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_desiredLocation;

     for (int i{startX + 1}; i < desiredX; ++i) {
        m_desiredLocation.first = i;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeft() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_desiredLocation;

     for (int i{startX - 1}; i > desiredX; --i) {
        m_desiredLocation.first = i;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goRightUp() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_Piece->getCurrentLocation();
    Board* myBoard{Board::getInstance()}; 

    for (int i{startX + 1}; i < desiredX; ++i) {
        m_desiredLocation.first = ++desiredY;
        m_desiredLocation.second = ++desiredX;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goRightDown() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_Piece->getCurrentLocation();
    Board* myBoard{Board::getInstance()}; 

    for (int i{startX + 1}; i < desiredX; ++i) {
        m_desiredLocation.first = --desiredY;
        m_desiredLocation.second = ++desiredX;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeftUp() {
    auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_Piece->getCurrentLocation();
    Board* myBoard{Board::getInstance()}; 

    for (int i{startX - 1}; i > desiredX; --i) {
        m_desiredLocation.first = ++desiredY;
        m_desiredLocation.second = --desiredX;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::goLeftDown() {
     auto [startY, startX] = m_Piece->getCurrentLocation();
    auto [desiredY, desiredX] = m_Piece->getCurrentLocation();
    Board* myBoard{Board::getInstance()}; 

    for (int i{startX - 1}; i > desiredX; --i) {
        m_desiredLocation.first = --desiredY;
        m_desiredLocation.second = --desiredX;
        if (!myBoard->isEmpty(m_desiredLocation).first) {
            return false;
        }
     }
     return true;
}

bool Barriers_Handler::isOnRight() {
   return  m_desiredLocation.second > m_Piece->getCurrentLocation().second ? true : false;
}

bool Barriers_Handler::isAbove() {
    return m_desiredLocation.first > m_Piece->getCurrentLocation().first ? true : false;
}

bool Barriers_Handler::isOnSameColum() {
    return m_Piece->getCurrentLocation().second == m_desiredLocation.second ? true : false;
}

bool Barriers_Handler::isOnSameRow() {
     return m_Piece->getCurrentLocation().first == m_desiredLocation.first ? true : false;
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