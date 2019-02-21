# include <stdio.h>
# include <stdlib.h>
# include "libpnm.h"

#ifndef _Q1_H_
#define _Q1_H_

/**
 * @brief      { Iterates through pixel values of image to collect frequency of each colour }
 *
 * @param      input_pgm_image                                   The input pgm image
 * @param      number_of_non_zero_values_in_the_frequency_array  The number of non zero values in the frequency array
 *
 * @return     { ptr of type long int to pixel frequency data }
 */

long int *generate_pixel_frequency(struct PGM_Image *input_pgm_image, int *number_of_non_zero_values_in_the_frequency_array);

#endif //#ifndef _Q1_H_