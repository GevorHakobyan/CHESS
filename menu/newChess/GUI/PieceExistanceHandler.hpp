#ifndef PIECEEXISTEANCE_HANDLER_HPP
#define PIECEEXISTEANCE_HANDLER_HPP

#include "AbstractHandler.hpp"

class PieceExistanceHandler : public AbstractHandler{
    public:
    PieceExistanceHandler(const Piece&, const Location);
    bool handleRequest() override;
};

#endif