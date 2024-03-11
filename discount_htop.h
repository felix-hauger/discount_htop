#ifndef DISCOUNT_HTOP
#define DISCOUNT_HTOP

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

// Constants
#define WINDOW_X_NAME 0
#define WINDOW_X_PID 40
#define WINDOW_X_PPID 55
#define WINDOW_X_VMSIZE 75

// Utils
void say_hello();
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, size_t length);

// Services
void show_usage(WINDOW *win);

// UI
void interface();

#endif