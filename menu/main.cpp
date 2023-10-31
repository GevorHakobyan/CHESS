#include <iostream>
#include "menu.hpp"
#include <ncurses.h>
#include <tuple>

int main()
{ 
    //START
    initscr();
    noecho();
    cbreak();
    start_color();

    //sign in or sign up
    Menu startMenu;
    startMenu.PrintMenu();
    startMenu.makeChoice();
    //END
    getch();
    refresh();
    endwin();
    return 0;
}
