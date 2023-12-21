#ifndef BROKER_HPP
#define BROKER_HPP

#include "Board.hpp"
#include "KIngDispatcher.hpp"

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
    static bool isKingUnderCheck(const Color, const Location&);
    private:
    static bool isOnSameColum(const Piece&, const Location&);
    static bool isPawn(const Piece&);
    private:
    static KingDispatcher* m_KingDispatcher;
    
};

#endif