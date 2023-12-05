#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "Piece.hpp"
#include "Board.hpp"

class Handler {
    public:
    virtual Handler* setNextHandler(Handler*) = 0;
    virtual bool handleRequest() = 0;
};

#endif