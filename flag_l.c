#include "display.h"

void display_long_format(const char *name, const char *path) {
    struct stat st;
    char fullpath[PATH_MAX];
    snprintf(fullpath, PATH_MAX, "%s/%s", path, name);
    
    if (stat(fullpath, &st) == -1) {
        perror("stat");
        return;
    }
    
    printf("%10.10s %ld %s %s %ld %s %s\n",
           get_permissions(st.st_mode),
           st.st_nlink,
           getpwuid(st.st_uid)->pw_name,
           getgrgid(st.st_gid)->gr_name,
           st.st_size,
           get_time(st.st_mtime),
           name);
}
