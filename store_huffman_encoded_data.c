#include "store_huffman_encoded_data.h"

void store_huffman_encoded_data(char *compressed_file_name_ptr, int image_width, int image_height, int max_gray_value, int number_of_nodes,
                                    struct node *huffman_nodes, long int length_of_encoded_image_array, unsigned char *encoded_image) {

    fprintf(compressed_file_name_ptr, "P5\n%d %d\n%d\n",
        image_width, image_height, max_gray_value);

    for(int i = 0; i < length_of_encoded_image_array; i++)
        fputc(encoded_image[i], compressed_file_name_ptr);



}