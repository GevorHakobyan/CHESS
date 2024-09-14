#ifndef MYKING_DISPATCHER_HPP
#define MYKING_DISPATCHER_HPP

#include "Dispatcher.hpp"

class MyKingDispatcher : public Dispatcher {
    public: //deleted ones
    MyKingDispatcher& operator=(const MyKingDispatcher&) = delete;
    MyKingDispatcher(const MyKingDispatcher&) = delete;
    public:
    static MyKingDispatcher* getInstance();
    bool Dispatch(const Piece&) override;
    
    private:
    bool isAvailableFor_Enemy(const Location&, const Color);
    MyKingDispatcher();
    static MyKingDispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
};

#endif