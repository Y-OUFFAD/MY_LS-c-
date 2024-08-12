#include "utils.h"
#include <time.h>

char *get_permissions(mode_t mode) {
    static char perms[11];
    strcpy(perms, "----------");

    perms[0] = S_ISDIR(mode) ? 'd' : (S_ISLNK(mode) ? 'l' : '-');
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';

    return perms;
}

char *get_time(time_t time) {
    static char buf[20];
    struct tm *timeinfo = localtime(&time);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", timeinfo);
    return buf;
}
