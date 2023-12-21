#ifndef DESIRED_SQUARE_HANDLER
#define DESIRED_SQUARE_HANDLER

#include "AbstractHandler.hpp"
#include  "Broker.hpp"
#include <memory>

class DesiredSquare_Handler : public AbstractHandler {
   public:
   DesiredSquare_Handler() = default;
   bool handleRequest(const Piece&, const Location&) override;
};

#endif //DESIRED_SQUARE_HANDLER