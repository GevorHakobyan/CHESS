#ifndef MENU_HPP
#define MENU_HPP

#include <ncurses.h>
#include <string>
//#include "User_Account.hpp"
#include <vector>

//Aliases
using Choices = std::vector<std::string>;
using SizeAndLocation = std::tuple<int, int, int, int>;

class Menu
{
    public:
        Menu();
        void PrintMenu() const;
        void makeChoice();
        /*void Sign_up(const std::tuple<int, int, int ,int>& sizeAndLocation);
        void Sign_in(const std::tuple<int, int, int ,int>& sizeAndLocation);
        void Start_newGame();
        void Exit();*/
    private:
        //void CreateAccount(const Password& password, const std::string& name, const std::string& surname, WINDOW* win1);
    private:
        Choices m_myMenuChoices;
        WINDOW* m_menuWindow{nullptr};
};

#endif
