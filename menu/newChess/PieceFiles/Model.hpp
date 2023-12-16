#ifndef CHESS_MODEL_HPP
#define CHESS_MODEL_HPP

#include "Board.hpp"
#include "PieceExistanceHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "BarriersHandler.hpp"
#include "desiredSquareHandler.hpp"

using Map = std::unique_ptr<std::map<Location, Index>>;
using UserInput = std::pair<Location, Location>;

class Model {
    public:
    static Model* getInstance();
    Model& operator=(const Model&) = delete;
    Model(const Model&) = delete;
    bool Move(UserInput);
    void setMap(Map&);
    const PieceList& getPieceList() const;
    const wchar_t* getMovedPiece_Character();
    const wchar_t* getSquare_Character();
    void setMovedPiece_Character(const Location&);
    void setMovedSquare_Character(const Location&);
    bool isEven(const int);
    bool getColor(const Location&);

    private:
    bool isZero(const Location&, const Location&);
    void updateBoardMatrix(Index&, Index&);
    void updateMap(Location&, Index&);

    private:
    static Model* m_Model;
    Model();
    Board* m_Board{nullptr};
    Map m_pieceMap{nullptr};
    const PieceList& m_pieceList;
    wchar_t* m_Piece;
    wchar_t* m_Square;
    //handlers
    PieceExistanceHandler* m_ExistanceHandler{nullptr};
    AvailableCoordinates_Handler* m_AvailableHandler{nullptr};
    Barriers_Handler* m_BarriersHandler{nullptr};
    DesiredSquare_Handler* m_DesiredHandler{nullptr};
};
#endif //CHESS_MODEL_HPP