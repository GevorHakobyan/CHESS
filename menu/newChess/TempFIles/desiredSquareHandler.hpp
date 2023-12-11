#ifndef DESIRED_SQUARE_HANLDER
#define DESIRE_SQUARE_HANDLER

#include "AbstractHandler.hpp"
#include "Board.hpp"
#include <memory>

class DesiredSquare_Handler : public AbstractHandler {
   public:
   DesiredSquare_Handler(const Piece&, const Location);
   bool handleRequest() override;
   private:
   bool isEmpty();
   bool isEnemy();
};

#endif