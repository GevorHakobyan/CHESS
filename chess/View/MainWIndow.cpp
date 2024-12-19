#include "MainWindow.h"

MainWindow::MainWindow() {
    m_Board = new ChessBoard();
    m_window = std::make_unique<QWidget>();
    m_window->setLayout(new QVBoxLayout());
    m_window->layout()->addWidget(m_Board);
    m_window->setFixedSize(1200, 1200);
}

MainWindow::UserInput MainWindow::show(bool isSuccessful) {
    if (isSuccessful) {
        m_Board->ChnageBoardState();
        m_Board->update();
    }

    m_window->show();
    QPalette palette;
    palette.setColor(QPalette::Window, QColor(220, 220, 220));  
    setPalette(palette);

    QEventLoop loop;
    connect(m_Board, &ChessBoard::userInputCaptured, &loop, &QEventLoop::quit); 
    loop.exec(); 

    return m_Board->getIndexes();
}

MainWindow::~MainWindow() {
    delete m_Board;
    m_Board = nullptr;
}


