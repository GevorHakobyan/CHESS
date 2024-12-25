#include "GameWindow.h"

MainWindow::MainWindow() {
    m_Board = new ChessBoard();
    m_window = std::make_unique<QWidget>();
    m_window->setLayout(new QVBoxLayout());
    m_window->layout()->addWidget(m_Board);
    m_window->setFixedSize(1600, 1600);
}

MainWindow::UserInput MainWindow::show(bool isSuccessful, PieceColor color) {
    if (isSuccessful) {
        m_Board->ChangeBoardContent();
        m_Board->update();
    }

    if (m_GameState == GameState::PawnEvent) {
        m_Board->ChangeBoardStateToPawn(color); //color of event pawn
        m_Board->update();
        callEvents();
        m_promotedCharacter = m_Board->getPromotedCharacter();
        m_Board->update();
    }

    if (m_GameState == GameState::EOG) {
        m_Board->ChangeBoardStateToEOG(color); //color of winner
        update();
        m_Board->update();
    }

    callEvents();  
    return m_Board->getIndexes();
}

MainWindow::~MainWindow() {
    delete m_Board;
    m_Board = nullptr;
}

void MainWindow::InteruptGame() {
    m_GameState = GameState::EOG; 
}

void MainWindow::PromoteEvent() {
    m_GameState = GameState::PawnEvent;
}

void MainWindow::DeactivateEvent() {
    m_GameState = GameState::Normal;
}

MainWindow::PieceCharacter MainWindow::getPromotedCharacter() const {
    return m_promotedCharacter;
}

void MainWindow::callEvents() {
    m_window->show();
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(220, 220, 220));  
    setPalette(palette);

    QEventLoop loop;
    connect(m_Board, &ChessBoard::userInputCaptured, &loop, &QEventLoop::quit); 
    loop.exec(); 
}
