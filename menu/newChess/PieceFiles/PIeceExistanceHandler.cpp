#include "PieceExistanceHandler.hpp"
bool PieceExistanceHandler::handleRequest(const Piece& m_Piece, const Location& m_desiredLocation) {
    if (&m_Piece != nullptr) {
        return AbstractHandler::handleRequest(m_Piece, m_desiredLocation);
    }
    return false;
}

