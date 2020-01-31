//#include <iostream>
#include "curses.h"
#include "panel.h"

using namespace std;

int main() {
    initscr();
    cbreak();
    noecho();

//    mvprintw( 5, 5, "Hello, World!" );


    WINDOW *my_wins[3];
    PANEL  *my_panels[3];
    int lines = 10, cols = 40, y = 2, x = 4, i, max = 5;

    for(i = 0; i < max; ++i) {
        my_wins[i] = newwin(lines, cols, y + 1 * i, x + 5 * i);
        box(my_wins[i], 0, 0);

        my_panels[i] = new_panel(my_wins[i]);
    }

    update_panels();

    update_panels();
    doupdate();

    getch();
    endwin();
    return 0;
}