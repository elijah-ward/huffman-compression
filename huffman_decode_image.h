# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libpnm.h"
#include "generate_huffman_nodes.h"

#ifndef _Q6_H_
#define _Q6_H_

/**
 * @brief      { decodes image data with huffman decompression }
 *
 * @param[in]  image_width                    The image width
 * @param[in]  image_height                   The image height
 * @param[in]  max_gray_value                 The maximum gray value
 * @param[in]  number_of_nodes                The number of nodes
 * @param      huffman_node                   The huffman node
 * @param[in]  length_of_encoded_image_array  The length of encoded image array
 * @param      encoded_image                  The encoded image
 *
 * @return     { struct holding the PGM image }
 */

struct PGM_Image *huffman_decode_image( int image_width, int image_height, int max_gray_value, int number_of_nodes,
    struct node *huffman_node, long int length_of_encoded_image_array, unsigned char *encoded_image);

#endif //#ifndef _Q6_H_
