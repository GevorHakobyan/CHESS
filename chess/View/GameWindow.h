#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QEventLoop>
#include "ViewBoard.h"  

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
    using Window = std::unique_ptr<QWidget>;
    using Board = ChessBoard*;
    using UserInput = ChessBoard::UserInput;
    using PieceCharacter = std::wstring;
    using PawnColor = ChessBoard::PawnColor;
    public:
    explicit MainWindow();
    ~MainWindow();
    UserInput show(bool, PawnColor = PawnColor::Undefined);
    PieceCharacter getPromotedCharacter() const;
    private:
    void callEvents();

    private:
    Window m_window{nullptr};
    Board m_Board{nullptr};
    PieceCharacter m_promotedCharacter;
};

#endif // MAINWINDOW_H

