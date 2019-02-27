#include "read_huffman_encoded_data.h"

unsigned char *read_huffman_encoded_data(char *compressed_file_name_ptr, int *image_width, int *image_height, int *max_gray_value, int *number_of_nodes,
                                    struct node **huffman_node, long int *length_of_encoded_image_array) {

    int width,height,max_gray,num_nodes,length_of_encoded;

    fscanf(compressed_file_name_ptr, "%d\n%d\n%d\n%d\n%d\n", &width, &height, &max_gray, &num_nodes, &length_of_encoded);
    printf("I got --\nwidth: %d\nheight:%d\nmax_gray:%d\nnum_nodes:%d\nlength_enc_arr:%ld\n", width, height, max_gray, num_nodes, length_of_encoded);

    image_width = &width;
    image_height = &height;
    max_gray_value = &max_gray;
    number_of_nodes = &num_nodes;

    struct node *nodes = (struct node*) malloc(num_nodes * sizeof(struct node));
    unsigned char *encoded_image_data = (unsigned char*) malloc((height*width)*sizeof(unsigned int));

    fread(nodes, sizeof(struct node), number_of_nodes, compressed_file_name_ptr);
    fread(encoded_image_data, 1, length_of_encoded_image_array, compressed_file_name_ptr);

    huffman_node = &nodes;

    return encoded_image_data;
}