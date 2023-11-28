#include "PiecesPrinter.hpp"

void PiecesPrinter::print(const SquareIdentity& identaties) {
    int y;
    int x;

    PieceFactory myFac;
    PieceList& myBlackList = myFac.getBlackPieces();

    for (int i{0}; i < 16; ++i) {
        y = std::get<0>(identaties[i]);
        x = std::get<1>(identaties[i]);

        move(y - 1, x - 4);
        addwstr(myBlackList[i]->getUnicodeCharacter());
    }

    PieceList& myWhiteList = myFac.getWhitePieces();

    for (int i {48}; i < 64; ++i) {
        y = std::get<0>(identaties[i]);
        x = std::get<1>(identaties[i]);
        
        move(y - 1, x - 4);
        addwstr(myWhiteList[63 - i]->getUnicodeCharacter());
    }
}