#ifndef BROKER_HPP
#define BROKER_HPP

#include "Board.hpp"
#include "MyKIngDispatcher.hpp"
#include "Enemy_KingDispatcher.hpp"
#include "GameState_Dispatcher.hpp"

using PieceOptions = std::vector<const wchar_t*>;
using PieceLocations = std::vector<Location>;

class Broker {
    public://usings
    using Answer = std::tuple<bool, bool, bool>;
    using MyKingDispatcherPtr = std::shared_ptr<MyKingDispatcher>;
    using EnemyKingDispatcherPtr = std::shared_ptr<EnemyKing_Dispatcher>;
    using GameStatePtr = std::shared_ptr<GameStateDispatcher>;
    using Color = Piece::Color;
    public: //methods
    Broker() = default;
    static bool isMyKingUnderCheck(const Piece&);
    static bool isEnemyKingUnderCheck(const Piece&);
    static bool isKingKilled(const Piece&);
    private:
    static bool canDefend(const std::pair<Location, Location>&);
    static void moveDefender(const Location&, const Location&);
    static void resetDefender(const Location&, const Location&);
    private:
    static MyKingDispatcherPtr m_KingDispatcher;
    static EnemyKingDispatcherPtr m_EnemyKingDispatcher;
    static GameStatePtr m_GameStateDispatcher; 
};

#endif