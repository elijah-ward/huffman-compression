#include "read_huffman_encoded_data.h"

unsigned char *read_huffman_encoded_data(char *compressed_file_name_ptr, int *image_width, int *image_height, int *max_gray_value, int *number_of_nodes,
                                    struct node **huffman_node, long int *length_of_encoded_image_array) {

    fscanf(compressed_file_name_ptr, "%d\n%d\n%d\n%d\n%d\n", &image_width, &image_height, &max_gray_value, &number_of_nodes, &length_of_encoded_image_array);
    printf("I got --\nwidth: %d\nheight:%d\nmax_gray:%d\n,num_nodes:%d\nlength_enc_arr:%d\n", image_width, image_height, max_gray_value, number_of_nodes, length_of_encoded_image_array);
    return 0;
}