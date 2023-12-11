#include "Knight.hpp"
Knight::Knight(const std::string& color, const wchar_t* character, Location startLocation)
 : Piece(color, character, startLocation) 
 {
    setAvailableCoordinates();
 };

 void Knight::updateAvailableCoordinates() {
    setAvailableCoordinates();
 }
void Knight::setAvailableCoordinates() {
  setUpRight();
  setUpLeft();
  setDownRight();
  setDownLeft(); 
}

void Knight::setUpRight() {
    auto[y, x] = m_Current_Location;
    Location location1{y + 1, x + 2};
    Location location2{y + 2, x + 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
}

void Knight::setUpLeft() {
    auto[y, x] = m_Current_Location;
    Location location1{y + 1, x - 2};
    Location location2{y + 2, x - 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
}

void Knight::setDownLeft() {
    auto[y, x] = m_Current_Location;
    Location location1{y - 1, x - 2};
    Location location2{y - 2, x - 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
}
void Knight::setDownRight() {
    auto[y, x] = m_Current_Location;
    Location location1{y - 1, x + 2};
    Location location2{y - 2, x + 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
}

bool Knight::doesExist(Location searcheable_Location) {
    int maxBoard{7};
    int minBoard{0};
    const auto[y, x] = searcheable_Location;

    if (y <= 7 && y >= 0) {
        return (x <= 7 && x >=0) ? true : false;
    }
    return false;
}