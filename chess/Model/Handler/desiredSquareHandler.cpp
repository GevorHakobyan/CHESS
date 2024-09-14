#include "desiredSquareHandler.hpp"

bool DesiredSquare_Handler::handleRequest(const Piece& myPiece, const Location& desiredLocation) {
    const auto[isPawn, answer] = HandleIfPawn(myPiece, desiredLocation);
    if (desiredLocation.first == 0 && desiredLocation.second == 4) {
        a = 72;
    }
    if (isPawn) {
        return (answer) ? AbstractHandler::handleRequest(myPiece, desiredLocation) : false;
    }

    if (Broker::isEmpty(desiredLocation)) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
      
    if (Broker::isEnemy(desiredLocation, myPiece.getColor())) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
    return false;
}

std::pair<bool, bool> DesiredSquare_Handler::HandleIfPawn(const Piece& myPiece, const Location& desiredLocation) {
    const auto[isPawn, isEvent, isOnSameColum] = Broker::HandleIfPawn(myPiece, desiredLocation);
    std::pair<bool, bool> answer;


    if (!isPawn) {
        answer.first = false;
        answer.second = false;
        return answer;
    }
    answer.first = true;

    if (isPawn && isEvent) {
        AbstractHandler::handleRequest(myPiece, desiredLocation);
        answer.second = false;
        return {true, false};
    }

    if (isPawn && isOnSameColum) {
        answer.second = Broker::isEmpty(desiredLocation);
        return answer;
    }

    if (Broker::isEmpty(desiredLocation)) {
        answer.second = false;
        return answer;
    }
    answer.second = Broker::isEnemy(desiredLocation, myPiece.getColor());
    return answer;
}


