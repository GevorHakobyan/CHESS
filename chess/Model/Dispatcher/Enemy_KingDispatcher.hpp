#ifndef ENEMY_KING_DISPATCHER
#define ENEMY_KING_DISPATCHER

#include "Dispatcher.hpp"


class EnemyKing_Dispatcher : public Dispatcher{
    public: //deleted ones
    EnemyKing_Dispatcher& operator=(const EnemyKing_Dispatcher&) = delete;
    EnemyKing_Dispatcher(const EnemyKing_Dispatcher&) = delete;

    public:
    static EnemyKing_Dispatcher* getInstance();
    bool Dispatch(const Piece&) override;

    private:
    bool isAvailableFor_Me(const Piece&, const Location&);
    EnemyKing_Dispatcher();
    static EnemyKing_Dispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
};

#endif