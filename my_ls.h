#ifndef MY_LS_H
#define MY_LS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <limits.h>

typedef struct Options {
    int one;
    int l;
    int R;
    int r;
    int d;
    int t;
    int u;
    int U;
    int L;
    int start_index;
} Options;

Options parse_options(int argc, char *argv[]);
void display_content(const char *path, Options *options);
void display_directory(const char *path, Options *options);
void display_long_format(const char *name, const char *path);
void reverse_order(char **list, int count);
void sort_by_time(char **list, int count, const char *path);
void display_recursive(const char *path, Options *options);
void follow_symlinks(char *name, const char *path);

#endif // MY_LS_H

