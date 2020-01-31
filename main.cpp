//#include <iostream>
#include "curses.h"

using namespace std;

int main() {
    initscr();

    mvprintw( 5, 5, "Hello, World!" );
    getch();

    endwin();
    return 0;

    return 0;
}