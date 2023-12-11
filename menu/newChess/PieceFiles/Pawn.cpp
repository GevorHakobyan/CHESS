#include "Pawn.hpp"
#include <optional>

Pawn::Pawn(const std::string& color, const wchar_t* character, Location startLocation)
 : Piece(color, character, startLocation) 
 {
    setAvailableCoordinates();
 };

 PawnPosition Pawn::detectPosition() {
    const auto[y, x] = m_Current_Location;
    return y == 6 ? PawnPosition::Down : PawnPosition::Up;
 }

void Pawn::updateAvailableCoordinates() {
    auto[y, x] = getCurrentLocation();
    Location currentLocation{y, x};
    int BoardMatrixSize{7};

    AvailableCoordinates updatedCoordinates;  

    updatedCoordinates = y - 2 < BoardMatrixSize ? standardUpdate(currentLocation) : updateWithChecks(currentLocation).value();
    m_Avialble_Coordinates = std::move(updatedCoordinates);
}

void Pawn::setAvailableCoordinates() {
    int step{-1};
    step = (detectPosition() == PawnPosition::Up) ? 1 : -1;
    auto[y, x] = m_Current_Location;
    Location coordinate1{y + step, x};
    Location coordinate2{y + 2 * step, x};

    m_Avialble_Coordinates.push_back(coordinate1);
    m_Avialble_Coordinates.push_back(coordinate2);
}

AvailableCoordinates Pawn::standardUpdate(Location currentLocation) {
    auto[y, x] = currentLocation;
    int MaxStep{2};

    AvailableCoordinates newCoordinates{};
    Location newLocations;

    for (int i = 0; i < MaxStep; ++i) {
        ++y;
        newLocations.first = y;
        newLocations.second = x;
        newCoordinates.push_back(newLocations);
    }

   std::optional<AvailableCoordinates> enemies = updateWithChecks(currentLocation);
    AvailableCoordinates realEnemies = enemies.value();
    if (enemies.has_value()) {
        for (auto& enemy : realEnemies) {
            newCoordinates.push_back(enemy);
        }
    }
    return newCoordinates;
}

std::optional<AvailableCoordinates> Pawn::updateWithChecks(Location currentLocation) {
    int BoardMaxSize{7};
    if (currentLocation.first == BoardMaxSize) {
        return std::nullopt;
    }
    
    std::pair<bool, bool> enemies{false, false};
    AvailableCoordinates newCordinates;
   
    if (currentLocation.first == BoardMaxSize - 1) {
        Location newLocation;
        newLocation.first = ++currentLocation.first;
        newLocation.second = newLocation.second;    
    }

    Location leftNeighbor;
    leftNeighbor.first = ++currentLocation.first;
    leftNeighbor.second = --currentLocation.second; 
    Location rightNeighbor;
    rightNeighbor.first = ++currentLocation.first;
    rightNeighbor.second = ++currentLocation.second;

    detectEnemies(currentLocation, enemies, leftNeighbor, rightNeighbor);
    //LeftNeighbor
    if (enemies.first) {
        newCordinates.push_back(leftNeighbor);
    }

    //rightNeighbor
    if (enemies.second) {
        newCordinates.push_back(rightNeighbor);
    }
    return newCordinates;
}

void Pawn::detectEnemies(Location currentLocation, std::pair<bool, bool>& enemies, Location leftNeighbor, Location rightNeighbor) {
    Board* myBoard{Board::getInstance()}; //what will happen if I use smart pointer??
    const PieceList& myList{myBoard->getPieceList()};

    auto[y, x] = leftNeighbor;  
    if (this->m_color != myList[y][x]->getColor()) {
        enemies.first = true;
    }

    y = rightNeighbor.first;
    x = rightNeighbor.second;
    if (this->m_color != myList[y][x]->getColor()) {
        enemies.second = true;
    }
    
}





