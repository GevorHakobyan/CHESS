#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
#include <string>
#include "User_Account.hpp"

class Menu
{
    public:
        Menu() = default;
        void Select_Button(WINDOW* win);
        void Sign_up(int y_Of_WINDOW, int x_Of_WINDOW, int Window_Length, int Window_Width);
        void Sign_in(int y_Of_WINDOW, int x_Of_WINDOW, int Window_Length, int Window_Width);
        void CreateAccount(const Password& password, const std::string& name, const std::string& surname, WINDOW* win1);
    private:
        WINDOW* Create_Window( int y_Of_WINDOW, int x_Of_WINDOW,int Window_Length, int Window_Width); 
    private:
        int m_button_choice;
};

#endif
