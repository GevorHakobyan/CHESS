#ifndef CHESS_MODEL_HPP
#define CHESS_MODEL_HPP


#include "PieceExistanceHandler.hpp"
#include "AvailableCoordinatesHandler.hpp"
#include "BarriersHandler.hpp"
#include "desiredSquareHandler.hpp"
#include "QueHandler.hpp"
#include "Board.hpp"

using Map = std::unique_ptr<std::map<Location, Index>>;
using UserInput = std::pair<Location, Location>;

template <typename T>
using HandlerPtr = std::shared_ptr<T>;

class Model {
    public:
    static Model* getInstance();
    Model& operator=(const Model&) = delete;
    Model(const Model&) = delete;
    bool Move(UserInput);
    const PieceList& getPieceList() const;
    bool isEven(const int);
    bool isOdd(const int);
    bool getSquareColor(const Location&);
    Color getPieceColor(const Index&); 
    //Event 
    void DeactivateEvent();
    bool isEventActive() const;
    const PieceOptions& getPieceOptions() const;
    const PieceLocations& getPieceLocations() const;
    void ImplementUserChoice(const Location&, const UserInput&);
    void setUserChoice_Character(const Location&);  
    bool isGameFinished() const; 

    private:
    void setEventInfo(const Color&, const Location&);
    void ActivateEventState();
    bool areSquaresValid(const Location&, const Location&);
    bool isOriginNullable(const Location&) const;
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
    const PieceList& m_pieceList;
    HandlerPtr<PieceExistanceHandler> m_ExistanceHandler{nullptr};
    HandlerPtr<QueHandler> m_QueHandler{nullptr};
    HandlerPtr<AvailableCoordinates_Handler> m_AvailableHandler{nullptr};
    HandlerPtr<Barriers_Handler> m_BarriersHandler{nullptr};
    HandlerPtr<DesiredSquare_Handler> m_DesiredHandler{nullptr};
    //Event
    PieceOptions m_PieceOptions;
    std::vector<Location> m_PieceLocations;
    bool m_EventState{false};
};
#endif //CHESS_MODEL_HPP