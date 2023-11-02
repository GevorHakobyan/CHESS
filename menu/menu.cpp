#include "menu.hpp"
#include <ncurses.h>
#include <string>
#include <tuple>

//ALiases
//using Choices = std::vector<std::string>;
//using SizeAndLocation = std::tuple<int, int, int, int>;

Menu::Menu() {
    m_menuWindow = newwin(10, 30, Y, X);
    refresh();
    m_myMenuChoices.push_back("Sign Up");
    m_myMenuChoices.push_back("Sign In");
    m_myMenuChoices.push_back("Start New Game");
    m_myMenuChoices.push_back("Exit");
}

void Menu::PrintMenu() {
    wrefresh(m_menuWindow);
    box(m_menuWindow, 0, 0);
    wrefresh(m_menuWindow);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    wbkgd(m_menuWindow, COLOR_PAIR(1));
    int c;

    keypad(m_menuWindow, TRUE);
    while(true) {
        for (int i = 0; i < m_myMenuChoices.size(); ++i) {
            if (i == m_activeState) {
                wattron(m_menuWindow, A_REVERSE);
            }
            mvwprintw(m_menuWindow, i + 1, 10, "%s", m_myMenuChoices[i].c_str());
            wattroff(m_menuWindow, A_REVERSE);
            wrefresh(m_menuWindow);
        }
        wrefresh(m_menuWindow);
        c = wgetch(m_menuWindow);
    switch(c) {
        case KEY_UP: {
            if (m_activeState != 0) {
                --m_activeState;
            }
            break;
        }
        case KEY_DOWN: {
            if (m_activeState != 3) {
                ++m_activeState;
            }
            break;
            }
            case 10: {
            DetectChoice();
            break;
            }
            case 'q': {
            return;
            }
        }
    }
}

void Menu::Sign_up(const SizeAndLocation& windowCharacters) {
    const auto[n_lines, n_rows, y, x] = windowCharacters;
    WINDOW* sign_up_window = newwin(n_lines, n_rows, y, x);
    std::string arguments[] = {"name: ", "surname: ", "password: ", "favourite number: "};
    refresh();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_GREEN);
    box(sign_up_window, 0, 0);
    wbkgd(sign_up_window, COLOR_PAIR(1));
    wrefresh(sign_up_window);

    char input[20];
    std::string parameters[4];
    raw();

    while (true) {
        for (int i = 0; i < 4; i++) {
            mvwprintw(sign_up_window, i + 1, 1,"%s", arguments[i].c_str());
            wgetstr(sign_up_window, input);
            size_t temp  = arguments[i].length();
            int distanc = static_cast<int>(temp);
            mvwprintw(sign_up_window, i + 1, temp + 3, "%s", input);
            wrefresh(sign_up_window);
            parameters[i] = input;
        }

        if (User_Account::passwordAuthentication(parameters[2], parameters[3], sign_up_window)) {
            wrefresh(sign_up_window);

            std::string myPassword = parameters[2];
            int favouriteNumber = std::stoi(parameters[3]);
            Password password = std::make_pair(myPassword, favouriteNumber);
            const std::string name{parameters[0]};
            const std::string surname{parameters[1]};
            wrefresh(sign_up_window);
            wclear(sign_up_window);
            delwin(sign_up_window);
            CreateAccount(password, name, surname);

            refresh();
            break;
        }

    }

    
}

void Menu::Sign_in(const SizeAndLocation& windowCharacters)  {
    const auto[n_lines, n_rows, y, x] = windowCharacters;
    WINDOW* sign_in_Window = newwin(n_lines, n_rows, y, x);
    refresh();

    start_color();
    init_pair(1,COLOR_WHITE, COLOR_GREEN);
    box(sign_in_Window, 0, 0);
    wbkgd(sign_in_Window, COLOR_PAIR(1));
    wrefresh(sign_in_Window);
    mvwprintw(sign_in_Window, 1 , 1, "Input Password: ");
    wrefresh(sign_in_Window);

    char input1[20];
    wgetstr(sign_in_Window, input1);
    mvwprintw(sign_in_Window, 1, 17,"%s", input1);
    wrefresh(sign_in_Window);

    mvwprintw(sign_in_Window, 2, 1, "Favourite number: ");
    wrefresh(sign_in_Window);
    char input2[20];
    wgetstr(sign_in_Window, input2);

    mvwprintw(sign_in_Window, 2,19,"%s",input2);
    wrefresh(sign_in_Window);
    refresh();

    std::string userInput1 = input1;
    std::string userInput2 = input2;
    wclear(sign_in_Window);
    delwin(sign_in_Window);
}

void Menu::PlayAsHost() {
    return;
}

void Menu::Exit() {
    return;
}

void Menu::DetectChoice() {
    SizeAndLocation windowCharacters = std::make_tuple(20, 50, Y, X);

    switch(m_activeState) {
        case 0: {
            Sign_up(windowCharacters);
            break;
        }
        case 1: {
            Sign_in(windowCharacters);
            break;
        }
        case 2: {
            PlayAsHost();
            break;
        }
        case 3: {
            Exit();
            break;
        }
    }
}

void Menu::CreateAccount(const Password& password, const std::string& name, const std::string& surname) {
    User_Account user1{password, name, surname};
    int choice {0};
    user1.showAccount(choice);
}
