#include "store_huffman_encoded_data.h"

void store_huffman_encoded_data(char *compressed_file_name_ptr, int image_width, int image_height, int max_gray_value, int number_of_nodes,
                                    struct node *huffman_nodes, long int length_of_encoded_image_array, unsigned char *encoded_image) {\

    fprintf(compressed_file_name_ptr, "%d\n%d\n%d\n%d\n%ld\n",
        image_width, image_height, max_gray_value, number_of_nodes, length_of_encoded_image_array);

    //write huffman_nodes to file
    fwrite(huffman_nodes, sizeof(struct node), number_of_nodes, compressed_file_name_ptr);

    //write encoded image array to the file
    fwrite(encoded_image, 1, length_of_encoded_image_array, compressed_file_name_ptr);

}