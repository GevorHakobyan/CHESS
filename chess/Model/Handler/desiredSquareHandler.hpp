#ifndef DESIRED_SQUARE_HANDLER
#define DESIRED_SQUARE_HANDLER

#include "AbstractHandler.hpp"
#include "Board.hpp"
#include "PawnEventSignaler.hpp"
#include <memory>

class DesiredSquare_Handler : public AbstractHandler {
   public:
   DesiredSquare_Handler() = default;
   bool handleRequest(const Piece&, const Location&) override;
   private:
   bool isPawn(const Piece&);
   bool isOnSameColum(const Piece&, const Location&);
   bool isEnemy(const Location&, const Color&);
   bool isEmpty(const Location&);
   bool isPawnEventTime(const Location&) const;
   std::pair<bool, bool> HandleIfPawn(const Piece&, const Location&);
};

#endif //DESIRED_SQUARE_HANDLER