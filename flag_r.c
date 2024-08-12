#include "my_ls.h"
#include "flag_r.h"

void reverse_order(char **list, int count) {
    for (int i = 0; i < count / 2; i++) {
        char *temp = list[i];
        list[i] = list[count - 1 - i];
        list[count - 1 - i] = temp;
    }
}
