#include "Model.hpp"

Model* Model::m_Model = nullptr;

Model::Model()
: m_Board{Board::getInstance()}, m_pieceList{m_Board->getPieceList()}
{
    m_Board  = Board::getInstance();
    m_ExistanceHandler = std::make_shared<PieceExistanceHandler>(PieceExistanceHandler());
    m_QueHandler = std::make_shared<QueHandler>(QueHandler());
    m_AvailableHandler = std::make_shared<AvailableCoordinates_Handler>(AvailableCoordinates_Handler());
    m_BarriersHandler = std::make_shared<Barriers_Handler>(Barriers_Handler());
    m_DesiredHandler = std::make_shared<DesiredSquare_Handler>(DesiredSquare_Handler());
    
    m_ExistanceHandler->setNextHandler(m_AvailableHandler);
    m_AvailableHandler->setNextHandler(m_BarriersHandler);
    m_BarriersHandler->setNextHandler(m_DesiredHandler);
    m_DesiredHandler->setNextHandler(m_QueHandler);
}

Model* Model::getInstance() {
    if (nullptr == m_Model) {
        m_Model = new Model;
    }

    return m_Model;
}

bool Model::Move(UserInput userInput) {
    auto[origin, destination] = userInput;
    if (areSquaresValid(origin, destination)) {
        return false;
    }

    const auto[y, x] = origin;
    if (isOriginNullable(origin)) {
        return false;
    }

    Color pieceColor = m_pieceList[y][x].get()->getColor(); 
     
    if (isStepValid(userInput)) {
        takeStep(origin, destination);

        const auto[Ynew, Xnew] = destination;
        if (Broker::isMyKingUnderCheck((*m_pieceList[Ynew][Xnew]))) { 
            UndoStep(userInput);
            return false;
        } 

        if (Broker::isEnemyKingUnderCheck((*m_pieceList[Ynew][Xnew]))) { 
            if (Broker::isKingKilled(*m_pieceList[Ynew][Xnew])) {
            }
        }
        return true;
    }

    if(Broker::isPawnEventTime(*m_pieceList[y][x], destination)) {
        ActivateEventState();
        setEventInfo(m_pieceList[y][x]->getColor(), userInput.second);
    }
    return false; 
}

bool Model::areSquaresValid(const Location& origin, const Location& destination) {
   if(0 == origin.first || 0 == origin.second) {
    return true;
   };
   return  (0 == destination.first || 0 == destination.second) ? true : false;
}

bool Model::isOriginNullable(const Location& origin) const {
    const auto[y, x] = origin;
    if (!m_pieceList[y][x].get()) {
        return true;
    }
    return false;
}

void Model::updateBoardMatrix(Index& previousIndex, Index& newIndex) {
     m_Board->updateMatrix(previousIndex, newIndex);
}

void Model::UndoBoardUpdate(Index& previousIndex, Index& newIndex) {
    m_Board->updateMatrix(newIndex, previousIndex);
}

void Model::UpdatePiece_Data(Location& previousLocation) {
    m_Board->updatePieceData(previousLocation);
}

void Model::UndoPieceData_Update(Location& previousLocation) {
    m_Board->updatePieceData(previousLocation);
}

const PieceList& Model::getPieceList() const {
    return m_pieceList;
}

bool Model::isEven(int index) {
    return (0 == index % 2) ? true : false;
}

bool Model::isOdd(int index) {
    return (0 != index % 2) ? true : false;
}

// (true == black) (false == white)
 bool Model::getSquareColor(const Location& origin) {
   const auto[i, j] = origin;

   if((isEven(i) && isEven(j))) {
    return false;
   }

   if((isOdd(i) && isOdd(j))) {
    return false;
   }
   return true;
}


Color Model::getPieceColor(const Index& myPieceIndex) {
    const auto[i , j] = myPieceIndex;

    if (m_pieceList[i][j] == nullptr) {
        return Color::Unknown;
    }

    return m_pieceList[i][j].get()->getColor();
}

void Model::setEventInfo(const Color& pawnColor, const Location& destination) {
    m_PieceOptions = Broker::getPieceOptions(pawnColor);
    m_PieceLocations = Broker::getPieceLocations(destination);
}

const PieceOptions& Model::getPieceOptions() const {
    return m_PieceOptions;
}

const PieceLocations& Model::getPieceLocations() const {
    return m_PieceLocations;
}

void Model::ActivateEventState() {
    m_EventState = true;
}

void Model::DeactivateEvent() {
    m_EventState = false;
}

bool Model::isEventActive() const {
    return (m_EventState == true) ? true : false;
}

void Model::ImplementUserChoice(const Location& userChoice, const UserInput& m_userInput) {
    /*const auto[origin, destination] = m_userInput;
    setUserChoice_Character(userChoice);

    Location Origin = (*m_pieceMap)[m_userInput.first];
    Location Destination = (*m_pieceMap)[m_userInput.second];
    m_Board->swapPawnWith(Origin, character, Destination);
    const auto[y, x] = Destination;*/
}

void Model::setUserChoice_Character(const Location& userChoice) {
    int Rook = m_PieceLocations[0].second;
    const int Queen = m_PieceLocations[1].second;
    const int Knight = m_PieceLocations[2].second;

    /*if (userChoice.second == Rook) {
        m_Piece = const_cast<wchar_t*>(m_PieceOptions[0]);
        return;
    }

    if (userChoice.second == Queen) {
        m_Piece = const_cast<wchar_t*>(m_PieceOptions[1]);
        return;
    }
    m_Piece = const_cast<wchar_t*>(m_PieceOptions[2]);*/
}

void Model::UndoStep(UserInput userInput) {
    auto[origin, destination] = userInput;

    UndoBoardUpdate(origin, destination);
    UndoPieceData_Update(origin);
    m_QueHandler->m_que = (m_QueHandler->m_que) ? false : true;
}

bool Model::isStepValid(const UserInput& userInput) {
    auto[origin, destination] = userInput;
    const auto[y, x] = origin;
    destination = destination;

     if (m_ExistanceHandler->handleRequest(*m_pieceList[y][x], destination)) {
        return true;
     }
     return false;
}

void Model::takeStep(Location origin, Index destination) {
    updateBoardMatrix(origin, destination);    
    UpdatePiece_Data(destination);
}

bool Model::isGameFinished() const {
    
}