#include <Controller.hpp>

Controller::Controller() 
: m_Model{Model::getInstance()}, m_GameWindow{} {};

void Controller::Play() {

    bool step{false};
    while(true) {
        std::cout << "In controller\n";
        qDebug() << "conroller via debug()\n";
        m_UserInput = m_GameWindow.show(step);
        step = m_Model->Move(m_UserInput);
    }
}






