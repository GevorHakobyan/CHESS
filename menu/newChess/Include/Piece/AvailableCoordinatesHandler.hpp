#ifndef AVAILABLE_COORDINATES_HADNLER
#define AVAILABLE_COORDINATES_HANDLER

#include "Pieace.hpp"
#include "Handler.hpp"
#include <memory>

class AvailableCoordinates_Handler : public Handler {
    private:
    std::unique_ptr<Handler> m_nextHandler{nullptr};
};

#endif