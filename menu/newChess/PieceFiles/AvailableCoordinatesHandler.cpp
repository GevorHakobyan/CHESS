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
        return AbstractHandler::handleRequest(m_Piece, m_desiredLocation);
    }
    return false;
}