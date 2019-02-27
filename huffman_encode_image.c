#include "huffman_encode_image.h"


 void printBinaryValue2(unsigned int num)
 {
    char result[sizeof(num)*8];
    int count = 0;
    while(num)
    {
        result[count++] = ((num&1 == 1) ? '1' : '0');
        num>>=1;
    }
    if(count)
    {
        count--;
        while(count>=0)
        {
            putchar(result[count--]);
        }
    }
    else
    {
        putchar('0');
    }
 }

unsigned char *huffman_encode_image(struct PGM_Image *input_pgm_image, struct node *huffman_nodes,
    int number_of_nodes, long int* length_of_encoded_image_array) {

    int max_gray_value = input_pgm_image->maxGrayValue;

    unsigned int *codewords = (unsigned int *) malloc((max_gray_value+1) * sizeof(unsigned int));
    for (int i=0; i<(max_gray_value+1); i++) {
        codewords[i] = 0;
    }

    for (int i = 0; i < number_of_nodes; i++) {
        int first_idx = huffman_nodes[i].first_value;
        int second_idx = huffman_nodes[i].second_value;

        unsigned int first_code = codewords[first_idx];
        unsigned int second_code = codewords[first_idx];

        first_code = first_code << 1;
        second_code = (second_code << 1) | 1;


        codewords[first_idx] = first_code;
        codewords[second_idx] = second_code;

    }

    for (int i = 0; i <= max_gray_value; i++) {
        printf("codeword at i: %d = ", i);
        printBinaryValue2(codewords[i]);
        printf("\n");
   }


    int height = input_pgm_image->height;
    int width = input_pgm_image->width;
    unsigned char *encoded_image_data = (unsigned char*) malloc((height*width)*sizeof(unsigned int));

    for (int row = 0; row<height; row++) {
        for (int col = 0; col<width; col++) {
            *encoded_image_data = codewords[input_pgm_image->image[row][col]];
            int length = sizeof(codewords[input_pgm_image->image[row][col]]);
            *length_of_encoded_image_array += length;
            encoded_image_data += length * sizeof(unsigned char);
        }
    }

    free(codewords);


    return encoded_image_data;

}