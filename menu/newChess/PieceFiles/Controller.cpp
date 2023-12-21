#include <Controller.hpp>

Controller::Controller() 
: m_Model{Model::getInstance()} {};


void Controller::setBoard() {
    BoardView* myBoard{BoardView::getInstance()};
    BoardPrinter printer{myBoard};
    PiecesPrinter piecePrinter{m_Model->getPieceList()};
    printer.Print(piecePrinter);
    piecePrinter.moveMapTo_View(m_PieceMap); 
    m_Mouse = MouseHandler::getInstance();
    m_Model->setMap(m_PieceMap);
}

void Controller::Play() {
    while(true) {
        m_UserInput = m_Mouse->getUserInput();
        bool step{false}; 
        step = m_Model->Move(m_UserInput);
        isMoveSuccessful(step);
    }
}

void Controller::isMoveSuccessful(bool step) {
    if (!step) {
        if (m_Model->isEventActive()) {
            CreatePawnEvent();
        }
        return;
    } 
    const wchar_t* piece = m_Model->getMovedPiece_Character();
    const wchar_t* square = m_Model->getSquare_Character();
    PiecesPrinter::printCharacter(piece, m_UserInput.second);
    PiecesPrinter::printCharacter(square, m_UserInput.first);
}

void Controller::CreatePawnEvent() {
    PieceOptions m_options = m_Model->getPieceOptions();
    PieceLocations m_locations = m_Model->getPieceLocations();

    printEventOptions(m_options, m_locations);
    Location m_userChoice = getUserChoice();

    m_Model->ImplementUserChoice(m_userChoice, m_UserInput);
    ImpelementGraphically(m_locations);
    
    m_Model->DeactivateEvent();
}

void Controller::printEventOptions(const PieceOptions& m_options, const PieceLocations& m_locations) {
    PiecesPrinter::printCharacter(m_options[0], m_locations[0]);
    PiecesPrinter::printCharacter(m_options[1], m_locations[1]);
    PiecesPrinter::printCharacter(m_options[2], m_locations[2]);
}

Location Controller::getUserChoice() {
    Location tmpLocation;
    std::optional<Location> userChoice;
    while (true) {
        tmpLocation = m_Mouse->getUserChoice();
        userChoice = evaluateChoice(tmpLocation);
        if (userChoice.has_value()) {
            return userChoice.value();
        }
    }
}

std::optional<Location> Controller::evaluateChoice(const Location& userInput) {
    PieceLocations m_locations = m_Model->getPieceLocations();
   std::optional<Location> userChoice;

    for (const auto& location : m_locations) {
        userChoice = approximateChoice(userInput, location);
        if (userChoice.has_value()) {
            return userChoice;
        }
    }
    return std::nullopt;
}

 std::optional<Location> Controller::approximateChoice(const Location& userInput, const Location& m_locatoion) {
    if (!(userInput.second + 3 >= m_locatoion.second)) {
        return std::nullopt;
    }
    
     if (!(userInput.second - 3 <= m_locatoion.second)) {
        return std::nullopt;
    }
    return m_locatoion;
}

void Controller::ImpelementGraphically(const PieceLocations& m_locations) {
    const wchar_t* square = m_Model->getSquare_Character();
    PiecesPrinter::printCharacter(square, m_UserInput.first);

    const wchar_t* character = m_Model->getMovedPiece_Character();
    PiecesPrinter::printCharacter(character, m_UserInput.second);

    const wchar_t* BlankCharacter = L" ";
    PiecesPrinter::printCharacter(BlankCharacter, m_locations[0]);
    PiecesPrinter::printCharacter(BlankCharacter, m_locations[1]);
    PiecesPrinter::printCharacter(BlankCharacter, m_locations[2]);
}
