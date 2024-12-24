#include <Controller.hpp>
#include <iostream>

Controller::Controller() 
: m_Model{Model::getInstance()}, m_GameWindow{} {};

void Controller::Play() {

    bool step{false};
    while(true) {
        m_UserInput = m_GameWindow.show(step);
        std::cout << "Here\n";
        swap();
        step = m_Model->Move(m_UserInput);
        CheckIfEvent(step);
    }
}

void Controller::swap() {
    auto&[origin, destination] = m_UserInput;
    std::swap(origin.first, origin.second);
    std::swap(destination.first, destination.second);
}

void Controller::CheckIfEvent(bool step) {
    if (m_Model->isEventActive()) {
        PawnColor color = (m_Model->getPawnColor() == Color::Black) ? PawnColor::Black : PawnColor::White;
        m_GameWindow.show(step, color);
        auto character = m_GameWindow.getPromotedCharacter();
        wchar_t* newCharater = new wchar_t[character.size() + 1];
        std::wcscpy(newCharater, character.c_str());

        m_Model->ImplementEvent(m_UserInput, newCharater);
        m_Model->DeactivateEvent();

    }
}




