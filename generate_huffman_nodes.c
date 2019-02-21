#include "generate_huffman_nodes.h"

#define MAX_GRAY 255

struct node *generate_huffman_nodes(long int *pixel_frequency, int max_gray_value, int number_of_non_zero_values_in_the_frequency_array) {

    int n_pairs = number_of_non_zero_values_in_the_frequency_array -1;
    struct node *huffman_node_arr = (struct node*) malloc((n_pairs+1) * sizeof(struct node));
    int huffman_arr_idx = 0;

    while (n_pairs > 0) {
        int greatest_freq_idx = 0;
        int second_greatest_freq_idx = 0;

        //find the greatest freq in the frequency array
        for (int i=0; i < MAX_GRAY + 1; i++) {
            if (pixel_frequency[i] > pixel_frequency[greatest_freq_idx]) {
                greatest_freq_idx = i;
            }
        }

        //find the second greatest freq in the frequency array
        for (int i=0; i < MAX_GRAY + 1; i++) {
            if (pixel_frequency[i] > pixel_frequency[second_greatest_freq_idx] && i != greatest_freq_idx) {
                second_greatest_freq_idx = i;
            }
        }

        struct node huffman_pair;
        huffman_pair.first_value = greatest_freq_idx;
        huffman_pair.second_value = second_greatest_freq_idx;

        huffman_node_arr[huffman_arr_idx] = huffman_pair;
        huffman_arr_idx++;

        pixel_frequency[greatest_freq_idx] = pixel_frequency[greatest_freq_idx] + pixel_frequency[second_greatest_freq_idx];
        pixel_frequency[second_greatest_freq_idx] = 0;
    }

    return huffman_node_arr;
}