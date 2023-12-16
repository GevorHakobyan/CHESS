#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "Model.hpp"
#include <View.hpp>


class Controller {
    public:
    Controller();
    void setBoard();
    void Play();

    private:
    void UpdateBoard_Data(Location&, Location&);
    void UpdateBoard_View();
    void isMoveSuccessful(bool);
    Model* m_Model{nullptr};
    View* m_View{nullptr};
    Map m_PieceMap{nullptr};
    UserInput m_UserInput;
};

#endif //CHESS_CONTROLLER_HPP