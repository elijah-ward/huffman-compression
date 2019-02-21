#include "generate_pixel_frequency.h"

#define MAX_GRAY 255

long int *generate_pixel_frequency(struct PGM_Image *input_pgm_image, int *number_of_non_zero_values_in_the_frequency_array) {
    long int* ptr = (long int*) malloc((MAX_GRAY + 1) * sizeof(long int));
    for (int i = 0; i < MAX_GRAY + 1; i++) {
        ptr[i] = 0;
    }

    for (int row = 0; row < input_pgm_image->height; row++) {
        for (int col = 0; col < input_pgm_image->width; col++) {
            ptr[(int) input_pgm_image->image[row][col]] += 1;
        }
    }

    return ptr;
}