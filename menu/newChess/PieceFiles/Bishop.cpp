#include "Bishop.hpp"
#include <ncurses.h>

Bishop::Bishop(const std::string& color, const wchar_t* character, Location startLocation) 
: Piece(color, character, startLocation) 
{
  setAvailableCoordinates();
};

void Bishop::updateAvailableCoordinates() {    
  setAvailableCoordinates();
}

void Bishop::setAvailableCoordinates() {
  setRightUpCoordinates();
  setLeftUpCoordinates();
  setRightDownCoordinates();
  setLeftDownCoordinates();
}

void Bishop::setRightUpCoordinates() {
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

void Bishop::setLeftUpCoordinates() {
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

void Bishop::setRightDownCoordinates() {
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

void Bishop::setLeftDownCoordinates (){
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