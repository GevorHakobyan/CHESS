#ifndef PIECEEXISTEANCE_HANDLER_HPP
#define PIECEEXISTEANCE_HANDLER_HPP

#include "AbstractHandler.hpp"
#include <ncurses.h>

class PieceExistanceHandler : public AbstractHandler{
    public:
    PieceExistanceHandler() = default;
    bool handleRequest(const Piece&, const Location&) override;
};

#endif