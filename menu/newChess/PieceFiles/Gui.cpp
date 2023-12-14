#include "Gui.hpp"

void Gui::drawBoard() {
    BoardView* myBoard{BoardView::getInstance()};
    BoardPrinter printer{myBoard};
    printer.Print();
}

void Gui::Play() {
    MouseHandler* mouseHandler{MouseHandler::getInstance()};
    while (true) {
        mouseHandler->HandleClicks();
    }
}

