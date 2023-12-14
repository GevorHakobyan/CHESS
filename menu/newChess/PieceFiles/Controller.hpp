#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "Board.hpp"
#include "PiecesPrinter.hpp"
#include "BoardView.hpp"
#include "PieceExistanceHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "BarriersHandler.hpp"
#include "desiredSquareHandler.hpp"

using MAP = std::map<Location, Index>&;

class Controller {
    public:
    static Controller* getInstance();
    Controller& operator=(const Controller&) = delete;
    Controller(const Controller&) = delete;
    void Move(const Location&, Location&);

    private:
    bool isZero(const Location&, const Location&);
    void updateBoardView(const Location&, const Location&);
    void updateBoardMatrix(Index&, Index&);
    void updateMap(Location&, Index&);

    private:
    static Controller* m_Controller;
    Controller();
    Board* m_Board{nullptr};
    MAP m_pieceMap;
    PieceList& m_pieceList;
    PieceExistanceHandler* m_ExistanceHandler{nullptr};
    AvailableCoordinates_Handler* m_AvailableHandler{nullptr};
    Barriers_Handler* m_BarriersHandler{nullptr};
    DesiredSquare_Handler* m_DesiredHandler{nullptr};
};
#endif //CHESS_CONTROLLER_HPP