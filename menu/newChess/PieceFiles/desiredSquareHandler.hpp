#ifndef DESIRED_SQUARE_HANLDER
#define DESIRE_SQUARE_HANDLER

#include "AbstractHandler.hpp"
#include "Board.hpp"
#include <memory>

class DesiredSquare_Handler : public AbstractHandler {
   public:
   DesiredSquare_Handler() = default;
   bool handleRequest(const Piece&, const Location&) override;
   private:
   bool isEmpty(const Location&);
   bool isEnemy(const Piece&, const Location&);
};

#endif //DESIRED_SQUARE_HANDLER