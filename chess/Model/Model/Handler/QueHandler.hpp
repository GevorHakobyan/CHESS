#ifndef QUE_HANDLER_HPP
#define QUE_HANDLER_HPP

#include "AbstractHandler.hpp"

class QueHandler : public AbstractHandler{
    public:
    QueHandler() = default;
    bool handleRequest(const Piece&, const Location&) override;
    bool m_que{true};
};
#endif