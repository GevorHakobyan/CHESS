#include <Contoller.hpp>

Gui* Controller::m_Gui = nullptr;
Model* Controller::m_Model = nullptr;

Controller::Controller() {
    m_Gui = Gui::getInstance();
    m_Model = Model::getInstance();
}

void Controller::getInputFrom_User(Location& origin, Location& destination) {
    UpdateBoard_Data(origin, destination);
}

void Controller::UpdateBoard_View() {
    const auto[indexPrv, indexNew] = m_Model->getMoveIndexes();
}

void Controller::UpdateBoard_Data(Location& origin, Location& destination) {
    m_Model->Move(origin, destination);
}
