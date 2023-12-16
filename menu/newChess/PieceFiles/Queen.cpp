#include "Queen.hpp"
#include <ncurses.h>

Queen::Queen(const std::string& color, const wchar_t* character, Location startLocation) 
: Piece(color, character, startLocation) 
{
    setAvailableCoordinates();
};

void Queen::setAvailableCoordinates() {
  mvprintw(0, 100, "%s", "I ammmmmmmmmm");
    setRowCoordinates();
    setColumCoordinates();
    setRightUpCoordinates();
    setLeftUpCoordinates();
    setRightDownCoordinates();
    setLeftDownCoordinates();
}

void Queen::updateAvailableCoordinates() {
    return;
}

void Queen::setRowCoordinates() {
    auto[y, x] = m_Current_Location;
    Location tmpLocation{m_Current_Location};
    for (int i{0}; i < x; ++i) {
        tmpLocation.second =  i;
        m_Avialble_Coordinates.push_back(tmpLocation);
    }

    tmpLocation = m_Current_Location;
    for (int i{x + 1}; i < 8; ++i) {
        tmpLocation.second = i;
        m_Avialble_Coordinates.push_back(tmpLocation);
    }
}

void Queen::setColumCoordinates() {
     auto[y, x] = m_Current_Location;
     Location tmpLocation{m_Current_Location};

    for (int i{8}; i < y + 8; ++i) {
        tmpLocation.first = i - 8;
        m_Avialble_Coordinates.push_back(tmpLocation);
    }

    tmpLocation = m_Current_Location;
    for (int i{y + 9}; i < 16; ++i) {
        tmpLocation.first = i - 8;
        m_Avialble_Coordinates.push_back(tmpLocation);
    }
}

void Queen::setRightUpCoordinates() {
  Location tmpLocation = m_Current_Location;
  auto[y, x] = m_Current_Location;
  int startY{0};
  int endX{7};
  while(y > startY && x < endX) {
    --endX;
    ++startY;
    tmpLocation.first--;
    tmpLocation.second++;
    m_Avialble_Coordinates.push_back(tmpLocation);
  }

   
}

void Queen::setLeftUpCoordinates() {
  Location tmpLocation = m_Current_Location;
  auto[y, x] = m_Current_Location;
  int startX{0};
  int startY{0}; 
 
 while (x > startX && y > startY) {
    ++startX;
    ++startY;
    tmpLocation.first--;
    tmpLocation.second--;
    m_Avialble_Coordinates.push_back(tmpLocation);
  }
}

void Queen::setRightDownCoordinates() {
  Location tmpLocation = m_Current_Location;
  auto[y, x] = m_Current_Location;
  int endX{7};
  int endY{7};

   while (x < endX && y < endY) {
    --endX;
    --endY;
    tmpLocation.first++;
    tmpLocation.second++;
    m_Avialble_Coordinates.push_back(tmpLocation);
  }
}

void Queen::setLeftDownCoordinates (){
  Location tmpLocation = m_Current_Location;
  auto[y, x] = m_Current_Location;
  int startX{0};
  int endY{7};
 
  while (y < endY && x > startX) {
    ++startX;
    --endY;
    tmpLocation.first++;
    tmpLocation.second--;
    m_Avialble_Coordinates.push_back(tmpLocation);
  }
}
