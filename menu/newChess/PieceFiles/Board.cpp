#include "Board.hpp"
Board* Board::m_Board = nullptr;

Board* Board::getInstance() {
    if (m_Board == nullptr) {
        m_Board = new Board();
    }
    return m_Board;
}

Board::Board() {
    setWhitePieces();
    setBlackPieces();
}

void Board::setWhitePieces() {
    std::string color = "White";
    const wchar_t* mychar = L"\u265C";
    Location startLocation{0, 0};
    m_pieceList[0][0].reset(new Rook(color, mychar, startLocation));
    startLocation.second = 7;
    m_pieceList[0][7].reset(new Rook(color, mychar, startLocation));
   
    mychar = L"\u265E";
    startLocation.second = 1;
    m_pieceList[0][1].reset(new Knight(color, mychar,startLocation));
    startLocation.second = 6;
    m_pieceList[0][6].reset(new Knight(color, mychar, startLocation));
   
    mychar = L"\u265D";
    startLocation.second = 2;
    m_pieceList[0][2].reset(new Bishop(color, mychar, startLocation));
    startLocation.second = 5;
    m_pieceList[0][5].reset(new Bishop(color, mychar, startLocation));
    
    mychar = L"\u265B";
    startLocation.second = 3;
    m_pieceList[0][3].reset(new Queen(color, mychar, startLocation));

    mychar = L"\u265A";
    startLocation.second = 4;
    m_pieceList[0][4].reset(new King(color, mychar, startLocation));
    
    mychar = L"\u265F";
    startLocation.first = 1;
    for (int i{0}; i < 8; ++i) {
        startLocation.second = i;
        m_pieceList[1][i].reset(new Pawn(color, mychar, startLocation));
    }
}

void Board::setBlackPieces() {
    std::string color = "Black";
    size_t endIndex{m_pieceList.size() - 1};
    Location startLocation{63, 0};

    const wchar_t* mychar = L"\u2656";
    m_pieceList[endIndex][0].reset(new Rook(color, mychar, startLocation));
    startLocation.second = 7;
    m_pieceList[endIndex][7].reset(new Rook(color, mychar, startLocation));
   
    mychar = L"\u2658";
    startLocation.second = 1;
    m_pieceList[endIndex][1].reset(new Knight(color, mychar, startLocation));
    startLocation.second = 6;
    m_pieceList[endIndex][6].reset(new Knight(color, mychar, startLocation));
   
    mychar = L"\u2657";
    startLocation.second = 2;
    m_pieceList[endIndex][2].reset(new Bishop(color, mychar, startLocation));
    startLocation.second = 5;
    m_pieceList[endIndex][5].reset(new Bishop(color, mychar, startLocation));
    
    mychar = L"\u2655";
    startLocation.second = 3;
    m_pieceList[endIndex][3].reset(new Queen(color, mychar, startLocation));

    mychar = L"\u2654";
    startLocation.second = 4;
    m_pieceList[endIndex][4].reset(new King(color, mychar, startLocation));
    
    mychar = L"\u2659";
    startLocation.first = 62;
    for (int i{0}; i < 8; ++i) {
        startLocation.second = i;
        m_pieceList[endIndex - 1][i].reset(new Pawn(color, mychar, startLocation));
    }
}

const PieceList& Board::getPieceList() const {
    return m_pieceList;
}

void Board::setMap(Location& pieceLocation, Index& pieceIndexes) {
    m_PieceMap[pieceLocation] = pieceIndexes;
}

void Board::move() {
    
}

std::pair<bool, Color> Board::isEmpty(Location specifiedLocation) {
    const auto[i, j] = m_PieceMap[specifiedLocation];
    if(m_pieceList[i][j]->getUnicodeCharacter() == nullptr) {
        return {true, Color::Unknown};
    }
    Color pieceColor = m_pieceList[i][j]->getColor();
    return {false, pieceColor};
}