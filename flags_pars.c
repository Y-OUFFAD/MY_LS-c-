#include "my_ls.h"

Options parse_options(int argc, char *argv[]) {
    Options options = {0};
    options.start_index = 1;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j]; j++) {
                switch (argv[i][j]) {
                    case '1': options.one = 1; break;
                    case 'l': options.l = 1; break;
                    case 'R': options.R = 1; break;
                    case 'r': options.r = 1; break;
                    case 'd': options.d = 1; break;
                    case 't': options.t = 1; break;
                    case 'u': options.u = 1; break;
                    case 'U': options.U = 1; break;
                    case 'L': options.L = 1; break;
                    default: 
                        fprintf(stderr, "Unknown option: -%c\n", argv[i][j]);
                        exit(EXIT_FAILURE);
                }
            }
        } else {
            options.start_index = i;
            break;
        }
    }
    return options;
}

