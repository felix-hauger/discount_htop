#ifndef DISCOUNT_HTOP
#define DISCOUNT_HTOP

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <string.h>

// Utils
void say_hello();
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, size_t length);

// Services
void show_usage();

// UI
void interface();

#endif