#ifndef BARRIERS_HANDLER_HPP
#define BARRIERS_HANDLER_HPP

#include <memory>
#include "Board.hpp"
#include "AbstractHandler.hpp"


class Barriers_Handler : public AbstractHandler {
    public:
    Barriers_Handler() = default;
    bool handleRequest(const Piece&, const Location&) override;
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
    private:
    Piece* m_Piece {nullptr};
    Location* m_desiredLocation{nullptr};
    void setPiece(Piece&);
    void setLocation(Location&);
};

#endif