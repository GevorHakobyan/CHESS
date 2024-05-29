#ifndef AVAILABLE_COORDINATES_HADNLER
#define AVAILABLE_COORDINATES_HANDLER


#include "AbstractHandler.hpp"
#include <ncurses.h>

class AvailableCoordinates_Handler : public AbstractHandler {
    public:
    AvailableCoordinates_Handler() = default;
    bool handleRequest(const Piece&, const Location&) override;
    int a{0};
};

#endif