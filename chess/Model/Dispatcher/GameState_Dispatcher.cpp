#include "GameState_Dispatcher.hpp"

GameStateDispatcher::thisPtr GameStateDispatcher::m_ptr{nullptr};

GameStateDispatcher::thisPtr GameStateDispatcher::getInstance() {
    if (!m_ptr) {
        m_ptr.reset(new GameStateDispatcher());
    }
    return m_ptr;
}

bool GameStateDispatcher::Dispatch(const Piece& invador) {
    const auto king = findKing(invador);
    setKing(king);
    setInvador(invador);
    return isGameInDeadState();
} 

bool GameStateDispatcher::isGameInDeadState() const {
    return isKingKilled();
}

const GameStateDispatcher::PiecePtr GameStateDispatcher::findKing(const Piece& invador) {
    const auto boardPtr = Board::getInstance();
    const auto& pieceList = boardPtr->getPieceList();
    const wchar_t* kingCharacter = (invador.getColor() == Color::White) ? L"\u2654" : L"\u265A";

    for (size_t i{0}; i < 8; ++i) {
        for (const auto& piece : pieceList[i]) {

            if (!piece) {
                continue;
            }

            if (*piece->getUnicodeCharacter() == *kingCharacter) {
                return piece.get();
            }
        }
    }

    return {nullptr};
}

void GameStateDispatcher::setKing(const PiecePtr king) {
    m_King = king;
}

void GameStateDispatcher::setInvador(const Piece& piece) {
    m_invador = &piece;
}

bool GameStateDispatcher::isKingKilled() const { 
    const auto& escapingPath = findEscapingPath(); //from this check only
    bool isSafe = isAnySafe(escapingPath);
    return false;
}

GameStateDispatcher::Path GameStateDispatcher::findEscapingPath() const {
    //left and right in point of king 
    if (isInvadorPawn()) {
        return takePawnSafePlaces();
    }

    const auto& kingCoordinates = m_King->getAvailableCoordinates();
    Path escapingPath;

    for (const auto& coordinate : kingCoordinates) {
        if (!isAvailableForInvador(coordinate)) {
            escapingPath.push_back(coordinate);
        }    
    }
    return escapingPath;
}


bool GameStateDispatcher::isInvadorPawn() const {
    const auto blackPawn = L"\u2659";
    const auto whitePawn = L"\u265F";
    return (*(m_invador->getUnicodeCharacter()) == *blackPawn || *(m_invador->getUnicodeCharacter()) ==  *whitePawn);
}

bool GameStateDispatcher::isAvailableForInvador(const Location& coordinate) const {
    const auto& invadorCoordinates = m_invador->getAvailableCoordinates();

    for (const auto& location : invadorCoordinates) {
        if(location == coordinate) {
            return true;
        }
    }
    return true;
}

GameStateDispatcher::Path GameStateDispatcher::takePawnSafePlaces() const {
    const auto& kingCoordinates = m_King->getAvailableCoordinates();
    Path escapingPath;

    for (const auto& coordinate : kingCoordinates) { //all are available then..
        escapingPath.push_back(coordinate);
    }

    return escapingPath;
}

bool GameStateDispatcher::isAnySafe(const Path& escapingPath) const {
    for (const auto& coordinate : escapingPath) {
        if (isSafe(coordinate)) {
            return true;
        }
    }
    return false;
}

bool GameStateDispatcher::isSafe(const Location& coordinate) const {
    const auto m_board = Board::getInstance();
    const auto& pieceList = m_board->getPieceList();
    bool isAvailableForEnemy{false};

    for (size_t i{0}; i < 8; ++i) {
        for (const auto& piece : pieceList[i]) {
            if (isAvailableForEnemy) {
                return false;
            }

            if (!piece) {
                continue;
            }

            if (piece->getColor() == m_invador->getColor()) {
                isAvailableForEnemy = SearchInAvailable_Coordinates(*piece, coordinate);
            }
        }
    }

    return true;
}
