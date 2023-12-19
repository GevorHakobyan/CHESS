#include "desiredSquareHandler.hpp"

bool DesiredSquare_Handler::handleRequest(const Piece& myPiece, const Location& desiredLocation) {
     if (isPawn(myPiece)) {
        if (isOnSameColum(myPiece, desiredLocation)) {
            return isEmpty(desiredLocation) ? true : false;
        }
        return isEmpty(desiredLocation) ? false : isEnemy(myPiece, desiredLocation);
    }

    return isEmpty(desiredLocation) ? true : isEnemy(myPiece, desiredLocation);
    return false;
}

bool DesiredSquare_Handler::isEmpty(const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 

    return myBoard->isEmpty(m_desiredLocation).first ? true : false;
    return true;
}

bool DesiredSquare_Handler::isEnemy(const Piece& m_Piece, const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 
    Color desiredPieceColor = myBoard->isEmpty(m_desiredLocation).second;

     return desiredPieceColor == m_Piece.getColor() ? false : true;
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
    move(29, 0);
    if (*myPiece.getUnicodeCharacter()== *blackPawn || *myPiece.getUnicodeCharacter() == *whitePawn) {
        return true;
    } 
    return false;  
}