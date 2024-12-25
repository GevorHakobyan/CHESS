#include "desiredSquareHandler.hpp"

bool DesiredSquare_Handler::handleRequest(const Piece& myPiece, const Location& desiredLocation) {
    const auto[isPawn, answer] = HandleIfPawn(myPiece, desiredLocation);
    if (isPawn) {
        if (answer && isPawnEventTime(desiredLocation)) {
            PawnEventSignaler::activateState();
        }
        return (answer) ? AbstractHandler::handleRequest(myPiece, desiredLocation) : false;
    }

    if (isEmpty(desiredLocation)) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
      
    if (isEnemy(desiredLocation, myPiece.getColor())) {
        return AbstractHandler::handleRequest(myPiece, desiredLocation);
    }
    return false;
}

std::pair<bool, bool> DesiredSquare_Handler::HandleIfPawn(const Piece& myPiece, const Location& desiredLocation) {
    std::pair<bool, bool> answer;

    if (!isPawn(myPiece)) {
        answer.first = false;
        answer.second = false;
        return answer;
    }
    answer.first = true;

    if (isOnSameColum(myPiece, desiredLocation)) {
        answer.second = isEmpty(desiredLocation);
        return answer;
    }

    if (isEmpty(desiredLocation)) {
        answer.second = false;
        return answer;
    }
    answer.second = isEnemy(desiredLocation, myPiece.getColor());
    return answer;
}

bool DesiredSquare_Handler::isEnemy(const Location& m_desiredLocation, const Color& m_PieceColor ) {
    Board* myBoard{Board::getInstance()}; 
    Color desiredPieceColor = myBoard->isEmpty(m_desiredLocation).second;

    return desiredPieceColor == m_PieceColor ? false : true;
}

bool DesiredSquare_Handler::isOnSameColum(const Piece& myPiece, const Location& desiredLocation) {
    const auto[pieceColum, pieceRow] = myPiece.getCurrentLocation();
    const auto[desiredColum, desiredRow] = desiredLocation;

    if (pieceRow == desiredRow) { 
        return true;
    }
    return false;
}

bool DesiredSquare_Handler::isPawn(const Piece& myPiece) {
    const wchar_t* blackPawn = L"\u2659";
    const wchar_t* whitePawn = L"\u265F";
    if (*myPiece.getUnicodeCharacter()== *blackPawn || *myPiece.getUnicodeCharacter() == *whitePawn) {
        return true;
    } 
    return false; 
}

bool DesiredSquare_Handler::isEmpty(const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 

    return myBoard->isEmpty(m_desiredLocation).first; 
}

bool DesiredSquare_Handler::isPawnEventTime(const Location& desiredLocation) const {
    int BoardMax{7};
    int BoardMin{0};
    return  (desiredLocation.first == BoardMax || desiredLocation.first == BoardMin) ? true : false;
}