#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QEventLoop>
#include "Board.h"  

class MainWindow : public QMainWindow {
    Q_OBJECT
    using Window = std::unique_ptr<QWidget>;
    using Board = ChessBoard*;
    using UserInput = ChessBoard::UserInput;
    using PieceCharacter = std::wstring;
    public:
    explicit MainWindow();
    ~MainWindow();
    UserInput show(bool);

    private:
    UserInput printCharacter(PieceCharacter, bool);
    Window m_window{nullptr};
    Board m_Board{nullptr};
};

#endif // MAINWINDOW_H

