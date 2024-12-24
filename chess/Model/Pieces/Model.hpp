#ifndef CHESS_MODEL_HPP
#define CHESS_MODEL_HPP

#include "PieceExistanceHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "BarriersHandler.hpp"
#include "desiredSquareHandler.hpp"
#include "QueHandler.hpp"
#include "Broker.hpp"
#include <QDebug>
#include <iostream>

using Map = std::unique_ptr<std::map<Location, Index>>;
using UserInput = std::pair<Location, Location>;

template <typename T>
using HandlerPtr = std::shared_ptr<T>;

class Model {
    public:
    using PieceCharacter = wchar_t*;
    using Color = Piece::Color;
    static Model* getInstance();
    Model& operator=(const Model&) = delete;
    Model(const Model&) = delete;
    bool Move(UserInput);
    const PieceList& getPieceList() const;
    //Event 
    void DeactivateEvent();
    bool isEventActive() const;
    bool isGameFinished() const; 

    private:
    void isEvent(UserInput);
    void ActivateEventState();
    void updateBoardMatrix(Index&, Index&);
    void UndoBoardUpdate(Index&, Index&);
    void UpdatePiece_Data(Location&);
    void UndoPieceData_Update(Location&);
    void UndoStep(UserInput);
    bool isStepValid(const UserInput&);
    void takeStep(Location, Index);
  

    private:
    static Model* m_Model;
    Model();
    Board* m_Board{nullptr};
    wchar_t* m_Piece{nullptr};
    const PieceList& m_pieceList;
    HandlerPtr<PieceExistanceHandler> m_ExistanceHandler{nullptr};
    HandlerPtr<QueHandler> m_QueHandler{nullptr};
    HandlerPtr<AvailableCoordinates_Handler> m_AvailableHandler{nullptr};
    HandlerPtr<Barriers_Handler> m_BarriersHandler{nullptr};
    HandlerPtr<DesiredSquare_Handler> m_DesiredHandler{nullptr};
    //Event
    public:
    void ImplementEvent(UserInput, PieceCharacter);
    Color getPawnColor() const;
    private:
    void setPawnColor(Color);
    Color m_pawnColor{};
    bool m_EventState{false};
};
#endif //CHESS_MODEL_HPP