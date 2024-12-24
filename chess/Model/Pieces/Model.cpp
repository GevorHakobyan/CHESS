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
    if (origin == destination) {
        return false;
    }
    auto[y, x] = origin;
     
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
    isEvent(userInput);
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


void Model::ActivateEventState() {
    m_EventState = true;
}

void Model::DeactivateEvent() {
    m_EventState = false;
}

bool Model::isEventActive() const {
    return m_EventState;
}

void Model::UndoStep(UserInput userInput) {
    auto[origin, destination] = userInput;

    UndoBoardUpdate(origin, destination);
    UndoPieceData_Update(origin);
    m_QueHandler->m_que = (m_QueHandler->m_que) ? false : true;
}

void Model::isEvent(UserInput indexes) {
    auto [origin, destination] = indexes;
    auto [y, x] = origin;
    if (&(*m_pieceList[y][x]) == nullptr) {
        return;
    }

    if(Broker::isPawnEventTime(*m_pieceList[y][x], destination)) {
        ActivateEventState();
        Color color = m_pieceList[y][x]->getColor();
        setPawnColor(color);
    }
}

bool Model::isStepValid(const UserInput& userInput) {
    auto[origin, destination] = userInput;
    const auto[y, x] = origin;

     if (m_ExistanceHandler->handleRequest(*m_pieceList[y][x], destination)) {
        return true;
     }
     return false;
}

void Model::takeStep(Location origin, Index destination) {
    updateBoardMatrix(origin, destination);    
    UpdatePiece_Data(destination);
}

void Model::ImplementEvent(UserInput Indexes, PieceCharacter promotedCharacter) {
    m_Board->swapPawnWith(Indexes.first, promotedCharacter, Indexes.second);
}

Model::Color Model::getPawnColor() const {
    return m_pawnColor;
}

void Model::setPawnColor(Color color) {
    m_pawnColor = color;
}

bool Model::isGameFinished() const {
    
}