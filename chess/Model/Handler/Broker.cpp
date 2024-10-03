#include "Broker.hpp"

Broker::MyKingDispatcherPtr Broker::m_KingDispatcher{MyKingDispatcher::getInstance()};
Broker::EnemyKingDispatcherPtr Broker::m_EnemyKingDispatcher{EnemyKing_Dispatcher::getInstance()};
Broker::GameStatePtr Broker::m_GameStateDispatcher{GameStateDispatcher::getInstance()};

bool Broker::isEmpty(const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 

    return myBoard->isEmpty(m_desiredLocation).first; 
}

Broker::Answer Broker::HandleIfPawn(const Piece& myPiece, const Location& desiredLocation) {
    std::tuple<bool, bool, bool> answer;
    if (!isPawn(myPiece)) {
        return {false, false, false};
    }
    std::get<0>(answer) = true;

    if (isPawnEventTime(myPiece, desiredLocation)) {
        std::get<1>(answer) = true;
        std::get<2>(answer) = false;
        return answer;
    }

    if (isOnSameColum(myPiece, desiredLocation)) {
        std::get<1>(answer) = false;
        std::get<2>(answer) = true;
        return answer;
    }

    std::get<1>(answer) = false;
    std::get<2>(answer) = false;
    return answer;
}
bool Broker::isEnemy(const Location& m_desiredLocation, const Color& m_PieceColor ) {
    Board* myBoard{Board::getInstance()}; 
    Color desiredPieceColor = myBoard->isEmpty(m_desiredLocation).second;

    return desiredPieceColor == m_PieceColor ? false : true;
}

bool Broker::isOnSameColum(const Piece& myPiece, const Location& desiredLocation) {
    const auto[pieceColum, pieceRow] = myPiece.getCurrentLocation();
    const auto[desiredColum, desiredRow] = desiredLocation;

    if (pieceRow == desiredRow) { 
        return true;
    }
    return false;
}

bool Broker::isPawn(const Piece& myPiece) {
    const wchar_t* blackPawn = L"\u2659";
    const wchar_t* whitePawn = L"\u265F";
    if (*myPiece.getUnicodeCharacter()== *blackPawn || *myPiece.getUnicodeCharacter() == *whitePawn) {
        return true;
    } 
    return false; 
}

bool Broker::isPawnEventTime(const Piece& myPiece, const Location& myLocation) {
    int BoardMax{7};
    int BoardMin{0};
    if (!isPawn(myPiece)) {
        return false;
    }

    if (isOnSameColum(myPiece, myLocation) && !isEmpty(myLocation)) {
        return false;
    }

    if (!isEnemy(myLocation, myPiece.getColor())) {
        return false;
    }
    return  (myLocation.first == BoardMax || myLocation.first == BoardMin) ? true : false;
}

void Broker::CreatePawnEvent(const Location& desiredCoordinates, const Location& desiredLocation, const Color pieceColor) {
    if (!isEmpty(desiredLocation)) {
        return;
    }
    PieceOptions m_Options = getPieceOptions(pieceColor);
}

PieceOptions Broker::getPieceOptions(const Color& PiecesColors) {
    PieceOptions options;
    if (PiecesColors == Color::Black) {
        const wchar_t* Rook{L"\u2656"};
        const wchar_t* Queen{L"\u2655"};
        const wchar_t* Knight{ L"\u2658"};
        options.push_back(Rook);
        options.push_back(Queen);
        options.push_back(Knight);
        return options;
    }
    const wchar_t* Rook{L"\u265C"};
    const wchar_t* Queen{L"\u265B"};
    const wchar_t* Knight{ L"\u265E"};
    options.push_back(Rook);
    options.push_back(Queen);
    options.push_back(Knight);
    return options;
}

PieceLocations Broker::getPieceLocations(const Location& destination) {
    int verticalStep = (destination.first < 42) ? -5 : 5; 
    int horizontalStep{9};
    PieceLocations locations;
    Location tmpLocation;

    tmpLocation.first = (destination.first + verticalStep);
    tmpLocation.second = (destination.second - horizontalStep);
    locations.push_back(tmpLocation);

    tmpLocation.second = (destination.second);
    locations.push_back(tmpLocation);

    tmpLocation.second = (destination.second + horizontalStep);
    locations.push_back(tmpLocation);

    return locations;
}

bool Broker::isMyKingUnderCheck(const Piece& myPiece) {
    //m_KingDispatcher = MyKingDispatcher::getInstance();
    return m_KingDispatcher->Dispatch(myPiece);
}

bool Broker::isEnemyKingUnderCheck(const Piece& myPiece) {
    //m_EnemyKingDispatcher = EnemyKing_Dispatcher::getInstance();
    return m_EnemyKingDispatcher->Dispatch(myPiece);
}

bool Broker::isKingKilled(const Piece& Invador) {
    m_GameStateDispatcher->setInvadingPath(m_EnemyKingDispatcher->getInvadingPath());
    const auto canEscape = m_GameStateDispatcher->Dispatch(Invador);
    if(canEscape) {
        return false;
    }
}

