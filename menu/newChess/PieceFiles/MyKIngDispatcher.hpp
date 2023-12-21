#ifndef MYKING_DISPATCHER_HPP
#define MYKING_DISPATCHER_HPP

#include "Dispatcher.hpp"

class MyKingDispatcher : public Dispatcher {
    public:
    static MyKingDispatcher* getInstance();
    MyKingDispatcher& operator=(const MyKingDispatcher&) = delete;
    MyKingDispatcher(const MyKingDispatcher&) = delete;
    bool Dispatch(const Color);
    private:
    bool isAvailableFor_Enemy(const Location&, const Color);
    bool SearchInAvailable_Coordinates(const Piece&, const Location&);
    MyKingDispatcher();
    static MyKingDispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
};

#endif