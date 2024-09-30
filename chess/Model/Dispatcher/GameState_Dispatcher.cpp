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

void GameStateDispatcher::setInvadingPath(const Path& invadingPath) {
    m_invadingPath = invadingPath;
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
    const auto& escapingPath = findSafeLocations();
    return false;
}

GameStateDispatcher::Path GameStateDispatcher::findSafeLocations() const {
    //left and right in point of king 
    if (isInvadorPawn()) {
        return takePawnSafePlaces();
    }

    if(isInvadorHorse()) {
        return takeKnightSafePlaces();
    }

    const auto& direction = determineCheckDirection();

    if (direction == CheckDirection::Horizontal) {
        return takeUpandDown();
    } 

    if (direction == CheckDirection::Vertical) {
        return takeRightandLeft();
    }

    if(direction == CheckDirection::L_Diagonal) {
        return takeRUandLD();
    }

    return takeRUandLD();
}

GameStateDispatcher::CheckDirection GameStateDispatcher::determineCheckDirection() const {
    const auto&[invY, invX] = m_invadingPath[0];
    const auto&[kingY, kingX] = m_King->getCurrentLocation();

    if (invY == kingY) {
        return CheckDirection::Vertical;
    }

    if (invX == kingX) {
        return CheckDirection::Horizontal;
    }

    if(invX > kingX) {
        return (invY > kingY) ? CheckDirection::R_Diagonal : CheckDirection::L_Diagonal;
    }

    return (invY < kingY) ? CheckDirection::R_Diagonal : CheckDirection::L_Diagonal;
}

bool GameStateDispatcher::isInvadorPawn() const {
    return (m_invador->getUnicodeCharacter() == L"\u2659" || m_invador->getUnicodeCharacter() ==  L"\u265F");
}

bool GameStateDispatcher::isInvadorHorse() const {
    return (m_invador->getUnicodeCharacter() ==  L"\u265E" || m_invador->getUnicodeCharacter() ==  L"\u2658");
}

GameStateDispatcher::Path GameStateDispatcher::takeKnightSafePlaces() const {
    return Path{};
}

GameStateDispatcher::Path GameStateDispatcher::takePawnSafePlaces() const {
    return Path{};
}

GameStateDispatcher::Path GameStateDispatcher::takeRDandLF() const {
    return Path{};
}

GameStateDispatcher::Path GameStateDispatcher::takeRUandLD() const {
    return Path{};
}

GameStateDispatcher::Path GameStateDispatcher::takeRightandLeft() const {
    return Path{};
}

GameStateDispatcher::Path GameStateDispatcher::takeUpandDown() const {
    return Path{};
}