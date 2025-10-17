#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"
#include "write.h"
#include "stats.h"

int main (int argc, char *argv[]) {
    char *filename = NULL;
    if (get_write_filename(argc, argv, &filename)) {
        write_file(filename);
    }
    else if (cat_mode(argc, argv, &filename)) {
        print_file(filename);
    }
    else if (stats_mod(argc, argv, &filename)) {
        file_stats(filename);
    }
}
