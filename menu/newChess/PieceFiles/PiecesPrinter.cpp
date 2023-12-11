#include "PiecesPrinter.hpp"
Index PiecesPrinter::m_pieceIndex{0,0};

void PiecesPrinter::getLocation(Location& location, const SquareIdentity& identities, int index) {
     location.first = std::get<0>(identities[index]);
     location.second = std::get<1>(identities[index]);
}

void PiecesPrinter::setBoardMap(Location& location, Board* myBoard) {
     myBoard->setMap(location, m_pieceIndex);
}

void PiecesPrinter::print(const SquareIdentity& identities) {
    Board* myBoard{Board::getInstance()}; //what will happen if I use smart pointer??
    const PieceList& myList{myBoard->getPieceList()};

    int index{0};
    Location location;

    for (int i{0}; i < 8; ++i) {
        for (int j{0}; j < 8; ++j) {
            m_pieceIndex.first = i;
            m_pieceIndex.second = j;
        
            getLocation(location, identities, index);
            setBoardMap(location, myBoard);

            if (myList[i][j] != nullptr) {
                printPiece(myList[i][j]->getUnicodeCharacter(), location);
            }
            ++index;
        }
    } 

    myBoard = nullptr;
}

void PiecesPrinter::printPiece(const wchar_t* piece, const Location& location) {
    move (location.first - 1, location.second - 3); 
    addwstr(piece);
}
void PiecesPrinter::printAvailables() {
    Board* myBoard{Board::getInstance()}; //what will happen if I use smart pointer??
    const PieceList& myList{myBoard->getPieceList()};
    const AvailableCoordinates& myref = myList[1][0]->getAvailableCoordinates();
    move(10, 0);
   for (int i{0}; i < myref.size(); ++i) {
        printw("%d", myref[i].first);
        printw(" ");
        printw("%d", myref[i].second);
        printw("\n");
    }
}