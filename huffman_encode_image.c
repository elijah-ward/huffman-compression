#include "huffman_encode_image.h"

#define MAX_CODE_LENGTH 30

void append_char(char *s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}

unsigned char *huffman_encode_image(struct PGM_Image *input_pgm_image, struct node *huffman_nodes,
    int number_of_nodes, long int* length_of_encoded_image_array) {

    int max_gray_value = input_pgm_image->maxGrayValue;

    unsigned char **codewords = (unsigned char **) malloc((max_gray_value+1) * sizeof(unsigned char*));
    for (int i=0; i<(max_gray_value+1); i++) {
        codewords[i] = (unsigned char *) malloc(MAX_CODE_LENGTH * sizeof(unsigned char));
        // codewords[i][0] = '\0';
        strdup(codewords[i], "");
        // printf("char at codeword i = %d: %u\n", i, codewords[i][0]);
    }

    // printf("number of nodes: %d\n", number_of_nodes);

    for (int i = 0; i < number_of_nodes; i++) {
        int first_idx = huffman_nodes[i].first_value;
        int second_idx = huffman_nodes[i].second_value;
        char first_code[MAX_CODE_LENGTH];
        char second_code[MAX_CODE_LENGTH];
        strcpy(first_code, codewords[first_idx]);
        strcpy(second_code, codewords[first_idx]);


        // strcpy(codewords[second_idx], codewords[first_idx]);
        int first_code_len = strlen(first_code);
        int second_code_len = strlen(second_code);


        append_char(first_code, '0');
        append_char(second_code, '1');

        // printf("first_code 0: %d\n", strlen(first_code));

        strcpy(codewords[first_idx], first_code);
        strcpy(codewords[second_idx], second_code);

        printf("first_idx: %d, second_idx:%d\n ", first_idx, second_idx );

        // if (i==0) {



        //     for (int k = 0; k < max_gray_value+1; k++) {
        //         int first_idx = huffman_nodes[k].first_value;
        //         int second_idx = huffman_nodes[k].second_value;
        //         printf("k: %d, codeword: ", k);
        //         for (int j=0; j<strlen(codewords[first_idx]); j++) {
        //             printf("%c",codewords[k][j]);
        //         }
        //         printf("\n");
        //         // printf("i: %d, first: %d, second: %d ,currnode first: %u, currnode second: %u\n",i, first_idx, second_idx, codewords[first_idx][0], codewords[second_idx][0]);
        //     }
        // }



        // printf("i: %d, first: %d, second: %d ,currnode first: %u, currnode second: %u\n",i, first_idx, second_idx, strlen(codewords[first_idx]), strlen(codewords[second_idx]));


    }

    for (int i = 0; i < max_gray_value+1; i++) {
        int first_idx = huffman_nodes[i].first_value;
        int second_idx = huffman_nodes[i].second_value;
        printf("i: %d, codeword: ", i);
        for (int j=0; j<strlen(codewords[first_idx]); j++) {
            printf("%c",codewords[i][j]);
        }
        printf("\n");
        // printf("i: %d, first: %d, second: %d ,currnode first: %u, currnode second: %u\n",i, first_idx, second_idx, codewords[first_idx][0], codewords[second_idx][0]);
    }


    int height = input_pgm_image->height;
    int width = input_pgm_image->width;
    unsigned char *encoded_image_data = (unsigned char*) malloc((height*width)*number_of_nodes*sizeof(unsigned char));

    for (int row = 0; row<height; row++) {
        for (int col = 0; col<width; col++) {
            *encoded_image_data = codewords[input_pgm_image->image[row][col]];
            int length = strlen((char *) codewords[input_pgm_image->image[row][col]]);
            *length_of_encoded_image_array += length;
            // printf("adding codeword of size %d for pixel row: %d, col: %d\n",length,row,col);
            encoded_image_data += length * sizeof(unsigned char);
        }
    }

    for (int i=0; i<(max_gray_value+1); i++) {
        free(codewords[i]);
    }
    free(codewords);

    // unsigned char *encoded_image_data = malloc(*length_of_encoded_image_array * sizeof(unsigned char));

    return encoded_image_data;

}