#ifndef GAMESTATE_DISPATCHER
#define GAMESTATE_DISPATCHER

#include "Dispatcher.hpp"
#include <assert.h>
#include <unordered_set>
#include <ranges>
#include <optional>

class GameStateDispatcher : public Dispatcher {
    public: //usings
    using thisPtr = std::shared_ptr<GameStateDispatcher>;
    using Path = std::vector<Location>;
    using PiecePtr =  const Piece*;
    using Coordinates = std::vector<Location>;
    using DefenderMap = std::map<Location, Location>;

    public: //deleted ones
    GameStateDispatcher& operator=(const GameStateDispatcher&) = delete;
    GameStateDispatcher(const GameStateDispatcher&) = delete;

    public:
    static thisPtr getInstance();
    bool Dispatch(const Piece&) override;
    void setInvadingPath(const Path&);
    DefenderMap getDefenders();
    ~GameStateDispatcher() = default;
    
    private:
    std::pair<bool, Location> canDefend(const Piece&);
    const PiecePtr findKing(const Piece&) const;
    std::pair<bool, Location> HandlePawnCase(const Piece&);
    void setKing(const PiecePtr);
    void setInvador(const Piece&);
    Path findEscapingPath() const;
    bool isAnySafe(const Path&);
    Path takePawnSafePlaces() const;
    bool isInvadorPawn() const;
    bool isGameInDeadState();
    bool isKingKilled() ;
    bool isAvailableForInvador(const Location&) const;
    bool isSafe(const Location&);
    GameStateDispatcher() = default;

    private:
    static thisPtr m_ptr;
    PiecePtr m_King{nullptr};
    PiecePtr m_invador{nullptr};
    Path m_invadingPath;
};
#endif //GameSTATE_DISPATCHER