#include "View.hpp"

/*View* View::m_View = nullptr;

View::View(const PieceList& myPieceList)
: m_PieceList{myPieceList}, m_Mouse{nullptr} {};

View* View::getInstance(const PieceList& myPieceList) {
    if (nullptr == m_View) {
        m_View = new View(myPieceList);
    }
    return m_View;
}
void View::printBoardView() {
    BoardView* myBoard{BoardView::getInstance()};
    BoardPrinter printer{myBoard};
    PiecesPrinter piecePrinter{m_PieceList};
    printer.Print(piecePrinter);
    piecePrinter.moveMapTo_View(m_pieceMap); 
    m_Mouse = MouseHandler::getInstance();
}

void View::Play() {
    m_UserInput = m_Mouse->getUserInput();
}

void View::moveMapTo_Controller(Map& controllerMap) {
    controllerMap = std::move(m_pieceMap);
}

UserInput View::GetInput() const {
    return m_UserInput;
}

void View::updateBoardView(const wchar_t* piece, const wchar_t* square, Location& origin, Location& destination) {
    PiecesPrinter::printCharacter(piece, destination);
    PiecesPrinter::printCharacter(square, origin);
}*/