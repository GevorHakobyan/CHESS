#include "King.hpp"

King::King(const std::string& color, const wchar_t* character, Location currentLocation) 
: Piece(color, character, currentLocation) 
{
    setAvailableCoordinates();
};

void King::updateAvailableCoordinates() {
    m_Avialble_Coordinates.clear();
    setAvailableCoordinates();
}

void King::setAvailableCoordinates() {
    setUpCoordinates();
    setDownCoordinates();
    setOnSameLine();
}

bool King::doesExist(Location searcheable_Location ){
    int maxBoard{7};
    int minBoard{0};
    const auto[y, x] = searcheable_Location;

    if (y <= 7 && y >= 0) {
        return (x <= 7 && x >=0) ? true : false;
    }
    return false;
}

void King::setUpCoordinates() {
    auto[y, x] = m_Current_Location;
    Location location1{y - 1, x - 1};
    Location location2{y - 1, x};
    Location location3{y - 1, x + 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
    if (doesExist(location3)) {
        m_Avialble_Coordinates.push_back(location3);
    }
}

void King::setDownCoordinates() {
 auto[y, x] = m_Current_Location;
    Location location1{y + 1, x - 1};
    Location location2{y + 1, x};
    Location location3{y + 1, x + 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
    if (doesExist(location3)) {
        m_Avialble_Coordinates.push_back(location3);
    }
}

void King::setOnSameLine() {
     auto[y, x] = m_Current_Location;
    Location location1{y, x - 1};
    Location location2{y, x + 1};

    if (doesExist(location1)) {
        m_Avialble_Coordinates.push_back(location1);
    }

    if (doesExist(location2)) {
        m_Avialble_Coordinates.push_back(location2);
    }
}