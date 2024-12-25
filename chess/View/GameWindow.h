#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QEventLoop>
#include "QCoreApplication"
#include "ViewBoard.h"  

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
    using Window = std::unique_ptr<QWidget>;
    using Board = ChessBoard*;
    using UserInput = ChessBoard::UserInput;
    using PieceCharacter = std::wstring;
    using PieceColor = ChessBoard::PieceColor;
    using GameState = ChessBoard::States;
    public:
    explicit MainWindow();
    ~MainWindow();
    UserInput show(bool, PieceColor = PieceColor::Undefined);
    void InteruptGame();
    void PromoteEvent();
    void DeactivateEvent();
    PieceCharacter getPromotedCharacter() const;
    private:
    void callEvents();

    private:
    GameState m_GameState{GameState::Normal};
    Window m_window{nullptr};
    Board m_Board{nullptr};
    PieceCharacter m_promotedCharacter;
};

#endif // MAINWINDOW_H

