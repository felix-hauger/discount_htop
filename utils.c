#include "discount_htop.h"

void say_hello()
{
    printf("hellothere\n");
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i]) {
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }

    return 0;
}

int my_strncmp(char *s1, char *s2, size_t length)
{
    size_t i = 0;

    while (i < length && (s1[i] || s2[i])) {
        if (s1[i] > s2[i]) {
            return 1;
        } else if (s1[i] < s2[i]) {
            return -1;
        }
        i++;
    }

    return 0;
}