#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

#include "PiecesPrinter.hpp"
#include "Controller.hpp"

class MouseHandler {
    public:
    MouseHandler(); 
    static MouseHandler* getInstance();  
    void HandleClicks();

    private: 
    Location getSquare();
    void SearchSquare();
    void moveMouse(Location&);
    void SearchXcoordinate();
    void SearchYcoodinate();
    void setXcoordinates();
    void setYcoordinates();
    int Search(const int);
    void setActiveLocation(Location);
    bool isInMiddleOfSquares(int, int, const std::vector<int>&);
    bool isOutOfBoard();
    bool getOrigin(Location&, MEVENT&);
    bool getDestination(Location&, MEVENT&);
    bool findDemandedLocation(Location&, MEVENT&, int&);
    
    private:
    Controller* m_Controller{nullptr};
    Location m_activeLocation;
    Location m_specifedSquare;
    const SquareIdentity& m_identaties;
    std::vector<int> m_Xcoordinates;
    std::vector<int> m_Ycoordinates;
    static MouseHandler* m_mouseHandler;
    int a{0};
};
#endif //MOUSE_HANDLER
