#ifndef PIECEEXISTEANCE_HANDLER_HPP
#define PIECEEXISTEANCE_HANDLER_HPP

#include "AbstractHandler.hpp"

class PieceExistanceHandler : public AbstractHandler{
    public:
    PieceExistanceHandler() = default;
    bool handleRequest(const Piece&, const Location&) override;
};

#endif