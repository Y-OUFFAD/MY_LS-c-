#include "my_ls.h"
#include "flag_R.h"

void display_recursive(const char *path, Options *options) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && 
            strcmp(entry->d_name, ".") != 0 && 
            strcmp(entry->d_name, "..") != 0) {

            char fullpath[PATH_MAX];
            snprintf(fullpath, PATH_MAX, "%s/%s", path, entry->d_name);

            printf("\n%s:\n", fullpath);
            display_content(fullpath, options);

            display_recursive(fullpath, options);
        }
    }
    closedir(dir);
}
