#include <ncurses.h>

int main()
{
    initscr();
    printw("Hello! Press any key to exit");
    refresh();
    getch();
    endwin();
    return 0;
}