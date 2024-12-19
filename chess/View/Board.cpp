#include "Board.h"

ChessBoard::ChessBoard() {
    setMap();
}

void ChessBoard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    printSquares(painter);
    printCharacters(painter);
}

void ChessBoard::mousePressEvent(QMouseEvent* event) {
    m_Que = !m_Que;
    int x = event->x();
    int y = event->y();

    size_t row = (x / m_squareSize) - 1;
    size_t col = y / m_squareSize;

    if (m_Que) {
        m_PieceIndexes.first = {row, col};
        x = (row + 1)  * m_squareSize + 30;
        y = col  * m_squareSize  + 80;
        m_userInput.first = {x, y};
        return;
    }

    m_PieceIndexes.second = {row, col};
    x = (row + 1) * m_squareSize + 30;
    y = col * m_squareSize + 80;
    m_userInput.second = {x, y};
    emit userInputCaptured();
}

void ChessBoard::setSquareColor(QPainter& painter, size_t row, size_t col) const {
    if ((row + col) % 2 == 0) {
        painter.setBrush(Qt::green);
        return;
    }
    painter.setBrush(Qt::blue);
}

void ChessBoard::printRow(QPainter& painter, size_t col) {
    for (size_t row = 0; row < 8; ++row) {
        setSquareColor(painter, row, col);
        int x = col * m_squareSize + 120;
        int y = row * m_squareSize; 
        painter.drawRect(x, y, m_squareSize, m_squareSize);
    }
}

void ChessBoard::printSquares(QPainter& painter) {
    for (size_t col = 0; col < 8; ++col) {
       printRow(painter, col);
    } 
}

void ChessBoard::printCharacters(QPainter& painter) {
    QFont font("Alpha", 48, QFont::Bold);  
    painter.setFont(font);
    painter.setPen(Qt::black);  

    for (const auto character : m_BoardState) {
        const auto[x, y] = character.first;
        QString piece = QString::fromStdWString(character.second);
        painter.drawText(x, y, piece);
    }
}

ChessBoard::PieceIndexes ChessBoard::getIndexes() const {
    return m_PieceIndexes;
}

void ChessBoard::ChnageBoardState() {
    auto targetIter = m_BoardState.find(m_userInput.second);
    if (targetIter != m_BoardState.end()) {
        m_BoardState.erase((*targetIter).first);
    }

    auto [location, character] = *m_BoardState.find(m_userInput.first);
    m_BoardState.erase(location);
    qDebug() << m_userInput.second << "\n";
    m_BoardState.insert({m_userInput.second, character});
}

void ChessBoard::setMap() {
    size_t y = m_squareSize + m_squareSize / 2 + 20;

    for (int i = 0; i < 8; ++i) {
        size_t x = i * m_squareSize + 150;
        PieceCharacter pawn =  L"\u2659";
        m_BoardState.insert({{x, y}, pawn});
    }
    size_t i{0};
    y = m_squareSize / 2 + 20;
    size_t x = i * m_squareSize + 150;

    PieceCharacter rook = L"\u2656";
    m_BoardState.insert({{x, y}, rook});
    x = ++i * m_squareSize + 150;
    
    PieceCharacter horse = L"\u2658";
    m_BoardState.insert({{x, y}, horse});
    x = ++i * m_squareSize + 150;

    PieceCharacter bishop = L"\u2657";
    m_BoardState.insert({{x, y}, bishop});
    x = ++i * m_squareSize + 150;
  
    PieceCharacter queen = L"\u2655";
    m_BoardState.insert({{x, y}, queen});
    x = ++i * m_squareSize + 150;

    PieceCharacter king = L"\u2654";
    m_BoardState.insert({{x, y}, king});
    x = ++i * m_squareSize + 150;

    bishop = L"\u2657";
    m_BoardState.insert({{x, y}, bishop});
    x = ++i * m_squareSize + 150;

    horse = L"\u2658";
    m_BoardState.insert({{x, y}, horse});
    x = ++i * m_squareSize + 150;

    rook = L"\u2656";
    m_BoardState.insert({{x, y}, rook});
    x = ++i * m_squareSize + 150;
    
    y = 6 * m_squareSize + m_squareSize / 2 + 20;
    for (int i = 0; i < 8; ++i) {
        int x = i * m_squareSize + 150;
        PieceCharacter pawn =  L"\u265F";
        m_BoardState.insert({{x, y}, pawn});
    }
    
    i = 0;
    x = i++ * m_squareSize + 150;
    y = 7 * m_squareSize + m_squareSize / 2 + 20;

    rook = L"\u265C";
    m_BoardState.insert({{x, y},rook});
    x = i++ * m_squareSize + 150;

    horse = L"\u265E";
    m_BoardState.insert({{x, y}, horse});
    x = i++ * m_squareSize + 150;

    bishop = L"\u265D";
    m_BoardState.insert({{x, y}, bishop});
    x = i++ * m_squareSize + 150;

    queen = L"\u265B";
    m_BoardState.insert({{x, y}, queen});
    x = i++ * m_squareSize + 150;
  
    king = L"\u265A";
    m_BoardState.insert({{x, y}, king});
    x = i++ * m_squareSize + 150;
 
    bishop = L"\u265D";
    m_BoardState.insert({{x, y}, bishop});
    x = i++ * m_squareSize + 150;
 
    horse = L"\u265E";
    m_BoardState.insert({{x, y}, horse});
    x = i++ * m_squareSize + 150;

    rook = L"\u265C";
    m_BoardState.insert({{x, y}, rook});
    x = i++ * m_squareSize + 150;
}


