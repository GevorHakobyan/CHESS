#ifndef CHESS_CONTROLLER_HPP
#define CHESS_CONTROLLER_HPP

#include "Model.hpp"
#include "GameWindow.h"

class Controller {
    public:
    using Window = MainWindow;
    using Color = Model::Color;
    using PieceColor = MainWindow::PieceColor;
    Controller();
    void Play();

    private:
    void InterruptGame();
    bool isGameOn();
    void CheckIfEvent(bool);
    void swap();
    Model* m_Model{nullptr};
    Map m_PieceMap{nullptr};
    UserInput m_UserInput;
    Window m_GameWindow;
};

#endif 