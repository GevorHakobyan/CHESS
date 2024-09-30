#ifndef MYKING_DISPATCHER_HPP
#define MYKING_DISPATCHER_HPP

#include "Dispatcher.hpp"

class MyKingDispatcher : public Dispatcher {
    public:
    using thisPtr = std::shared_ptr<MyKingDispatcher>;
    public: //deleted ones
    MyKingDispatcher& operator=(const MyKingDispatcher&) = delete;
    MyKingDispatcher(const MyKingDispatcher&) = delete;
    public:
    static thisPtr getInstance();
    bool Dispatch(const Piece&) override;
    ~MyKingDispatcher()  =default;
    
    private:
    bool isAvailableFor_Enemy(const Location&, const Color);
    MyKingDispatcher();
    static thisPtr m_Dispatcher;
};

#endif