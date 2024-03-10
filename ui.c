#include "discount_htop.h"

void interface()
{
    printf("ncurses version: %d.%d.%d\n", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR, NCURSES_VERSION_PATCH);

    int ch;
    // struct rusage ru;

    initscr();
    noecho();

    WINDOW *win = newwin(100, 100, 0, 0);
    waddstr(win, "Hello, world! press q to quit\n");

    while (1) {
        // wprintw(win, "Hello, world!");
        ch = getch();
        if (ch == 'q') {
            break;
        }
        wprintw(win, "You typed: %c\n", ch);
        wrefresh(win);
        refresh();
    }
    // while (true && (ch != ERR && ch != 'q' && ch != 'Q')) {
    //     ch = getch();
    //     getrusage(RUSAGE_SELF, &ru);
    //     printw("CPU time used: %ld.%06ld sec user, %ld.%06ld sec system\n",
    //            ru.ru_utime.tv_sec, ru.ru_utime.tv_usec,
    //            ru.ru_stime.tv_sec, ru.ru_stime.tv_usec);
    //     refresh();
    // }
    endwin();
}