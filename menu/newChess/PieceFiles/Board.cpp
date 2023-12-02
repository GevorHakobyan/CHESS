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
    m_pieceList[0][0].reset(new Rook(color, mychar));
    m_pieceList[0][7].reset(new Rook(color, mychar));
   
    mychar = L"\u265E";
    m_pieceList[0][1].reset(new Knight(color, mychar));
    m_pieceList[0][6].reset(new Knight(color, mychar));
   
    mychar = L"\u265D";
    m_pieceList[0][2].reset(new Bishop(color, mychar));
    m_pieceList[0][5].reset(new Bishop(color, mychar));
    
    mychar = L"\u265B";
    m_pieceList[0][3].reset(new Queen(color, mychar));

    mychar = L"\u265A";
    m_pieceList[0][4].reset(new King(color, mychar));
    
    mychar = L"\u265F";
    for (int i{0}; i < 8; ++i) {
        m_pieceList[1][i].reset(new Pawn(color, mychar));
    }
}

void Board::setBlackPieces() {
    std::string color = "Black";
    size_t endIndex{m_pieceList.size() - 1};

    const wchar_t* mychar = L"\u2656";
    m_pieceList[endIndex][0].reset(new Rook(color, mychar));
    m_pieceList[endIndex][7].reset(new Rook(color, mychar));
   
    mychar = L"\u2658";
    m_pieceList[endIndex][1].reset(new Knight(color, mychar));
    m_pieceList[endIndex][6].reset(new Knight(color, mychar));
   
    mychar = L"\u2657";
    m_pieceList[endIndex][2].reset(new Bishop(color, mychar));
    m_pieceList[endIndex][5].reset(new Bishop(color, mychar));
    
    mychar = L"\u2655";
    m_pieceList[endIndex][3].reset(new Queen(color, mychar));

    mychar = L"\u2654";
    m_pieceList[endIndex][4].reset(new King(color, mychar));
    
    mychar = L"\u2659";
    for (int i{0}; i < 8; ++i) {
        m_pieceList[endIndex - 1][i].reset(new Pawn(color, mychar));
    }
}

const PieceList& Board::getPieceList() const {
    return m_pieceList;
}

