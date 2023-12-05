#include "MouseHandler.hpp"

void MouseHandler::HandleClick () {
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);

     while (true) {
        int ch = getch();

        if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {

                } 
                refresh();
            }
        }

        if (ch == 'q') {
            break;
        }
    }
}

Location MouseHandler::findSquare(Location specifiedLocation) {
   const SquareIdentity mySquares{}

   for (const auto& )
}