#include "BarriersHandler.hpp"

bool Barriers_Handler::handleRequest(const Piece& myPiece, const Location& mydesiredLocation) {
    setCurrentLocation(myPiece);
    setDesiredLocation(mydesiredLocation);  
    addTo_InvadingPath(m_currentLocation);
  
    if (isHorse(myPiece)) {
        return AbstractHandler::handleRequest(myPiece, mydesiredLocation);
    }

    if (isPawn(myPiece)) {
        return AbstractHandler::handleRequest(myPiece, mydesiredLocation);
    }

    if (isOnSameColum()) { 
        return handleOnSameColum()? AbstractHandler::handleRequest(myPiece, mydesiredLocation) : false;
    }
    
    
    if (isOnSameRow()) { 
        return handleOnSameRow() ? AbstractHandler::handleRequest(myPiece, mydesiredLocation) : false;
    } 

    if (handlePrependicular()) {
        return AbstractHandler::handleRequest(myPiece, mydesiredLocation);
    }
    return false;
}

void Barriers_Handler::setCurrentLocation(const Piece& myPiece) {
    m_currentLocation = myPiece.getCurrentLocation();
}

void Barriers_Handler::setDesiredLocation(const Location& myDesiredLocation) {
    m_desiredLocation = myDesiredLocation;
}

bool Barriers_Handler::isHorse(const Piece& m_Piece) {
    const wchar_t* blackHorse = L"\u2658";
    const wchar_t* whiteHorse = L"\u265E";
    if (m_Piece.getColor() == Color::Black && *m_Piece.getUnicodeCharacter() == *blackHorse) {
        return true;
    }

    if (m_Piece.getColor() == Color::White && *m_Piece.getUnicodeCharacter() == *whiteHorse) {
        return true;
    }
    return false;
}

bool Barriers_Handler::isPawn(const Piece& m_Piece) {
    const wchar_t* blackPawn = L"\u2659";
    const wchar_t* whitePawn = L"\u265F";
    if (m_Piece.getColor() == Color::Black && *m_Piece.getUnicodeCharacter() == *blackPawn) {
        return true;
    }

    if (m_Piece.getColor() == Color::White && *m_Piece.getUnicodeCharacter() == *whitePawn) {
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
    return false;  
}

bool Barriers_Handler::goUp() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

     for (int i{startY + 1}; i < desiredY; ++i) {
        desiredLocation.first = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation);
     }

     return true;
}

bool Barriers_Handler::goDown() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

     for (int i{startY - 1}; i > desiredY; --i) {
        desiredLocation.first = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation);
     }
     return true;
}

bool Barriers_Handler::goRight() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

     for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.second = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation);
     }
     return true;
}

bool Barriers_Handler::goLeft() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

     for (int i{startX - 1}; i > desiredX; --i) {
        desiredLocation.second = i;
        if (!myBoard->isEmpty(desiredLocation).first) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation);
     }
     return true;
}

bool Barriers_Handler::goRightDown() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

    for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.first = --startY;
        desiredLocation.second = ++startX;
        if (!(myBoard->isEmpty(desiredLocation).first)) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation);
     }
    return true;
}

bool Barriers_Handler::goRightUp() { 
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location desiredLocation = m_desiredLocation;

    for (int i{startX + 1}; i < desiredX; ++i) {
        desiredLocation.first = ++startY;
        desiredLocation.second = ++startX;

        if (!(myBoard->isEmpty(desiredLocation).first)) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(desiredLocation); 

     }
     return true;
}

bool Barriers_Handler::goLeftUp() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location discovarableLocation = m_desiredLocation;

    for (int i{startX - 1}; i > desiredX; --i) {
        discovarableLocation.first = ++startY;
        discovarableLocation.second = --startX;

        if (!myBoard->isEmpty(discovarableLocation).first) {
            eraseInvadingPath();
            return false;
        }

        addTo_InvadingPath(m_desiredLocation);
     }
     return true;
}

bool Barriers_Handler::goLeftDown() {
    Board* myBoard{Board::getInstance()}; 
    auto [startY, startX] = m_currentLocation;
    auto [desiredY, desiredX] = m_desiredLocation;
    Location discovarableLocation = m_desiredLocation;

    for (int i{startX - 1}; i > desiredX; --i) {
        discovarableLocation.first = --startY;
        discovarableLocation.second = --startX;

        if (!myBoard->isEmpty(discovarableLocation).first) {
            eraseInvadingPath();
            return false;
        }
        addTo_InvadingPath(m_desiredLocation);
        
     }
     return true;
}

bool Barriers_Handler::isOnRight() {
   return  m_desiredLocation.second > m_currentLocation.second ? true : false;
}

bool Barriers_Handler::isAbove() {
    return (m_desiredLocation.first > m_currentLocation.first) ? true : false;
}

bool Barriers_Handler::isOnSameColum() {
    return m_currentLocation.second == m_desiredLocation.second ? true : false;
}

bool Barriers_Handler::isOnSameRow() {
     return m_currentLocation.first == m_desiredLocation.first ? true : false;
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

void Barriers_Handler::addTo_InvadingPath(const Location& coordinate) {
    m_invadingPath.push_back(coordinate);
}

Barriers_Handler::Path Barriers_Handler::getInvadingPath() {
    return m_invadingPath;
}

void Barriers_Handler::eraseInvadingPath() {
    m_invadingPath.erase(m_invadingPath.begin(), m_invadingPath.end());
}