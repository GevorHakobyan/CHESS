#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "Piece.hpp"

class Handler {
    public:
    virtual Handler* setNextHandler(Handler*) = 0;
    virtual bool handleRequest(const Piece&, const Location&) = 0;
};

#endif