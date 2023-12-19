#include "Controller.hpp"
#include <ncurses.h>
#include <locale.h>

int main() {
    initscr();
    setlocale(LC_ALL, "");
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    curs_set(0);
    
    bkgd(COLOR_PAIR(1));
    box(stdscr, 0, 0);
    Controller myController{}; 
    myController.setBoard();
    myController.Play();
   
    refresh();
    getch();
    endwin();
}