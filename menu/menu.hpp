#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
#include <string>
#include "User_Account.hpp"
#include <vector>

//Standard Cordinates of WINDOW
#define Y 18
#define X 82

//Aliases
using Choices = std::vector<std::string>;
using SizeAndLocation = std::tuple<int, int, int, int>;

class Menu
{
    public:
        Menu();
        void PrintMenu();
        void Sign_up(const SizeAndLocation&);
        void Sign_in(const SizeAndLocation&);
        void PlayAsHost();
        void Exit();
        void DetectChoice();
        //void CreateAccount(const Password& password, const std::string& name, const std::string& surname, WINDOW* win1);
    private:
        Choices m_myMenuChoices;
        WINDOW* m_menuWindow{nullptr};
        int m_activeState{0};
};

#endif
