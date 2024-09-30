#ifndef ENEMY_KING_DISPATCHER
#define ENEMY_KING_DISPATCHER

#include "Dispatcher.hpp"


class EnemyKing_Dispatcher : public Dispatcher{
    public:
    using Path = std::vector<Location>;
    using thisPtr = std::shared_ptr<EnemyKing_Dispatcher>;
    public: //deleted ones
    EnemyKing_Dispatcher& operator=(const EnemyKing_Dispatcher&) = delete;
    EnemyKing_Dispatcher(const EnemyKing_Dispatcher&) = delete;

    public:
    static thisPtr getInstance();
    bool Dispatch(const Piece&) override;
    const Path& getInvadingPath() const;
    ~EnemyKing_Dispatcher() = default;

    private:
    bool isAvailableFor_Me(const Piece&, const Location&);
    EnemyKing_Dispatcher();
    static thisPtr m_Dispatcher;
    Path m_InvadingPath;
};

#endif