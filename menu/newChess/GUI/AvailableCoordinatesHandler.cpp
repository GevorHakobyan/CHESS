#include "AvailableCoordinatesHandler.hpp"

AvailableCoordinates_Handler::AvailableCoordinates_Handler(const Piece& myPiece, const Location myLocation)
: AbstractHandler(myPiece, myLocation) {};

bool AvailableCoordinates_Handler::handleRequest() { 
    bool answer{false};
    AvailableCoordinates myPieceAvailableCoordinates = m_Piece.getAvailableCoordinates();

    for (const auto& coordinate : myPieceAvailableCoordinates) {
        if (coordinate == m_desiredLocation) {
            answer = true;
            break;
        }
    }

    if (answer == true) {
        return AbstractHandler::handleRequest();
    }
    return false;
}