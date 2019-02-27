#include <stdio.h>
#include <stdlib.h>
#include "libpnm.h"
#include "generate_pixel_frequency.h"
#include "generate_huffman_nodes.h"
#include "huffman_encode_image.h"
#include "store_huffman_encoded_data.h"

int validate_params(int argc, char **argv) {
    if (argc < 3) {
        puts("Usage: ./pgm_huffman_encode [INPUT IMAGE FILE] [COMPRESSED OUTPUT FILENAME]");
        exit(0);
    }
}

int main( int argc, char **argv ) {

    validate_params(argc, argv);

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    struct PGM_Image pgm_input_image;
    load_PGM_Image(&pgm_input_image, input_filename);
    int height = pgm_input_image.height;
    int width = pgm_input_image.width;
    int max_gray_value = pgm_input_image.maxGrayValue;

    int non_zero_count = 0;
    long int *pixel_frequency = generate_pixel_frequency(&pgm_input_image, &non_zero_count);

    struct node *huffman_nodes = generate_huffman_nodes(pixel_frequency, max_gray_value, non_zero_count);

    int num_nodes = non_zero_count - 1;
    long int length_of_encoded_image_array = 0;
    // long int height = pgm_input_image.height;
    // long int width = pgm_input_image.width;
    // long int upper_bound_mem = height * width;

    unsigned char *encoded_image_data = huffman_encode_image(&pgm_input_image, huffman_nodes, num_nodes, &length_of_encoded_image_array);

    printf("%d is length of encode array\n", length_of_encoded_image_array);

    FILE *out_fp;
    out_fp = fopen(output_filename, "w");
    store_huffman_encoded_data(out_fp, height, width, max_gray_value, num_nodes, &length_of_encoded_image_array, huffman_nodes, &pgm_input_image);
    fclose(out_fp);

    free_PGM_Image(&pgm_input_image);
    free(encoded_image_data);
    free(huffman_nodes);

}