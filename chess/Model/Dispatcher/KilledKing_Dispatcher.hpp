#ifndef KILLEDKING_DISPATCHER
#define KILLEDKING_DISPTACHER

#include "Dispatcher.hpp"

class KilledKingDispatcher : public Dispatcher {
    public: //deleted ones
    KilledKingDispatcher& operator=(const KilledKingDispatcher&) = delete;
    KilledKingDispatcher(const KilledKingDispatcher&) = delete;
    public:
    static KilledKingDispatcher* getInstance();
    bool Dispatch(const Piece&) override;
    
    private:
    void searchKing(const Piece&) ;
    bool isKingKilled(const Piece& king);
    bool isCoordinateUnderCheck(const Location&);
    bool isKing(const wchar_t, const wchar_t) const;
    KilledKingDispatcher();
    static KilledKingDispatcher* m_Dispatcher;
    Barriers_Handler* m_Handler{nullptr};
    private:
    bool m_isKilled{false};
};
#endif //KILLEDKING_DISPTACHER