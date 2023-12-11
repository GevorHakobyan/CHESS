#include "AvailableCoordinatesHandler.hpp"

AvailableCoordinates_Handler::AvailableCoordinates_Handler() {};

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
        move(1, 0);
        printw("%s", "is Available");
        return true;
        //return AbstractHandler::handleRequest(m_Piece, m_desiredLocation);
    }
    move(1, 0);
    printw("%s", "Isn't availble");
    return false;
}