#include "User_Account.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>

User_Account::User_Account(const Password& password, const std::string& name,  const std::string& surname) 
    : m_name {name}, 
    m_surname{surname}, 
    m_password{password} 
    {
        int maxY, maxX;
        getmaxyx(stdscr, maxY, maxX);
        m_accountWindow = newwin(maxY, maxX, 0, 0);
        refresh();
        m_accountProperties = {"Start New game", "Edit Account", "Exit"};
        setName(name);
        setSurname(surname);
        setPassword(password);
    }
//setters
void User_Account::setName(const std::string& name, WINDOW* win) {
   if (name_surname_Authentication(name, win)) {
    m_name = name;
    return;
   } 
}
void User_Account::setSurname(const std::string& surname, WINDOW* win)
{
    if (name_surname_Authentication(surname, win)) {
        m_surname = surname;
        return;
    }
}

void User_Account::setPassword(Password password) {
    m_password = password;
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
    char favouriteNumber;
    WINDOW* passWordWin = newwin(20, 50, Y, X);
    refresh();
    mvwprintw(passWordWin, 1, 1,  "What is your favourite number?: ");
    wrefresh(passWordWin);
    favouriteNumber = wgetch(passWordWin);

    char decision;
    if (static_cast<int>(favouriteNumber) == m_password.second) {
        mvwprintw(passWordWin, 2, 1, "Your password is: ");
        mvwprintw(passWordWin, 2, 17,"%s",getPassword().first.c_str());
        wrefresh(passWordWin);
    } else {
        mvwprintw(passWordWin, 2, 1,"Authentication failed!");
        mvwprintw(passWordWin, 3, 1, "Do you want to create new one? y/n");
        wrefresh(passWordWin);
        decision = wgetch(passWordWin);
    }

    if (decision == 'n' || decision == 'N') {
        return;
    }

    Password newPassword;
    char first;
    char second;

    mvwprintw(passWordWin,4, 1, "Enter your favourite number: ");
    wrefresh(passWordWin);
    second = wgetch(passWordWin);
    mvwprintw(passWordWin, 5, 1,"Enter new passwrod: ");
    wrefresh(passWordWin);
    first = wgetch(passWordWin);
    
    std::string First {1,first};
    std::string Second {1,second};
    if (passwordAuthentication(First, Second, passWordWin)) { 
    newPassword.second = static_cast<int>(second);
    newPassword.first = first;
    m_password = newPassword;
    }
}

bool User_Account::passwordAuthentication(const std::string& text, std::string& favouriteNumber, WINDOW* win1) {
    int number; 
    int y, x;
    getyx(win1, y, x);

    try {
        number = std::stoi(favouriteNumber);
    } catch(const std::invalid_argument &ex) {
       
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

    for (const auto& elem : m_listOfAccounts) {
        if (password == elem.second) {
            mvwprintw(win1, y + 1, x - 21,"Password already exist!");
            wrefresh(win1);
            check  = false;
            }
    }
    return check;
}

bool User_Account::name_surname_Authentication(const std::string& nameOrSurname, WINDOW* win1) const
{
    if (win1 == nullptr) {
        win1 = m_accountWindow;
    }
    int y, x;
    getyx(win1, y, x);
    if (nameOrSurname.length() <= 2) {
     
        mvwprintw(win1, y + 1, x - 21, "Too short name! Should be at least 3 characters long:");
        wrefresh(win1);
        getch();
        wclear(win1);
        return false; 
    }
    for (int i = 0; i < nameOrSurname.length(); i++) {
        int n = static_cast<int>(nameOrSurname[i]);
        if (n < 65 || n > 122) {
            mvwprintw(win1, y + 1, x - 21,"Invalid character in your name/Surname: ");
            wrefresh(win1);
            mvwprintw(win1,y + 2, x- 21,"Your default name  and Surname are: Unknown, User");
            wrefresh(win1);
            return false;
        }
    }
    return true;
}
void User_Account::edit_Name_Surname()
{
    WINDOW* editWindow = newwin(20, 50, Y, X);
    mvwprintw(editWindow, 1, 1, "Input new name");
    wrefresh(editWindow);
    char newName[20];
    getstr(newName);

    mvwprintw(editWindow,2, 1, "Input new Surname");
    wrefresh(editWindow);
    char newSurname[20];
    getstr(newSurname);

    std::string name(newName);
    std::string surname(newSurname);
    setName(name, editWindow);
    setSurname(surname, editWindow);
}

void User_Account::showAccount() {
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
void User_Account::addToAccountList(const User_Account& account) {
      std::pair<User_Account, Password> account1 = std::make_pair(account, account.getPassword()); 
      m_listOfAccounts.push_back(account1);
}

void User_Account::findAccount(const Password& password) {
    for (auto& account : m_listOfAccounts) {
        if (account.second == password) {
            account.first.showAccount();
        }
    }
}

void User_Account::detectChoice(const int choice) {
    switch(choice) {
    case 0: {
        break;
    }
    case 1: {
        edit_Name_Surname();
        break;
    }
    case 2: {
        wclear(m_accountWindow);
        wrefresh(m_accountWindow);
        break;
    }
    }
}
std::vector<std::pair<User_Account, Password>> User_Account::m_listOfAccounts = {};
