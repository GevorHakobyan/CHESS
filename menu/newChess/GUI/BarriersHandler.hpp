#ifndef BARRIERS_HANDLER_HPP
#define BARRIERS_HANDLER_HPP

#include "AbstractHandler.hpp"
#include <memory>

class Barriers_Handler : public AbstractHandler {
    public:
    Barriers_Handler(const Piece&, const Location);
    bool handleRequest() override;
    private:
    bool isHorse();
   
    bool handleOnSameRow();
    bool handleOnSameColum();
    bool handlePrependicular();
    bool goUp();
    bool goDown();
    bool goRight();
    bool goLeft();
    bool goRightUp();
    bool goRightDown();
    bool goLeftUp();
    bool goLeftDown(); 

    bool isOnSameRow();
    bool isOnSameColum(); 
    bool isAbove();
    bool isOnRight();
    bool isOnRightBeneathCorner();
    bool isOnLeftAboveCorner();
};

#endif