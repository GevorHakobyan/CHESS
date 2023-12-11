#include "MouseHandler.hpp"
#include <math.h>

MouseHandler* MouseHandler::m_mouseHandler = nullptr;

MouseHandler* MouseHandler::getInstance() {
    if (nullptr == m_mouseHandler) {
        m_mouseHandler = new MouseHandler{};
    }
    return m_mouseHandler;
}
MouseHandler::MouseHandler() 
: m_activeLocation{std::make_pair<int, int>(0, 0)}, 
  m_specifedSquare{std::make_pair<int, int>(0 , 0)},
  m_identaties{BoardView::getInstance()->getSquaresIdentities()} 
  {
    setXcoordinates();
    setYcoordinates();
  };

void MouseHandler::setActiveLocation(Location active) {
    m_activeLocation = active;
}

void MouseHandler::HandleClicks () {
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    Board* mainBoard{Board::getInstance()};
    int firstinput;
    int secondInput;
    Location origin;
    Location destination;
    const PieceList& PieceList = mainBoard->getPieceList();



     while (true) {
        getOrigin(firstinput, origin);
        getDestination(secondInput, destination);
       /* move(5, 0);
        printw("%d", origin.first);
        move(5, 3);
        printw("%d", destination.first);*/
        mainBoard->movePiece(origin, destination);
        if (firstinput == 'q' || secondInput == 'q') {
            break;
        }
    }  
}

void MouseHandler::moveMouse(int& input, Location& esim) {
    MEVENT event;
    input = getch();
    Location clicked{0, 0};
    if (input == KEY_MOUSE) {
        if (getmouse(&event) == OK) {
            if (event.bstate & BUTTON1_CLICKED) {
                    clicked.first = event.y;
                    clicked.second = event.x;
                    setActiveLocation(clicked);
                    SearchSquare();
                    esim = m_specifedSquare;
            }
        } 
        refresh();
    }      
}

Location MouseHandler::getSquare() {
    SearchSquare();
    return m_specifedSquare;
}

void MouseHandler::SearchSquare() {
    SearchYcoodinate();
    SearchXcoordinate();
}

void MouseHandler::SearchXcoordinate() {
    int x{m_activeLocation.second}; 
    m_specifedSquare.second = Search(x);
}

void MouseHandler::SearchYcoodinate() {   
    int y{m_activeLocation.first};
    m_specifedSquare.first = Search(y);
}

void MouseHandler::setXcoordinates() {
    for (int i{0}; i < 8; ++i) {
        m_Xcoordinates.push_back(std::get<1>(m_identaties[i]));
    }
}

void MouseHandler::setYcoordinates() {
    for (int i{0}; i < 64; i += 8) {
        m_Ycoordinates.push_back(std::get<0>(m_identaties[i]));
    }
}

int MouseHandler::Search(const int point) {
    int interval{7};
    int index{0};
    int difference{0};
    std::vector<int>& coordinates = point >= 65 ? m_Xcoordinates : m_Ycoordinates;

    for (int i{0}; i < coordinates.size(); ++i) { 
        difference = (coordinates[i] - point);
        if ( difference >= 0 &&  difference <= interval) {
            interval = difference;
            index = i;
            if (isInMiddleOfSquares(i, point, coordinates)) {
                return 0;
            }
        }
    }
    return coordinates[index];
}

bool MouseHandler::isInMiddleOfSquares(int i, int point, const std::vector<int>& coordinates) {
    if (0 == i) {
        return false;
    }
    int step;
    step = coordinates[0] < 70 ? 2 : 5;

    if (point < coordinates[i] - step && point > coordinates[i - 1]) {
        return true;
    }
    return false;
}

void MouseHandler::getOrigin(int& input, Location& origin) {
    moveMouse(input, origin);
}

void MouseHandler::getDestination(int& input, Location& destination) {
    moveMouse(input, destination);
}
