#ifndef GAMESTATE_DISPATCHER
#define GAMESTATE_DISPATCHER

#include "Dispatcher.hpp"
#include <assert.h>
#include <unordered_map>

class GameStateDispatcher : public Dispatcher {
    public: //usings
    using thisPtr = std::shared_ptr<GameStateDispatcher>;
    using Path = std::vector<Location>;
    using PiecePtr = const Piece*;
    using Defenders = std::vector<Piece&>;
    using DefendersMap = std::unordered_map<Location, Defenders>;

    public: //deleted ones
    GameStateDispatcher& operator=(const GameStateDispatcher&) = delete;
    GameStateDispatcher(const GameStateDispatcher&) = delete;

    public:
    static thisPtr getInstance();
    bool Dispatch(const Piece&) override;
    DefendersMap getDefender(); 
    void setInvadingPath(const Path&);
    ~GameStateDispatcher() = default;
    
    private:
    const PiecePtr findKing(const Piece&);
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
    Path m_invadingPath{};
};
#endif //GameSTATE_DISPATCHER