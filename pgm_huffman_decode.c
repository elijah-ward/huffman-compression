#include <stdio.h>
#include <stdlib.h>
#include "libpnm.h"
#include "huffman_decode_image.h"
#include "read_huffman_encoded_data.h"

int validate_params(int argc) {
    if (argc != 3) {
        puts("Usage: ./pgm_huffman_decode [COMPRESSED INPUT FILENAME] [IMAGE OUTPUT FILENAME]");
        exit(0);
    }
    return 0;
}

int main( int argc, char **argv ) {

    validate_params(argc);

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int image_width;
    int image_height;
    int max_gray_value;
    int number_of_nodes;
    long int length_of_encoded_image_array;
    struct node *huffman_nodes;

    FILE *in_fp;
    in_fp = fopen(input_filename, "r");
    // unsigned char *encoded_image_data = read_huffman_encoded_data( in_fp, &image_width, &image_height, &max_gray_value,
    //     &number_of_nodes, &huffman_nodes, &length_of_encoded_image_array );
    if (in_fp != NULL) {
        fclose(in_fp);
    }


    // struct PGM_Image *output_image = huffman_decode_image(image_width, image_height, max_gray_value, number_of_nodes,
    //     huffman_nodes, length_of_encoded_image_array, encoded_image_data);

    // save_PGM_Image(output_image, output_filename, 1);
    // free_PGM_Image(output_image);

}