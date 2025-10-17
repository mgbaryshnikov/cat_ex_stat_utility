#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"

void print_file (char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[1024];
    if (file == NULL) {
        fprintf(stderr, "Такой директории не существует!");
        return;
    }
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}
int cat_mode(int argc, char *argv[], char **filename) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
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