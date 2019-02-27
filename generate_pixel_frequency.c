#include "generate_pixel_frequency.h"

long int *generate_pixel_frequency(struct PGM_Image *input_pgm_image, int *number_of_non_zero_values_in_the_frequency_array) {
    int max_grey_value = input_pgm_image->maxGrayValue;
    long int* ptr = (long int*) malloc((max_grey_value + 1) * sizeof(long int));
    int num_non_zero = *number_of_non_zero_values_in_the_frequency_array;

    for (int i = 0; i <= max_grey_value; i++) {
        ptr[i] = 0;
    }

    for (int row = 0; row < input_pgm_image->height; row++) {
        for (int col = 0; col < input_pgm_image->width; col++) {
            ptr[(int) input_pgm_image->image[row][col]] += 1;
        }
    }

    int ctr = 0;

    for (int i = 0; i <= max_grey_value; i++) {
        if (ptr[i] != 0) {
            num_non_zero++;
        }
    }
    *number_of_non_zero_values_in_the_frequency_array = num_non_zero;
    printf("NUM NON ZERO FREQ: %d\n", num_non_zero);
    return ptr;
}