#include "Gui.hpp"

void Gui::drawBoard() {
    BoardView myBoard{8,8};
    BoardPrinter printer{myBoard};
    printer.Print();
}


