#include <Controller.hpp>

Controller::Controller() 
: m_Model{Model::getInstance()}, m_GameWindow{} {};

void Controller::Play() {

    while(true) {
        bool step{false}; 
        m_UserInput = m_GameWindow.show(step);
        step = m_Model->Move(m_UserInput);
    }
}






