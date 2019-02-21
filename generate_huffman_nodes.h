# include <stdio.h>
# include <stdlib.h>
# include "libpnm.h"

#ifndef _Q2_H_
#define _Q2_H_

/**
 * @brief      { node struct to hold huffman pair }
 */

struct node
{
    int first_value;
    int second_value;
};

/**
 * @brief      { generates the ordered pairs<pixel values> required to form the huffman tree }
 *
 * @param      pixel_frequency                                   The pixel frequency
 * @param[in]  max_gray_value                                    The maximum gray value
 * @param[in]  number_of_non_zero_values_in_the_frequency_array  The number of non zero values in the frequency array
 *
 * @return     { returns an array of nodes containing the huffman pairs }
 */

struct node *generate_huffman_nodes(long int *pixel_frequency, int max_gray_value, int number_of_non_zero_values_in_the_frequency_array);

#endif //#ifndef _Q2_H_

