#include "PieceFactory.hpp"

PieceFactory::PieceFactory() {
    setWhitePieces();
    setBlackPieces();
}
void PieceFactory::setWhitePieces() {
    std::string color = "Black";
     const wchar_t* mychar = L"\u265C";
    m_whitePieces[0] = std::make_unique<Rook>(color, mychar);
    m_whitePieces[7] = std::make_unique<Rook>(color, mychar);
   
    mychar = L"\u265E";
    m_whitePieces[1] = std::make_unique<Knight>(color, mychar);
    m_whitePieces[6] = std::make_unique<Knight>(color, mychar);
   
    mychar = L"\u265D";
    m_whitePieces[2] = std::make_unique<Bishop>(color, mychar);
    m_whitePieces[5] = std::make_unique<Bishop>(color, mychar);
    
    mychar = L"\u265B";
    m_whitePieces[3] = std::make_unique<Queen>(color, mychar);

    mychar = L"\u265A";
    m_whitePieces[4] = std::make_unique<King>(color, mychar);
    
    mychar = L"\u265F";
    for (int i{0}; i < 8; ++i) {
        m_whitePieces[i + 8] = std::make_unique<Pawn>(color, mychar);
    }
}

void PieceFactory::setBlackPieces() {
    std::string color = "White";
    const wchar_t* mychar = L"\u2656";
    m_blackPieces[0] = std::make_unique<Rook>(color, mychar);
    m_blackPieces[7] = std::make_unique<Rook>(color, mychar);
   
    mychar = L"\u2658";
    m_blackPieces[1] = std::make_unique<Knight>(color, mychar);
    m_blackPieces[6] = std::make_unique<Knight>(color, mychar);
   
    mychar = L"\u2657";
    m_blackPieces[2] = std::make_unique<Bishop>(color, mychar);
    m_blackPieces[5] = std::make_unique<Bishop>(color, mychar);
    
    mychar = L"\u2655";
    m_blackPieces[3] = std::make_unique<Queen>(color, mychar);

    mychar = L"\u2654";
    m_blackPieces[4] = std::make_unique<King>(color, mychar);
    
    mychar = L"\u2659";
    for (int i{0}; i < 8; ++i) {
        m_blackPieces[i + 8] = std::make_unique<Pawn>(color, mychar);
    }
}

PieceList& PieceFactory::getBlackPieces() {
    return m_blackPieces;
}

PieceList& PieceFactory::getWhitePieces() {
    return m_whitePieces;
}