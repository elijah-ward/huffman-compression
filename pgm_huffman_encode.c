#include <stdio.h>
#include <stdlib.h>
#include "libpnm.h"
#include "generate_pixel_frequency.h"
#include "generate_huffman_nodes.h"
#include "huffman_encode_image.h"
#include "store_huffman_encoded_data.h"

#define MAX_GRAY 255

int main( int argc, char **argv ) {

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    struct PGM_Image pgm_input_image;
    load_PGM_Image(&pgm_input_image, input_filename);

    int non_zero_count = 0;


    long int *pixel_frequency = generate_pixel_frequency(&pgm_input_image, &non_zero_count);

    printf("non_zero_count: %d\n", non_zero_count);

    struct node *huffman_nodes = generate_huffman_nodes(pixel_frequency, MAX_GRAY, non_zero_count);

    for (int i=0; i < non_zero_count - 1; i++) {
        // printf("node first value: %d, node second value: %d\n", huffman_nodes[i].first_value, huffman_nodes[i].second_value);
    }

}