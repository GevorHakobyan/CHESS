#include <ncurses.h>
#include <locale.h>

int main() {
    initscr();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    setlocale(LC_ALL, "");

    while (true) {
        int ch = getch();

        if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_CLICKED) {
                    move(event.y, event.x);
                   addwstr(L"\u265C");
                } else if (event.bstate & REPORT_MOUSE_POSITION) {
                    move(event.y, event.x);
                   addwstr(L"\u265A");
                }

                refresh();
            }
        }

        if (ch == 'q') {
            break;
        }
    }

    endwin();
    return 0;
}

