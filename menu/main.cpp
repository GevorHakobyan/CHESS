#include <iostream>
#include "menu.hpp"
#include <ncurses.h>
#include <tuple>

std::tuple<WINDOW*, int, int, int, int> CreateStartWindow();
void sign_in_up();

int main()
{ 
    //START
    initscr();
    noecho();
    cbreak();
    start_color();

    //sign in or sign up
    sign_in_up();

    //END
    getch();
    refresh();
    endwin();
    return 0;
}

std::tuple<WINDOW*, int, int, int, int> CreateStartWindow() {
    ///defining standard size + place
    int y_of_window {2};
    int x_of_window  {75};
    int window_length {20};
    int window_width {60}; 

    //creating a start window
    WINDOW* start_window = Create_Window(y_of_window, x_of_window,window_length, window_width);
    return std::make_tuple(start_window,y_of_window, x_of_window, window_length, window_width);
}

void sign_in_up() {
    const auto [start_window,y_of_window, x_of_window, window_length, window_width] = CreateStartWindow();
    init_pair(1,COLOR_WHITE, COLOR_GREEN);
    refresh();
    keypad(start_window, true);
    box(start_window, 0,0);
    wbkgd(start_window, COLOR_PAIR(1));
    wrefresh(start_window);
    int button_choice {0}; 
    Select_Button(start_window, button_choice);
    if (button_choice % 2 == 0) {  
        Sign_in(y_of_window,x_of_window,window_length, window_width);
    } else {
        Sign_up(y_of_window,x_of_window,window_length, window_width);
    };
}
