#ifndef ENEMY_KING_DISPATCHER
#define ENEMY_KING_DISPATCHER

#include "Dispatcher.hpp"


class EnemyKing_Dispatcher : public Dispatcher{
    public:
    static EnemyKing_Dispatcher* getInstance();
    EnemyKing_Dispatcher& operator=(const EnemyKing_Dispatcher&) = delete;
    EnemyKing_Dispatcher(const EnemyKing_Dispatcher&) = delete;
    bool Dispatch(const Piece&);
    private:
    bool handlePawnCase(const Piece&, const Location&);
    bool isPawn(const Piece&);
    bool isOnSameColum(const Location&, const Location&);
    bool isAvailableFor_Me(const Piece&, const Location&);
    EnemyKing_Dispatcher();
    static EnemyKing_Dispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
};

#endif