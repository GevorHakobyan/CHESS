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
    public: //methods
    Broker() = default;
    static Answer HandleIfPawn(const Piece&, const Location&);
    static bool isEmpty(const Location&);
    static bool isEnemy(const Location&, const Color&);
    static bool isPawnEventTime(const Piece&, const Location&);
    static void CreatePawnEvent(const Location&, const Location&, const Color);
    static PieceOptions getPieceOptions(const Color&);
    static PieceLocations getPieceLocations(const Location&);
    static bool isMyKingUnderCheck(const Piece&);
    static bool isEnemyKingUnderCheck(const Piece&);
    static bool isKingKilled(const Piece&);
    private:
    static bool isOnSameColum(const Piece&, const Location&);
    static bool isPawn(const Piece&);
    private:
    static MyKingDispatcherPtr m_KingDispatcher;
    static EnemyKingDispatcherPtr m_EnemyKingDispatcher;
    static GameStatePtr m_GameStateDispatcher; 
};

#endif