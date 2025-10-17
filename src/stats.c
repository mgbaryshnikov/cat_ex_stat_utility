#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include "stats.h"

void file_stats (char *filename) {
    FILE *file = fopen(filename, "r");
    int desc = fileno(file);
    struct stat info_file;
    fstat(desc, &info_file);
    off_t size = info_file.st_size;
    printf("Размер - %lld Байт", (long long)size);
}

int stats_mod(int argc, char *argv[], char **filename) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                *filename = argv[i + 1];
                return 1;
            } else {
                fprintf(stderr, "Введите еще и имя файла\n");
                exit(1);
            }
        }
    }
    return 0;
}