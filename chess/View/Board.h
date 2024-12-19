#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <map>
#include <memory>

class ChessBoard : public QWidget {
    Q_OBJECT
    public:
    using Location = std::pair<size_t, size_t>;
    using Index = std::pair<size_t, size_t>;
    using PieceIndexes = std::pair<Index, Index>;
    using UserInput = std::pair<Location, Location>;
    using PieceCharacter = std::wstring;
    using Map = std::map<Location, PieceCharacter>;
    public:
    explicit ChessBoard();
    ~ChessBoard() override = default;
    PieceIndexes getIndexes() const;
    void ChnageBoardState();
    signals:
    void userInputCaptured();
    
    private:
    void setSquareColor(QPainter&, size_t, size_t) const;
    void printRow(QPainter&, size_t);
    void printSquares(QPainter&) ;
    void printCharacters(QPainter&);
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void setMap();
    private:
    Map m_BoardState{};
    bool m_Que{false};
    PieceIndexes m_PieceIndexes;
    UserInput m_userInput;
    int m_squareSize{120};
};

#endif // BOARD_H
