#include "Gui.hpp"
#include <ncurses.h>
#include <locale.h>

int main() {
    initscr();
    setlocale(LC_ALL, "");
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    
    bkgd(COLOR_PAIR(1));
    box(stdscr, 0, 0);
    Gui* myGui{Gui::getInstance()};
    myGui->drawBoard();
    myGui->Play();
    refresh();
    getch();
    endwin();
}