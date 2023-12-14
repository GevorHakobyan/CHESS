#include "desiredSquareHandler.hpp"
bool DesiredSquare_Handler::handleRequest(const Piece& myPiece, const Location& desiredLocation) {
    return isEmpty(desiredLocation) ? true : isEnemy(myPiece, desiredLocation);
}

bool DesiredSquare_Handler::isEmpty(const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 
    return myBoard->isEmpty(m_desiredLocation).first ? true : false;
}

bool DesiredSquare_Handler::isEnemy(const Piece& m_Piece, const Location& m_desiredLocation) {
     Board* myBoard{Board::getInstance()}; 
     return myBoard->isEmpty(m_desiredLocation).second == m_Piece.getColor() ? false : true;
}