#include "huffman_encode_image.h"

#define MAX_GRAY 255

unsigned char *huffman_encode_image(struct PGM_Image *input_pgm_image, struct node *huffman_nodes,
    int number_of_nodes, long int* length_of_encoded_image_array) {

    printf("number of nodes: %d", number_of_nodes);

    unsigned char *balls = malloc(*length_of_encoded_image_array * sizeof(char));

    return balls;

}