#ifndef KING_DISPATCHER_HPP
#define KING_DISPATCHER_HPP

#include "BarriersHandler.hpp"
#include "Board.hpp"

class KingDispatcher{
    public:
    static KingDispatcher* getInstance();
    KingDispatcher& operator=(const KingDispatcher&) = delete;
    KingDispatcher(const KingDispatcher&) = delete;
    bool Dispatch(const Color);
    private:
    Location determineKingLocation(const wchar_t*);
    bool isAvailableFor_Enemy(const Location&, const Color);
    bool SearchInAvailable_Coordinates(const Piece&, const Location&);
    KingDispatcher();
    static KingDispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
};

#endif