#include "MouseHandler.hpp"


MouseHandler* MouseHandler::m_mouseHandler = nullptr;
void fakeDelay();

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
    m_Controller = Controller::getInstance();
  };

void MouseHandler::setActiveLocation(Location active) {
    m_activeLocation = active;
}

void MouseHandler::HandleClicks () {
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    Location origin;
    Location destination;
    MEVENT event;

    if (!getOrigin(origin, event)) {
        return;
    }
    refresh();
    if (!getDestination(destination, event)) {
        return;
    }
    refresh();
    //fakeDelay();
     
    m_Controller->Move(origin, destination);
}

void MouseHandler::moveMouse(Location& clicked) {
    setActiveLocation(clicked);
    if (isOutOfBoard()) {
        clicked.first = 0;
        clicked.second = 0;
        return;
    }
    SearchSquare();
    clicked = m_specifedSquare;
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
bool MouseHandler::isOutOfBoard() {
    const auto[y, x] = m_activeLocation;
    int maxX{121};
    int minX{65};
    int maxY{42};
    int minY{12};

    if (x > maxX ||  x < minX) {
        return true;
    }

    if (y > maxY || y < minY) {
        return true;
    }
    
    return false;
}
bool MouseHandler::getOrigin(Location& origin, MEVENT& event) {
    fakeDelay();
    int input1 = getch();
    return findDemandedLocation(origin, event, input1) ? true : false;
}

bool MouseHandler::getDestination(Location& destination, MEVENT& event) {
    fakeDelay(); //one click two input
    int input2 = getch();
    return findDemandedLocation(destination, event, input2) ? true : false;
}

bool MouseHandler::findDemandedLocation(Location& demandedLocation, MEVENT& event, int& input) {
     if (input == KEY_MOUSE && getmouse(&event) == OK) {
        demandedLocation.first = event.y;
        demandedLocation.second = event.x;
        mvprintw(0, 0, "%d", demandedLocation.first);
        mvprintw(1, 0, "%d", demandedLocation.second);
        moveMouse(demandedLocation);
    }
    ++a;
    mvprintw(5, 0, "%d", a);
    if (input == 'q') {
        return false;
    }
    return true;
}

void fakeDelay() {
    int input = getch();
    return;
}