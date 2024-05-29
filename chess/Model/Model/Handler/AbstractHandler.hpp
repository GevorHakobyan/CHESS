#ifndef ABSTRACT_HANDLER_HPP
#define ABSTRACT_HANDLER_HPP

#include "Handler.hpp"

class AbstractHandler : public Handler {
    public:
    AbstractHandler() = default;
    Handler* setNextHandler(Handler*) override;
    bool handleRequest(const Piece&, const Location&) override;
    protected:
    Handler* m_nextHandler{nullptr};
};

#endif