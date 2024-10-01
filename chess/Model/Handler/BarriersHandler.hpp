#ifndef BARRIERS_HANDLER_HPP
#define BARRIERS_HANDLER_HPP

#include <memory>
#include "AbstractHandler.hpp"
#include "Board.hpp"

class Barriers_Handler : public AbstractHandler {
    public:
    public:
    Barriers_Handler() = default;
    bool handleRequest(const Piece&, const Location&) override;
    private:
    bool isHorse(const Piece&);
    bool isPawn(const Piece&);
   
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
    private:
    Location m_desiredLocation;
    Location m_currentLocation;
    void setDesiredLocation(const Location&);
    void setCurrentLocation(const Piece&);
};

#endif