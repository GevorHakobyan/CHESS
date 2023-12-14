#include "Gui.hpp"

Gui* Gui::m_Gui = nullptr;

Gui* Gui::getInstance() {
    if (nullptr == m_Gui) {
        m_Gui = new Gui;
    }
    return m_Gui;
}
void Gui::drawBoard() {
    BoardView* myBoard{BoardView::getInstance()};
    BoardPrinter printer{myBoard};
    printer.Print();
}

void Gui::Play() {
    /*MouseHandler* mouseHandler{MouseHandler::getInstance()};
    while (true) {
        mouseHandler->HandleClicks();
    }*/
}
