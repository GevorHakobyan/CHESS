#ifndef AVAILABLE_COORDINATES_HADNLER
#define AVAILABLE_COORDINATES_HANDLER


#include "AbstractHandler.hpp"

class AvailableCoordinates_Handler : public AbstractHandler {
    public:
    AvailableCoordinates_Handler(const Piece&, const Location);
    bool handleRequest() override;
};

#endif