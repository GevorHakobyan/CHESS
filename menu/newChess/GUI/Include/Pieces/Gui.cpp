#include "Gui.hpp"

void Gui::drawBoard() {
    Board myBoard{8,8};
    BoardPrinter printer{myBoard};
    printer.Print();
}

/*void Gui::printPeaces(BoardPrinter& printer) {
    PieceFactory myFactory;
    PieceList& myList = myFactory.getWhitePieces();
    PiecesPrinter::print(myList, printer);
}*/

