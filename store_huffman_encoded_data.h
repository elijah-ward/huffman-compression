# include <stdio.h>
# include <stdlib.h>
# include "libpnm.h"
#include "generate_huffman_nodes.h"

#ifndef _Q4_H_
#define _Q4_H_

void store_huffman_encoded_data(char *compressed_file_name_ptr, int image_width, int image_height, int max_gray_value, int number_of_nodes,
                                    struct node *huffman_nodes, long int length_of_encoded_image_array, unsigned char *encoded_image);


#endif //#ifndef _Q4_H_
