#include "State.hpp"
#include <memory>

void State::setMenu(Menu& myMenu) {
    this->m_myMenu = std::make_unique<Menu>(myMenu);
}