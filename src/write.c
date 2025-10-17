#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write.h"

void write_file (char *filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        fprintf(stderr, "Ошибка создания файла!");
        exit(1);
    }
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, file);
        
        if (strcmp(buffer, "\n") == 0) {
            break;
        }
    }
    fclose(file);
}  

int get_write_filename(int argc, char *argv[], char **filename) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-w") == 0) {
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