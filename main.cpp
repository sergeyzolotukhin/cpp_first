#include "curses.h"
#include "panel.h"
#include <cstring>

#define NLINES 10
#define NCOLS 40

#define BOX_D_VLINE 0xBA
#define BOX_D_HLINE 0xCD
#define BOX_D_TL_CORNER 0xC9
#define BOX_D_TR_CORNER 0xBB
#define BOX_D_BL_CORNER 0xC8
#define BOX_D_BR_CORNER 0xBC

#define BORDER_COLOR_NO 10
#define BORDER_COLOR COLOR_PAIR(BORDER_COLOR_NO)

#define WINDOW_COLOR_NO 20
#define WINDOW_COLOR COLOR_PAIR(WINDOW_COLOR_NO)

#define PROMPT_COLOR_NO 30
#define PROMPT_COLOR COLOR_PAIR(PROMPT_COLOR_NO)

using namespace std;

void init_wins(WINDOW **wins, int n);

void wshow(WINDOW *win, char *label, int label_color);

void wtitle(WINDOW *win, char *title, chtype color);

void show_win_my();

int main() {
    show_win_my();
    return 0;
}

void show_win_my() {
    WINDOW *my_wins[3];
    PANEL *my_panels[3];
    PANEL *top;
    int ch;

    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    init_pair(1, COLOR_RED, COLOR_BLUE);
    init_pair(2, COLOR_GREEN, COLOR_BLUE);
    init_pair(3, COLOR_YELLOW, COLOR_BLUE);

    init_pair(PROMPT_COLOR_NO, COLOR_WHITE, COLOR_BLACK);

    init_pair(BORDER_COLOR_NO, COLOR_WHITE, COLOR_BLUE);
    init_pair(WINDOW_COLOR_NO, COLOR_WHITE, COLOR_BLUE);

    init_wins(my_wins, 3);

    my_panels[0] = new_panel(my_wins[0]);
    my_panels[1] = new_panel(my_wins[1]);
    my_panels[2] = new_panel(my_wins[2]);

    set_panel_userptr(my_panels[0], my_panels[1]);
    set_panel_userptr(my_panels[1], my_panels[2]);
    set_panel_userptr(my_panels[2], my_panels[0]);

    update_panels();

    attron(PROMPT_COLOR);
    mvprintw(LINES - 2, 0, "Use tab to browse through the windows (F1 to Exit)");
    attroff(PROMPT_COLOR);
    doupdate();

    top = my_panels[2];
    while ((ch = getch()) != KEY_F(1)) {
        switch (ch) {
            case 9:
                top = (PANEL *) panel_userptr(top);
                top_panel(top);
                break;
        }
        update_panels();
        doupdate();
    }

    endwin();
}

void init_wins(WINDOW **wins, int n) {
    int x, y, i;
    char label[80];

    y = 2;
    x = 10;
    for (i = 0; i < n; ++i) {
        wins[i] = newwin(NLINES, NCOLS, y, x);
        sprintf(label, "Window Number %d", i + 1);
        wshow(wins[i], label, i + 1);
        y += 3;
        x += 7;
    }
}

void wborder(WINDOW *win) {
    wborder(win,
            BOX_D_VLINE, BOX_D_VLINE, BOX_D_HLINE, BOX_D_HLINE,
            BOX_D_TL_CORNER, BOX_D_TR_CORNER, BOX_D_BL_CORNER, BOX_D_BR_CORNER);
}

void wshow(WINDOW *win, char *title, int label_color) {
    wbkgd(win, WINDOW_COLOR);

    wattron(win, BORDER_COLOR);
    wborder(win);
    wattroff(win, BORDER_COLOR);

    wtitle(win, title, COLOR_PAIR(label_color));

    refresh();
}

void wtitle(WINDOW *win, char *title, chtype color) {
    wattron(win, color);
    mvwprintw(win, 0, 2, "%s", title);
    wattroff(win, color);
}