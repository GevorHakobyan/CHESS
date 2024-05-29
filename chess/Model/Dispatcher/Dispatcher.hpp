#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "Board.hpp"
#include "BarriersHandler.hpp"

class Dispatcher {
    public:
    Dispatcher() = default;
    Location determineKingLocation(const wchar_t*);
};
#endif