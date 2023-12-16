#include <Controller.hpp>

Controller::Controller() 
: m_Model{Model::getInstance()}, m_View{View::getInstance(m_Model->getPieceList())} {};

void Controller::UpdateBoard_View() {

}

void Controller::UpdateBoard_Data(Location& origin, Location& destination) {
    //m_Model->Move(origin, destination);
}

void Controller::setBoard() {
    m_View->printBoardView();
    m_View->moveMapTo_Controller(m_PieceMap);
    m_Model->setMap(m_PieceMap);
}

void Controller::Play() {
    while(true) {
        m_View->Play();
        m_UserInput = m_View->GetInput();
        bool step = m_Model->Move(m_UserInput);
        isMoveSuccessful(step);
    }
}

void Controller::isMoveSuccessful(bool step) {
    if (!step) {
        return;
    } 
    const wchar_t* piece = m_Model->getMovedPiece_Character();
    const wchar_t* square = m_Model->getSquare_Character();
    m_View->updateBoardView(piece, square, m_UserInput.first, m_UserInput.second);
}