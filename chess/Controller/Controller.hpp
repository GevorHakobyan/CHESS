#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "Model.hpp"
#include "MainWindow.h"

class Controller {
    public:
    using Window = MainWindow;
    Controller();
    void Play();

    private:
    Model* m_Model{nullptr};
    Map m_PieceMap{nullptr};
    UserInput m_UserInput;
    Window m_GameWindow;
};

#endif 