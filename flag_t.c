#include "my_ls.h"
#include "flag_t.h"

int compare_time(const struct stat *a, const struct stat *b) {
    return b->st_mtime - a->st_mtime;
}

void sort_by_time(char **list, int count, const char *path) {
    struct stat *stats = malloc(count * sizeof(struct stat));
    for (int i = 0; i < count; i++) {
        char fullpath[PATH_MAX];
        snprintf(fullpath, PATH_MAX, "%s/%s", path, list[i]);
        stat(fullpath, &stats[i]);
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (compare_time(&stats[i], &stats[j]) > 0) {
                char *temp = list[i];
                list[i] = list[j];
                list[j] = temp;

                struct stat temp_stat = stats[i];
                stats[i] = stats[j];
                stats[j] = temp_stat;
            }
        }
    }
    free(stats);
}
