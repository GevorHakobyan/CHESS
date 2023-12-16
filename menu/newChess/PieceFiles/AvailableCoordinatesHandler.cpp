#include "AvailableCoordinatesHandler.hpp"

bool AvailableCoordinates_Handler::handleRequest(const Piece& m_Piece, const Location& m_desiredLocation) { 
    bool answer{false};
    AvailableCoordinates myPieceAvailableCoordinates = m_Piece.getAvailableCoordinates();
    for (const auto& coordinate : myPieceAvailableCoordinates) {
        if (coordinate == m_desiredLocation) {
            answer = true;
            break;
        }
    }

    if (answer == true) {
    mvprintw(5, 0, "%s", "In availabel coordinates   ");
        return AbstractHandler::handleRequest(m_Piece, m_desiredLocation);
    } 
    return false;
}