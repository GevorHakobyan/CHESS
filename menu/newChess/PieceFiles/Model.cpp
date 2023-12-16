#include "Model.hpp"

Model* Model::m_Model = nullptr;

Model::Model()
: m_Board{Board::getInstance()}, m_pieceList{m_Board->getPieceList()}
{
    m_Board  = Board::getInstance();
    m_ExistanceHandler = new PieceExistanceHandler;
    m_AvailableHandler = new AvailableCoordinates_Handler;
    m_BarriersHandler = new Barriers_Handler;
    m_DesiredHandler = new DesiredSquare_Handler;
    m_ExistanceHandler->setNextHandler(m_AvailableHandler);
    m_AvailableHandler->setNextHandler(m_BarriersHandler);
    m_BarriersHandler->setNextHandler(m_DesiredHandler);
}

Model* Model::getInstance() {
    if (nullptr == m_Model) {
        m_Model = new Model;
    }

    return m_Model;
}

bool Model::Move(UserInput userInput) {

    auto[origin, destination] = userInput;
    if (isZero(origin, destination)) {
        mvprintw(25, 0, "%s", "ZERO");
        return false;
    }
    const auto[y, x] = (*m_pieceMap)[origin];
    destination = (*m_pieceMap)[destination];
     
    if ( m_ExistanceHandler->handleRequest(*m_pieceList[y][x], destination)) {  
        mvprintw(9, 0, "%d", destination.first);
        mvprintw(9, 3, "%d", destination.second);
        setMovedPiece_Character(origin);
        setMovedSquare_Character(origin);
        //updateBoardMatrix((*m_pieceMap)[origin], destination);
        return true;
   } 
   return false;
}

bool Model::isZero(const Location& origin, const Location& destination) {
   if(0 == origin.first || 0 == origin.second) {
    return true;
   };
   return  (0 == destination.first || 0 == destination.second) ? true : false;
}

void Model::updateMap(Location& location, Index& pieceIndex) {
    (*m_pieceMap)[location] = pieceIndex;
}

void Model::updateBoardMatrix(Index& previousIndex, Index& newIndex) {
     m_Board->updateMatrix(previousIndex, newIndex);
}

void Model::setMap(Map& pieceMap) {
    m_pieceMap = std::move(pieceMap);
}

const PieceList& Model::getPieceList() const {
    return m_pieceList;
}

const wchar_t* Model::getMovedPiece_Character() {
    const wchar_t* character = m_Piece;
    return character;
}

const wchar_t* Model::getSquare_Character() {
    const wchar_t* character = m_Square;
    return character;
}

bool Model::isEven(int index) {
    return (0 == index % 2) ? true : false;
}

// (true == black) (false == white)
 bool Model::getColor(const Location& origin) {
   const auto[i, j] = (*m_pieceMap)[origin];
   mvprintw(10, 17, "%d", i);
   mvprintw(10, 19, "%d", j);

   if(!(isEven(i) && isEven(j))) {
    mvprintw(15, 15, "%s", "in first");
    return true;
   }

   if((isEven(i) && !isEven(j))) {
    mvprintw(15, 15, "%s", "in second");
    return true;
   }
   return false;
}

void Model::setMovedPiece_Character(const Location& origin) {
    const auto[i, j] = (*m_pieceMap)[origin];
    m_Piece = const_cast<wchar_t*>((m_pieceList[i][j]->getUnicodeCharacter()));
}

void Model::setMovedSquare_Character(const Location& origin) {
    m_Square =  const_cast<wchar_t*>((getColor(origin)) ? (L"\u25A0") : (L"\u25A1"));
}