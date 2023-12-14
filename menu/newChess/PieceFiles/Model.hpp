#ifndef CHESS_MODEL_HPP
#define CHESS_MODEL_HPP

#include "Board.hpp"
#include "PieceExistanceHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "BarriersHandler.hpp"
#include "desiredSquareHandler.hpp"

using MAP = std::map<Location, Index>&;
using MoveIndexes = std::pair<Index, Index>;

class Model {
    public:
    static Model* getInstance();
    Model& operator=(const Model&) = delete;
    Model(const Model&) = delete;
    void Move(const Location&, Location&);
    void setMoveIndexes(Index&, Index&);
    MoveIndexes getMoveIndexes() const;

    private:
    bool isZero(const Location&, const Location&);
    void updateBoardMatrix(Index&, Index&);
    void updateMap(Location&, Index&);

    private:
    static Model* m_Model;
    Model();
    Board* m_Board{nullptr};
    MAP m_pieceMap;
    PieceList& m_pieceList;
    PieceExistanceHandler* m_ExistanceHandler{nullptr};
    AvailableCoordinates_Handler* m_AvailableHandler{nullptr};
    Barriers_Handler* m_BarriersHandler{nullptr};
    DesiredSquare_Handler* m_DesiredHandler{nullptr};
    Index m_Target_Prev_Index;
    Index m_Target_New_Index;
};
#endif //CHESS_MODEL_HPP