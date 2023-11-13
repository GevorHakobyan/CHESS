#ifndef BARRIERS_HANDLER_HPP
#define BARRIERS_HANDLER_HPP

#include "Handler.hpp"
#include <memory>

class Barriers_Handler {
    private:
    std::unique_ptr<Handler> m_nextHandler{nullptr};
};

#endif