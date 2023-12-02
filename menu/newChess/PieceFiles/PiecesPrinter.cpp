#include "PiecesPrinter.hpp"

void PiecesPrinter::print(const SquareIdentity& identities) {
    Board* myBoard{Board::getInstance()};
    const PieceList& myList{myBoard->getPieceList()};

    int index{0};
    std::pair<int, int> location;

    for (const auto& row : myList) {
        for (const auto& piece : row) {
            location.first = std::get<0>(identities[index]);
            location.second = std::get<1>(identities[index]);
            if (piece != nullptr) {
                printPiece(piece->getUnicodeCharacter(), location);
            }
            ++index;
        }
    }
}

void PiecesPrinter::printPiece(const wchar_t* piece, std::pair<int, int> location) {
    move (location.first - 1, location.second - 4); 
    addwstr(piece);
}