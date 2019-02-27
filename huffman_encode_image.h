# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libpnm.h"
#include "generate_huffman_nodes.h"

#ifndef _Q3_H_
#define _Q3_H_

/**
 * @brief      { huffman_encode_image }
 *
 * @param      input_pgm_image                The input pgm image
 * @param      huffman_nodes                  The huffman nodes
 * @param[in]  number_of_nodes                The number of nodes
 * @param      length_of_encoded_image_array  The length of encoded image array
 *
 * @return     { huffman-encoded image data }
 */

unsigned char *huffman_encode_image(struct PGM_Image *input_pgm_image, struct node *huffman_nodes,
    int number_of_nodes, long int* length_of_encoded_image_array);


#endif //#ifndef _Q3_H_
