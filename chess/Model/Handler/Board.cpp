#include "Board.hpp"
Board* Board::m_Board = nullptr;

Board* Board::getInstance() {
    if (m_Board == nullptr) {
        m_Board = new Board;
    }
    return m_Board;
}

Board::Board() {
    setWhitePieces();
    setBlackPieces();
}

Board::~Board() {};

void Board::setWhitePieces() {
    std::string color = "White";
    const wchar_t* mychar = L"\u265C";
    Location startLocation{0, 0};
    m_pieceList[0][0].reset(new Rook(color, mychar, startLocation));
    startLocation.second = 7;
    m_pieceList[7][0].reset(new Rook(color, mychar, startLocation));
   
    mychar = L"\u265E";
    startLocation.second = 1;
    m_pieceList[1][0].reset(new Knight(color, mychar,startLocation));
    startLocation.second = 6;
    m_pieceList[6][0].reset(new Knight(color, mychar, startLocation));
   
    mychar = L"\u265D";
    startLocation.second = 2;
    m_pieceList[2][0].reset(new Bishop(color, mychar, startLocation));
    startLocation.second = 5;
    m_pieceList[5][0].reset(new Bishop(color, mychar,startLocation));
    
    mychar = L"\u265B";
    startLocation.second = 3;
    m_pieceList[3][0].reset(new Queen(color, mychar, startLocation));

    mychar = L"\u265A";
    startLocation.second = 4;
    m_pieceList[4][0].reset(new King(color, mychar, startLocation));
    
    mychar = L"\u265F";
    startLocation.first = 1;
    for (int i{0}; i < 8; ++i) {
        startLocation.second = i;
        m_pieceList[i][1].reset(new Pawn(color, mychar, startLocation));
    }
}

void Board::setBlackPieces() {
    std::string color = "Black";
    size_t endIndex{m_pieceList.size() - 1};
    Location startLocation{7, 0};

    const wchar_t* mychar = L"\u2656";
    m_pieceList[0][endIndex].reset(new Rook(color, mychar, startLocation));
    startLocation.second = 7;
    m_pieceList[7][endIndex].reset(new Rook(color, mychar, startLocation));
   
    mychar = L"\u2658";
    startLocation.second = 1;
    m_pieceList[1][endIndex].reset(new Knight(color, mychar, startLocation));
    startLocation.second = 6;
    m_pieceList[6][endIndex].reset(new Knight(color, mychar, startLocation));
   
    mychar = L"\u2657";
    startLocation.second = 2;
    m_pieceList[2][endIndex].reset(new Bishop(color, mychar, startLocation));
    startLocation.second = 5;
    m_pieceList[5][endIndex].reset(new Bishop(color, mychar, startLocation));
    
    mychar = L"\u2655";
    startLocation.second = 3;
    m_pieceList[3][endIndex].reset(new Queen(color, mychar, startLocation));

    mychar = L"\u2654";
    startLocation.second = 4;
    m_pieceList[4][endIndex].reset(new King(color, mychar, startLocation));
    
    mychar = L"\u2659";
    startLocation.first = 6;
    for (int i{0}; i < 8; ++i) {
        startLocation.second = i;
        m_pieceList[i][endIndex - 1].reset(new Pawn(color, mychar, startLocation));
    }
}

std::pair<bool, Color> Board::isEmpty(Index specifiedLocation) {
    const auto[i, j] = specifiedLocation;
    if(m_pieceList[i][j] == nullptr) {
        return {true, Color::Unknown};
    }
    Color pieceColor = m_pieceList[i][j]->getColor();
    return {false, pieceColor};
}

const PieceList& Board::getPieceList() const {
    return m_pieceList;
}

void Board::updateMatrix(Index& previousIndex, Index& newIndex) {
    const auto[Xprev, Yprev] = previousIndex;
    const auto[Xnew, Ynew] = newIndex;

    if (nullptr != m_pieceList[Xnew][Ynew]) {
        m_pieceList[Xnew][Ynew].reset();
    } 
    m_pieceList[Xnew][Ynew] = std::move(m_pieceList[Yprev][Xprev]);
    m_pieceList[Xprev][Yprev].reset(); //has already been moved?? is it even neceassary??
}

void Board::updatePieceData(Location& newLocation) {
    const auto[x, y] = newLocation;
    m_pieceList[x][y].get()->setCurrentLocation(newLocation);
    m_pieceList[x][y].get()->updateAvailableCoordinates();
}

void Board::swapPawnWith(const Index& pawnIndex, std::pair<const wchar_t*, Color>& character, const Index& newLocation) {
    const auto[x, y] = pawnIndex;
    const auto[X, Y] = newLocation;
    character.second = m_pieceList[x][y]->getColor();
    PieceTypes pieceType = determineCharacter(character);

    if (pieceType == PieceTypes::Rook) {
        const wchar_t* mychar = (character.second == Color::Black) ? L"\u2656" : L"\u265C";
        std::string color = (character.second == Color::Black) ? "Black" : "White";
        m_pieceList[x][y].reset();
        m_pieceList[X][Y].reset();
        std::unique_ptr<Rook> m_Rook(new Rook(color, mychar, newLocation)); 
        m_pieceList[X][Y] = std::move(m_Rook);
        return;
    }

    if (pieceType == PieceTypes::Queen) {
        const wchar_t* mychar = (character.second == Color::Black) ? L"\u2655" : L"\u265B";
        std::string color = (character.second == Color::Black) ? "Black" : "White";
        m_pieceList[x][y].reset();
        m_pieceList[X][Y].reset();
        std::unique_ptr<Queen> m_Queen(new Queen(color, mychar, newLocation)); 
        m_pieceList[X][Y] = std::move(m_Queen);
        return;
    }

    if (pieceType == PieceTypes::Knight) {
        const wchar_t* mychar = (character.second == Color::Black) ? L"\u2658" : L"\u265E";
        std::string color = (character.second == Color::Black) ? "Black" : "White";
        m_pieceList[x][y].reset();
        m_pieceList[X][Y].reset();
        std::unique_ptr<Knight> m_Knight(new Knight(color, mychar, newLocation)); 
        m_pieceList[X][Y] = std::move(m_Knight);
        return;
    }
   
}

PieceTypes Board::determineCharacter(std::pair<const wchar_t*, Color> character){
    const wchar_t* BlackRook{L"\u2656"};
    const wchar_t* BlackQueen{L"\u2655"};
    const wchar_t* BlackKnight{L"\u2658"};
    
    const wchar_t* WhiteRook{L"\u265C"};
    const wchar_t* WhiteQueen{L"\u265B"};
    const wchar_t* WhiteKnight{L"\u265E"};

    if (*character.first == *BlackRook || *character.first == *WhiteRook) {
        return PieceTypes::Rook;
    } 

     if (*character.first == *BlackKnight || *character.first == *WhiteKnight) {
        return PieceTypes::Knight;
    }
    
    if (*character.first == *BlackQueen || *character.first == *WhiteQueen) {
        return PieceTypes::Queen;
    }
}
