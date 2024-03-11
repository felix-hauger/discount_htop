#include "discount_htop.h"

void show_usage(WINDOW *win)
{
    // printf("USAGE: %d\n", getrusage(4476));
    // FILE **statuses;
    DIR *proc;
    struct dirent *dt;
    FILE *status;
    char line[200];

    // struct dirent *current_processus;

    proc = opendir("/proc");

    if (proc == NULL) {
        perror("Error accessing process list\n");
        exit(1);
    }

    mvwprintw(win, 1, 0, "NAME");
    mvwprintw(win, 1, 40, "PID");
    mvwprintw(win, 1, 55, "PPID");
    mvwprintw(win, 1, 75, "VM SIZE\n");
    int i = 0;

    while ((dt = readdir(proc)) != NULL) {
        // current_processus = readdir(dt);
        // mvwprintw("%s\n", dt->d_name);
        char path[500];
        snprintf(path, sizeof(path), "/proc/%s/status", dt->d_name);
        
        status = fopen(path, "r");
        if (status != NULL) {
            while (fgets(line, sizeof(line), status)) {
                if (my_strncmp(line, "Name:", 5) == 0) {
                    int length = strlen(line);
                    if (length > 0 && line[length - 1] == '\n') {
                        line[length - 1] = '\0'; // Remove the newline character
                    }

                    mvwprintw(win, i+2, 0, "%s\t", line);

                } else if (my_strncmp(line, "Pid:", 4) == 0) {
                    mvwprintw(win, i+2, 40, "%s\t", line);
                } else if (my_strncmp(line, "PPid:", 5) == 0) {
                    mvwprintw(win, i+2, 55, "%s\t", line);
                } else if (my_strncmp(line, "VmSize:", 7) == 0) {
                    mvwprintw(win, i+2, 75, "%s\t", line);
                }
            }
            wprintw(win, "\n");

            fclose(status);
            i++;
        }
    }

    closedir(proc);
    wrefresh(win);
};