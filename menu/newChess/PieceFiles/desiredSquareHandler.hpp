#ifndef DESIRED_SQUARE_HANDLER
#define DESIRED_SQUARE_HANDLER

#include "AbstractHandler.hpp"
#include  "Board.hpp"
#include <memory>

class DesiredSquare_Handler : public AbstractHandler {
   public:
   DesiredSquare_Handler() = default;
   bool handleRequest(const Piece&, const Location&) override;
   private:
   bool isPawn(const Piece&);
   bool isOnSameColum(const Piece&, const Location&);
   bool isEmpty(const Location&);
   bool isEnemy(const Piece&, const Location&);
   int a{0};
};

#endif //DESIRED_SQUARE_HANDLER