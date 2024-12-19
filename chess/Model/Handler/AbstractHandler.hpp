#ifndef ABSTRACT_HANDLER_HPP
#define ABSTRACT_HANDLER_HPP

#include <memory>
#include "Piece.hpp"

class AbstractHandler {
    public:
    using HandlerPtr = std::shared_ptr<AbstractHandler>;
    AbstractHandler() = default;
    HandlerPtr setNextHandler(HandlerPtr);
    virtual bool handleRequest(const Piece&, const Location&);
    protected:
    HandlerPtr m_nextHandler;
};

#endif