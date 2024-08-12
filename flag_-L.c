#include "my_ls.h"
#include "flag_L.h"

void follow_symlinks(char *name, const char *path) {
    struct stat st;
    char fullpath[PATH_MAX];
    snprintf(fullpath, PATH_MAX, "%s/%s", path, name);

    if (lstat(fullpath, &st) == -1) {
        perror("lstat");
        return;
    }

    if (S_ISLNK(st.st_mode)) {
        char link_target[PATH_MAX];
        ssize_t len = readlink(fullpath, link_target, PATH_MAX - 1);
        if (len == -1) {
            perror("readlink");
            return;
        }
        link_target[len] = '\0';
        printf("%s -> %s\n", name, link_target);
    } else {
        printf("%s\n", name);
    }
}
