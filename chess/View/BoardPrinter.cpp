#include "BoardPrinter.hpp"
void printRowNumber(int);

BoardPrinter::BoardPrinter(BoardView* myBoard) {
    m_board = myBoard;
    m_boardSize = myBoard->getBoard().size();
    m_PieceMap = std::make_unique<std::map<Location, Index>>();
}

void BoardPrinter::Print(PiecesPrinter& piecePrinter) {
    printMatrix();
    printColumLetter();
    piecePrinter.print(m_board->getSquaresIdentities());
}

void BoardPrinter::printMatrix() {
    BoardMatrix matrix = m_board->getBoard();
    for (int i = 0; i < matrix.size(); ++i) {
        printRow(matrix[i], i + 3);
        addwstr(L"\n");
    }
}

void BoardPrinter::printRow(Row& row, int lineNumber) {
    int rowNum{lineNumber * 4};
    printRowNumber(rowNum);
    for (int i = 0; i < 3; ++i) {
        move(rowNum, 65);
        ++rowNum;
        printBoardLine(row, i); 
        setCursorLocation();    
        addwstr(L"\n");
    }   
    
}

void BoardPrinter::printBoardLine(Row& row, int i) {
    for (int j = 0; j < row.size(); ++j) {
            printSquareLine(row[j][i], i);
    }
}

void BoardPrinter::printSquareLine(std::array<const wchar_t*, 3>& line, int lineNumber) {
    for (auto square : line) {
        addwstr(square);
        addwstr(L" ");
    }

    int lastLine{2};
    if (lineNumber == lastLine) {
        setCursorLocation();
        setSquareLocations();
    }

    addwstr(L" ");
}

void BoardPrinter::printColumLetter() {
    Letters letter{m_board->getLetters()};
    auto [y,x] = m_cursor;
    move(y + 1, 68);
    for (auto elem : letter) {
        addch(elem);
        setCursorLocation();
        x = m_cursor.second;
        move(y + 1, x + 6);
    }
}

void BoardPrinter::printRowNumber(int rowNum) {
    int lineNumber{rowNum / 4};
    move(rowNum + 1, 63); 
    printw("%d", lineNumber - 2);
    move(rowNum, 65);
}

void BoardPrinter::setCursorLocation() {
    getyx(stdscr, m_cursor.first, m_cursor.second);
}

CursorPositon BoardPrinter::getCursorLocation() {
    return m_cursor;
}

void BoardPrinter::setSquareLocations() {
    std::tuple<int, int, int> squareIdentity = std::make_tuple(m_cursor.first, m_cursor.second - 1, m_activeSquare);
    ++m_activeSquare;
    m_board->setSquareIdentity(squareIdentity);
}