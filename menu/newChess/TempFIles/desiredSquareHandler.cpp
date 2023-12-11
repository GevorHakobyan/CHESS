#include "desiredSquareHandler.hpp"

DesiredSquare_Handler::DesiredSquare_Handler(const Piece& myPiece, const Location desiredLocation)
: AbstractHandler(myPiece, desiredLocation) {};

bool DesiredSquare_Handler::handleRequest() {
    return isEmpty() ? true : isEnemy();
}

bool DesiredSquare_Handler::isEmpty() {
    Board* myBoard{Board::getInstance()}; 
    return myBoard->isEmpty(m_desiredLocation).first ? true : false;
}

bool DesiredSquare_Handler::isEnemy() {
     Board* myBoard{Board::getInstance()}; 
     return myBoard->isEmpty(m_desiredLocation).second == m_Piece->getColor() ? false : true;
}