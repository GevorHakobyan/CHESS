#ifndef GAMESTATE_DISPATCHER
#define GAMESTATE_DISPATCHER

#include "Dispatcher.hpp"
#include <assert.h>

class GameStateDispatcher : public Dispatcher {
    public: //usings
    using thisPtr = std::shared_ptr<GameStateDispatcher>;
    using Path = std::vector<Location>;
    using PiecePtr = const Piece*;

    public: //deleted ones
    GameStateDispatcher& operator=(const GameStateDispatcher&) = delete;
    GameStateDispatcher(const GameStateDispatcher&) = delete;

    public:
    static thisPtr getInstance();
    bool Dispatch(const Piece&) override;
    ~GameStateDispatcher() = default;
    
    private:
    const PiecePtr findKing(const Piece&);
    void setKing(const PiecePtr);
    void setInvador(const Piece&);
    Path findEscapingPath() const;
    bool isAnySafe(const Path&) const;
    Path takePawnSafePlaces() const;
    bool isInvadorPawn() const;
    bool isGameInDeadState() const;
    bool isKingKilled() const;
    bool isAvailableForInvador(const Location&) const;
    bool isSafe(const Location&) const;
    GameStateDispatcher() = default;

    private:
    static thisPtr m_ptr;
    PiecePtr m_King{nullptr};
    PiecePtr m_invador{nullptr};
};
#endif //GameSTATE_DISPATCHER