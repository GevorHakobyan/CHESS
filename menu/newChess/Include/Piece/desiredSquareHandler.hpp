#ifndef DESIRED_SQUARE_HANLDER
#define DESIRE_SQUARE_HANDLER

#include "Handler.hpp"
#include <memory>

class DesiredSquare_Handler : public Handler {
    private:
    std::unique_ptr<Handler> m_nextHandler{nullptr};
};

#endif