#include "Controller.hpp"

Controller* Controller::m_Controller = nullptr;

Controller::Controller()
: m_Board{Board::getInstance()}, m_pieceMap{m_Board->getPieceMap()}, m_pieceList{m_Board->getPieceList()}
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

Controller* Controller::getInstance() {
    if (nullptr == m_Controller) {
        m_Controller = new Controller;
    }

    return m_Controller;
}

void Controller::Move(const Location& origin, Location& destination) {
  
    if (isZero(origin, destination)) {
        mvprintw(25, 0, "%s", "ZERO");
        return;
    }
    const auto[y, x] = m_pieceMap[origin];
    destination = m_pieceMap[destination];
    mvprintw(26, 0, "%d",y);
    mvprintw(26, 3, "%d",x);
    mvprintw(27, 0, "%d",destination.first);
    mvprintw(27, 3, "%d",destination.second);
     
    if ( m_ExistanceHandler->handleRequest(*m_pieceList[y][x], destination)) {  
        mvprintw(9, 0, "%d", destination.first);
        mvprintw(9, 3, "%d", destination.second);
        //updateBoardMatrix(m_pieceMap[origin], destination);
        //updateBoardView(m_pieceMap[origin], destination);
   } 
}

bool Controller::isZero(const Location& origin, const Location& destination) {
   if(0 == origin.first || 0 == origin.second) {
    return true;
   };
   return  (0 == destination.first || 0 == destination.second) ? true : false;
}

void Controller::updateMap(Location& location, Index& pieceIndex) {
    m_Board->setMap(location, pieceIndex);
}

void Controller::updateBoardMatrix(Index& previousIndex, Index& newIndex) {
    const auto[Yprev, Xprev] = previousIndex;
    const auto[Ynew, Xnew] = newIndex;
    
    if (nullptr != m_pieceList[Ynew][Xnew]) {
        m_pieceList[Ynew][Xnew].reset();
    } 
   
    m_pieceList[Ynew][Xnew] = std::move(m_pieceList[Yprev][Xprev]);
    m_pieceList[Yprev][Xprev].reset(); //has already been moved?? is this neceassary??
}

void Controller::updateBoardView(const Location& origin, const Location& second) {
    BoardView* m_boardView{BoardView::getInstance()};
    PiecesPrinter piecePrinter;
    piecePrinter.print(m_boardView->getSquaresIdentities());
    piecePrinter.printPiece(L"\u25A1", origin);
}
