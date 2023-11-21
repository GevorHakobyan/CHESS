#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include <memory>
#include "State.hpp"

//context
class Menu {
    public:
    Menu(State&);
    void changeState(State& newState);
    private:
    std::unique_ptr<State> m_currState{nullptr};
};

#endif