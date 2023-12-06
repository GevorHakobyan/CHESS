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
    int input;
     while (true) {
        moveMouse(input);
        if (input == 'q') {
            break;
        }
    }  
}

void MouseHandler::moveMouse(int& input) {
    MEVENT event;
    input = getch();
    if (input == KEY_MOUSE) {
        if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                Location clicked{event.y, event.x};
                setActiveLocation(clicked);
                SearchSquare();
                move(m_specifedSquare.first, m_specifedSquare.second);
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
    std::vector<int>& coordinates = point >= 70 ? m_Xcoordinates : m_Ycoordinates;

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
