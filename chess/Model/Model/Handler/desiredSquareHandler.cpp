#include "desiredSquareHandler.hpp"

bool DesiredSquare_Handler::handleRequest(const Piece& myPiece, const Location& desiredLocation) {
    const auto[isPawn, isEvent] = Broker::HandleIfPawn(myPiece, desiredLocation);
    if (isPawn && isEvent) {
        return false;
    }

    if (isPawn && !isEvent) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
    
     if (Broker::isEmpty(desiredLocation)) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
     }  
    if (Broker::isEnemy(desiredLocation, myPiece.getColor())) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
    return false;
}


