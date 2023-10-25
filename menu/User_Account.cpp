#include "User_Account.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>

User_Account::User_Account(const Password password, const std::string& name,  const std::string& surname, WINDOW* win1) 
    : m_name {name}, 
    m_surname{surname}, 
    m_password{password} 
    {
        setName(name, win1);
        setSurname(surname, win1);
        setPassword(password);
    }
//setters
void User_Account::setName(const std::string& name, WINDOW* win1) {
   if (name_surname_Authentication(name, win1)) {
    m_name = name;
    return;
   } 
}
void User_Account::setSurname(const std::string& surname, WINDOW* win1)
{
    if (name_surname_Authentication(surname, win1)) {
        m_surname = surname;
        return;
    }
}

void User_Account::setPassword(Password password) {
    m_password = password;
    addToPasswordList(m_password);
}

//getters
std::string User_Account::getName() const
{
    return m_name;
}

std::string User_Account::getSurname() const
{
    return m_surname;
}

Password User_Account::getPassword() const
{
    return m_password;
}

void User_Account::passwordRecovery()
{
    int favouriteNumber;
    std::cout << "What is your favourite number?: ";
    std::cin >> favouriteNumber;

    char decision;
    if (favouriteNumber == m_password.second) {
        std::cout << "Your password is: " << getPassword().first << "\n";
    } else {
        std::cout << "Authentication failed!" << "\n";
        std::cout << "Do you want to create new one? y/n";
        std::cin >> decision;
    }

    if (decision == 'n' || decision == 'N') {
        return;
    }

    Password newPassword;
    std::cout << "Enter your favourite number: ";
    std::cin >> newPassword.second;
    std::cout << "Enter new passwrod: ";
    std::cin >> newPassword.first;
    m_password = newPassword;
}

bool User_Account::passwordAuthentication(const std::string& text, std::string& favouriteNumber, WINDOW* win1) {
    int number;
    try {
        number = std::stoi(favouriteNumber);
    } catch(const std::invalid_argument &ex) {
        int y, x;
        getyx(win1, y, x);
        mvwprintw(win1, y + 1, x - 21, "Invalid argument:");
        mvwprintw(win1, y + 1, x - 4,"%s",ex.what());
        wrefresh(win1);
        getch();
        wclear(win1);
        return false;
    }

    bool check{true};
    Password password;
    password.first = text;
    password.second = number;

    for (const auto& elem : listOfPasswords) {
        if (password.first == elem.first) {
            std::cout << "Password already exist!" << "\n";
            check  = false;
            }
    }
    addToPasswordList(password);
    return check;
}

bool User_Account::name_surname_Authentication(const std::string& nameOrSurname, WINDOW* win1) const
{
    if (nameOrSurname.length() <= 2) {
        int y, x;
        getyx(win1, y, x);
        mvwprintw(win1, y + 1, x - 21, "Too short name! Should be at least 3 characters long:");
        wrefresh(win1);
        getch();
        wclear(win1);
        return false; 
    }
    for (int i = 0; i < nameOrSurname.length(); i++) {
        int n = static_cast<int>(nameOrSurname[i]);
        if (n < 65 || n > 122) {
            std::cout << "Invalid character in your name/Surname: " << nameOrSurname[i] << "\n";
            std::cout << "Your default name  and Surname are: " << "Unknown" << " User" << "\n";
            return false;
        }
    }
    return true;
}
void User_Account::edit_Name_Surname(WINDOW* win1)
{
    int y;
    int x;
    getyx(win1, y, x);
    mvwprintw(win1, y + 1, 1, "Input new name");
    wrefresh(win1);
    char newName[20];
    getstr(newName);

    mvprintw(win1, y + 2, 1, "Input new Surname");
    wrefresh(win1);
    char newSurname[20];
    getstr(newSurname);

    std::string name(newName);
    std::string surname(newSurname);
    setName(name, win1);
    setSurname(surname, win1);
}

void User_Account::showAccount(int& choice) const {
    int max_y;
    int max_x;
    getmaxyx(stdscr, max_y, max_x);
    WINDOW* userWindow  = newwin(max_y,max_x,0, 0);
    refresh();

    start_color();
    init_pair(1,COLOR_WHITE, COLOR_GREEN);
    box(userWindow, 0, 0);
    wbkgd(userWindow, COLOR_PAIR(1));

    std::string name = getName();
    attron(A_BOLD);
    mvwprintw(userWindow, 1, 75, "HELLOW %s TO WORLD'S BEST CHESS GAME!!", name.c_str());
    attroff(A_BOLD);
    wrefresh(userWindow);
    keypad(userWindow, TRUE);
    noecho();

    std::string choices[] = {"Start New Game", "Exit", "Edit Account"};
    int choice;
    int highlight = 0;
    while(true) {
        for (int i = 0; i < 3; ++i) {
            if (i == highlight) {
                wattron(userWindow, A_REVERSE);
            }
            const char* choice = choices[i].c_str();
            mvwprintw(userWindow, i + 5, 75,"%s", choice);
            wattroff(userWindow, A_REVERSE);
        }
        wrefresh(userWindow);
        choice = wgetch(userWindow);

    switch (choice) {
    case KEY_UP:
        highlight--;
        if (-1 == highlight) {
            highlight = 0;
        }
        break;
    case KEY_DOWN:
        highlight++;
        if (3 == highlight) {
            highlight = 1;
        }
        break;
    default:
        break;
    }
    if (choice == 10) {
        wclear(userWindow);
        delwin(userWindow);
        refresh();
        break;
    }
  }
    refresh();
} 
void User_Account::addToPasswordList(const Password password) 
{
    listOfPasswords.push_back(password);
}

std::vector<Password> User_Account::listOfPasswords = {};
