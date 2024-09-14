#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "Piece.hpp"

class Handler {
    public:
    using HandlerPtr = std::unique_ptr<Handler>;
    virtual HandlerPtr setNextHandler(HandlerPtr) = 0;
    virtual bool handleRequest(const Piece&, const Location&) = 0;
};

#endif