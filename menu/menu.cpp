#include "menu.hpp"
#include <ncurses.h>
#include <string>

//ALiases
//using Password = std::pair<std::string, int>;

WINDOW* Menu::Create_Window( int y_of_window, int x_of_window,int window_length, int window_width){    WINDOW* win = newwin(window_length,window_width, y_of_window, x_of_window);
    return win;
}


void Menu::Select_Button(WINDOW* win) { 
    std::string choices[] = {"Sign in!", "Sign up!"};
    int choice;
    int highlight = 0;
    mvwprintw(win,1,10, "HELLO CHESS.COM!");
    wrefresh(win);

    while(true) {
        for (int i = 0; i < 2; ++i) {
            if (i == highlight) {
                wattron(win, A_REVERSE);
            }
            const char* choice = choices[i].c_str();
            mvwprintw(win, i + 2, 10,"%s", choice);
            wattroff(win, A_REVERSE);
        }
        wrefresh(win);
        choice = wgetch(win);

    switch (choice) {
    case KEY_UP:
        highlight--;
        m_button_choice = 0;
        if (-1 == highlight) {
            highlight = 0;
        }
        break;
    case KEY_DOWN:
        highlight++;
        m_button_choice = 1;
        if (2 == highlight) {
            highlight = 1;
        }
        break;
    default:
        break;
    }
    if (choice == 10) {
        wclear(win);
        delwin(win);
        refresh();
        break;
    }
  }
}

void Sign_up(int y_of_window, int x_of_window, int window_length, int window_width)
{
    WINDOW* sign_up_window = newwin(window_length,window_width, y_of_window, x_of_window);
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
            CreateAccount(password, name, surname, sign_up_window);

            refresh();
            break;
        }

    }

    wrefresh(sign_up_window);
    getch();
    wclear(sign_up_window);
    delwin(sign_up_window);
}

void Sign_in(int y_Of_WINDOW, int x_Of_WINDOW, int Window_Length, int Window_Width)
{
    WINDOW* sign_in_Window = newwin(Window_Length,Window_Width,y_Of_WINDOW, x_Of_WINDOW);
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

void CreateAccount(const Password& password, const std::string& name, const std::string& surname, WINDOW* win1) {
    User_Account user1{password, name, surname, win1};
    user1.showAccount();
}
