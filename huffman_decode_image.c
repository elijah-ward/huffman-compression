#include "huffman_decode_image.h"

#define MAX_CODE_LENGTH 30

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

void append_char(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

struct PGM_Image *huffman_decode_image( int image_width, int image_height, int max_gray_value, int number_of_nodes,
    struct node *huffman_node, long int length_of_encoded_image_array, unsigned char *encoded_image) {


    

    struct PGM_Image decomp_output_image;




}