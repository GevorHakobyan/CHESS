#include "Broker.hpp"

MyKingDispatcher* Broker::m_KingDispatcher{nullptr};
EnemyKing_Dispatcher* Broker::m_EnemyKingDispatcher{nullptr};

bool Broker::isEmpty(const Location& m_desiredLocation) {
    Board* myBoard{Board::getInstance()}; 

    return myBoard->isEmpty(m_desiredLocation).first ? true : false;
}

std::pair<bool, bool> Broker::HandleIfPawn(const Piece& myPiece, const Location& desiredLocation) {
    std::pair<bool, bool> answer;
    if (!isPawn(myPiece)) {
        answer.first = false;
        answer.second = false;
        return answer;
    }
    answer.first = true;

    if (isPawnEventTime(myPiece, desiredLocation)) {
        answer.second = true;
        return answer;
    }

    if (isOnSameColum(myPiece, desiredLocation)) {
        answer.second = !isEmpty(desiredLocation);
        return answer;
    }

    answer.second = isEmpty(desiredLocation) ? true : !(Broker::isEnemy(desiredLocation, myPiece.getColor()));
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

bool Broker::isMyKingUnderCheck(const Color pieceColor, const Location& myLocation) {
    m_KingDispatcher = MyKingDispatcher::getInstance();
    return m_KingDispatcher->Dispatch(pieceColor);
}

bool Broker::isEnemyKingUnderCheck(const Piece& myPiece) {
    m_EnemyKingDispatcher = EnemyKing_Dispatcher::getInstance();
    return m_EnemyKingDispatcher->Dispatch(myPiece);
}

