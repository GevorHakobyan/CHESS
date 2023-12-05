#include "PieceExistanceHandler.hpp"

PieceExistanceHandler::PieceExistanceHandler(const Piece& myPiece, const Location desiredLocation)
: AbstractHandler(myPiece, desiredLocation) {};

bool PieceExistanceHandler::handleRequest() {
    if (m_Piece.getUnicodeCharacter() != nullptr) {
        return AbstractHandler::handleRequest();
    }
    return false;
}
