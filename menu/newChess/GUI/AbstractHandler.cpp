#include "AbstractHandler.hpp"

AbstractHandler::AbstractHandler(const Piece& myPiece, const Location desiredLocation)
: m_Piece{myPiece}, m_desiredLocation{desiredLocation} {};

Handler* AbstractHandler::setNextHandler(Handler* handler) {
    this->m_nextHandler = handler;
    return handler;
}

bool AbstractHandler::handleRequest() {
    if (this->m_nextHandler != nullptr) {
        return this->m_nextHandler->handleRequest();
    }
    return false;
}

