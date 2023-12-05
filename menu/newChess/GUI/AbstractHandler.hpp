#ifndef ABSTRACT_HANDLER_HPP
#define ABSTRACT_HANDLER_HPP

#include "Handler.hpp"

class AbstractHandler : public Handler {
    public:
    AbstractHandler(const Piece&, Location);
    Handler* setNextHandler(Handler*) override;
    bool handleRequest() override;
    protected:
    Handler* m_nextHandler{nullptr};
    const Piece& m_Piece;
    Location m_desiredLocation;
};

#endif