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

    private:
    void setEventInfo(const Color&, const Location&);
    void ActivateEventState();
  
    bool isZero(const Location&, const Location&);
    void updateBoardMatrix(Index&, Index&);
    void UndoBoardUpdate(Index&, Index&);
    void UpdatePiece_Data(Location&);
    void UndoPieceData_Update(Location&);
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
    QueHandler* m_QueHandler{nullptr};
    AvailableCoordinates_Handler* m_AvailableHandler{nullptr};
    Barriers_Handler* m_BarriersHandler{nullptr};
    DesiredSquare_Handler* m_DesiredHandler{nullptr};
    //Event
    PieceOptions m_PieceOptions;
    std::vector<Location> m_PieceLocations;
    bool m_EventState{false};
};
#endif //CHESS_MODEL_HPP