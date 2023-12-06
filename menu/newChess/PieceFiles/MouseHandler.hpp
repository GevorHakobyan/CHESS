#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

#include "PiecesPrinter.hpp"
class MouseHandler {
    public:
    MouseHandler(); 
    static MouseHandler* getInstance();
    Location getSquare();
    private:
    void HandleClicks();
    void SearchSquare();
    void moveMouse(int&);
    void SearchXcoordinate();
    void SearchYcoodinate();
    void setXcoordinates();
    void setYcoordinates();
    int Search(const int);
    void setActiveLocation(Location);
    bool isInMiddleOfSquares(int, int, const std::vector<int>&);
    private:
    Location m_activeLocation;
    Location m_specifedSquare;
    const SquareIdentity& m_identaties;
    std::vector<int> m_Xcoordinates;
    std::vector<int> m_Ycoordinates;
    static MouseHandler* m_mouseHandler;
};
#endif
