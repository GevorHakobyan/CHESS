#include <Controller.hpp>

Controller::Controller() 
: m_Model{Model::getInstance()} {};

void Controller::UpdateBoard_View() {

}

void Controller::UpdateBoard_Data(Location& origin, Location& destination) {
    //m_Model->Move(origin, destination);
}

void Controller::setBoard() {
    BoardView* myBoard{BoardView::getInstance()};
    BoardPrinter printer{myBoard};
    PiecesPrinter piecePrinter{m_Model->getPieceList()};
    printer.Print(piecePrinter);
    piecePrinter.moveMapTo_View(m_PieceMap); 
    m_Mouse = MouseHandler::getInstance();
    m_Model->setMap(m_PieceMap);
}

void Controller::Play() {
    while(true) {
        m_UserInput = m_Mouse->getUserInput();
        bool step{false}; 
        step = m_Model->Move(m_UserInput);
        isMoveSuccessful(step);
    }
}

void Controller::isMoveSuccessful(bool step) {
    if (!step) {
        return;
    } 
    const wchar_t* piece = m_Model->getMovedPiece_Character();
    const wchar_t* square = m_Model->getSquare_Character();
    PiecesPrinter::printCharacter(piece, m_UserInput.second);
    PiecesPrinter::printCharacter(square, m_UserInput.first);
}