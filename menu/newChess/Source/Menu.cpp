#include "Menu.hpp"
#include <memory>

Menu::Menu(State& currState)
: m_currState{std::make_unique<State>(currState)} {}

void Menu::changeState(State& newState) {
    State* myState {&newState};
    m_currState.reset(myState);
}

