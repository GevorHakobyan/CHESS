#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

#include "PiecesPrinter.hpp"

class MouseHandler {
    public:
    MouseHandler() = default;
    private:
    void HandleClick();
    Location findSquare(Location);
};
#endif
