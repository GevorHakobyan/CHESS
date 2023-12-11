#include "PieceExistanceHandler.hpp"

bool PieceExistanceHandler::handleRequest(const Piece& m_Piece, const Location& m_desiredLocation) {
    if (&m_Piece != nullptr) {
        move(0, 0);
        printw("%s", "Exist   ");
        return AbstractHandler::handleRequest(m_Piece, m_desiredLocation);
    }
    move(0, 0);
    printw("%s",  "doesn't exist");
    return false;
}

