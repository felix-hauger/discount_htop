#include "discount_htop.h"

void interface()
{
    // printf("ncurses version: %d.%d.%d\n", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR, NCURSES_VERSION_PATCH);

    int ch;
    // struct rusage ru;

    initscr();
    noecho();

    WINDOW *info_win = newwin(10, 100, 0, 0);
    WINDOW *win = newwin(60, 100, 10, 0);

    mvwprintw(info_win, 1, 5, "Hello, world! press [q] to quit or [r] to refresh");

    wrefresh(info_win);

    show_usage(win);

    while (1) {
        ch = wgetch(win);
        if (ch == 'q') {
            break;
        } else if (ch == 'r') {
            wclear(win);
            show_usage(win);
            wrefresh(win);
        }
        // wprintw(win, "You typed: %c\n", ch);
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