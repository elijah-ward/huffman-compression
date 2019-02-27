# include <stdio.h>
# include <stdlib.h>
# include "libpnm.h"
#include "generate_huffman_nodes.h"

#ifndef _Q5_H_
#define _Q5_H_

/**
 * @brief      Reads a huffman encoded data.
 *
 * @param      compressed_file_name_ptr       The compressed file name pointer
 * @param      image_width                    The image width
 * @param      image_height                   The image height
 * @param      max_gray_value                 The maximum gray value
 * @param      number_of_nodes                The number of nodes
 * @param      huffman_node                   The huffman node
 * @param      length_of_encoded_image_array  The length of encoded image array
 *
 * @return     { encoded image data }
 */

unsigned char *read_huffman_encoded_data(char *compressed_file_name_ptr, int *image_width, int *image_height, int *max_gray_value, int *number_of_nodes,
                                    struct node **huffman_node, long int *length_of_encoded_image_array);


#endif //#ifndef _Q5_H_
