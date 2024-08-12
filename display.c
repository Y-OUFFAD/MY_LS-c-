#include "display.h"

void display_content(const char *path, Options *options) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            if (options->l) {
                display_long_format(entry->d_name, path);
            } else {
                printf("%s\n", entry->d_name);
            }
        }
    }
    closedir(dir);
}

void display_directory(const char *path, Options *options) {
    printf("%s:\n", path);
    display_content(path, options);
}
