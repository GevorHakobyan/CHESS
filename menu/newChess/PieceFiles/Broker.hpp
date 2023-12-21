#ifndef BROKER_HPP
#define BROKER_HPP

#include "Board.hpp"
#include "MyKIngDispatcher.hpp"
#include "Enemy_KingDispatcher.hpp"

using PieceOptions = std::vector<const wchar_t*>;
using PieceLocations = std::vector<Location>;

class Broker {
    public :
    Broker() = default;
    static std::pair<bool, bool> HandleIfPawn(const Piece&, const Location&);
    static bool isEmpty(const Location&);
    static bool isEnemy(const Location&, const Color&);
    static bool isPawnEventTime(const Piece&, const Location&);
    static void CreatePawnEvent(const Location&, const Location&, const Color);
    static PieceOptions getPieceOptions(const Color&);
    static PieceLocations getPieceLocations(const Location&);
    static bool isMyKingUnderCheck(const Color, const Location&);
    static bool isEnemyKingUnderCheck(const Piece&);
    private:
    static bool isOnSameColum(const Piece&, const Location&);
    static bool isPawn(const Piece&);
    private:
    static MyKingDispatcher* m_KingDispatcher;
    static EnemyKing_Dispatcher* m_EnemyKingDispatcher;
};

#endif