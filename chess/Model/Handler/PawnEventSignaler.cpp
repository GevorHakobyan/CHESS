#include "PawnEventSignaler.hpp"

bool PawnEventSignaler::_eventState{false};

bool PawnEventSignaler::isEventActive() {
    return _eventState;
}

void PawnEventSignaler::activateState() {
    _eventState = (_eventState) ? _eventState : !_eventState;
}

void PawnEventSignaler::deactivateState() {
    _eventState = (_eventState) ? !_eventState : _eventState;
}