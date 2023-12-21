#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "Model.hpp"
#include "BoardPrinter.hpp"
#include "MouseHandler.hpp"


class Controller {
    public:
    Controller();
    void setBoard();
    void Play();

    private:
    void CreatePawnEvent();
    void printEventOptions(const PieceOptions&, const PieceLocations&);
    Location getUserChoice();
    std::optional<Location> evaluateChoice(const Location&);
    std::optional<Location> approximateChoice(const Location&, const Location&);
    void ImpelementGraphically(const PieceLocations&);
    void isMoveSuccessful(bool);
    Model* m_Model{nullptr};
    Map m_PieceMap{nullptr};
    MouseHandler* m_Mouse{nullptr};
    UserInput m_UserInput;
};

#endif 