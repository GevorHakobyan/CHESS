#ifndef GAMESTATE_DISPATCHER
#define GAMESTATE_DISPATCHER

#include "Dispatcher.hpp"
#include <assert.h>

class GameStateDispatcher : public Dispatcher {
    public:
    enum class CheckDirection{Horizontal, Vertical, R_Diagonal, L_Diagonal};
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
    void setInvadingPath(const Path&);
    ~GameStateDispatcher() = default;
    
    private:
    const PiecePtr findKing(const Piece&);
    void setKing(const PiecePtr);
    void setInvador(const Piece&);
    Path findSafeLocations() const;
    CheckDirection determineCheckDirection() const;
    Path takeUpandDown() const;
    Path takeRightandLeft() const;
    Path takeRDandLF() const;
    Path takeRUandLD() const;
    Path takePawnSafePlaces() const;
    Path takeKnightSafePlaces() const;
    bool isInvadorPawn() const;
    bool isInvadorHorse() const;
    bool isGameInDeadState() const;
    bool isKingKilled() const;
    GameStateDispatcher() = default;

    private:
    static thisPtr m_ptr;
    Path m_invadingPath{};
    PiecePtr m_King{nullptr};
    PiecePtr m_invador{nullptr};
};
#endif //GameSTATE_DISPATCHER