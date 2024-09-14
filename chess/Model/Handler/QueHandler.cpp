#include "QueHandler.hpp"

bool QueHandler::handleRequest(const Piece& myPiece, const Location& myLocation) {
    if ((!m_que && myPiece.getColor() == Color::White)) {
        m_que = true;
        return true;
    }
     if ((m_que && myPiece.getColor() == Color::Black)) {
        m_que = false;
        return true;
    }
    return false;
}