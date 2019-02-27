#include <stdio.h>
#include <stdlib.h>
#include "mean_absolute_error.h"

int validate_params(int argc) {
    if (argc != 3) {
        puts("Usage: ./compare_pgm_images [IMAGE ONE FILENAME] [IMAGE TWO FILENAME]");
        exit(0);
    }
    return 0;
}

int main(int argc, char **argv) {

    char *image_filename_1 = argv[1];
    char *image_filename_2 = argv[2];
    validate_params(argc);
    float mae = mean_absolute_error(image_filename_1, image_filename_2);
    printf("The mean average error is: %f\n", mae);
}