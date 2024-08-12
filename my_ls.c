#include "my_ls.h"

int main(int argc, char *argv[]) {
    Options options = parse_options(argc, argv);

    for (int i = options.start_index; i < argc; i++) {
        if (options.d) {
            display_directory(argv[i], &options);
        } else {
            display_content(argv[i], &options);
            if (options.R) {
                display_recursive(argv[i], &options);
            }
        }
    }
    return 0;
}

