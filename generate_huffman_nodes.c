#include "generate_huffman_nodes.h"

#define MAX_GRAY 255

struct node *generate_huffman_nodes(long int *pixel_frequency, int max_gray_value, int number_of_non_zero_values_in_the_frequency_array) {

    int n_pairs = number_of_non_zero_values_in_the_frequency_array;
    struct node *huffman_node_arr = (struct node*) malloc((n_pairs) * sizeof(struct node));
    int huffman_arr_idx = n_pairs - 1;

    int least_freq_idx = 0;
    int second_least_freq_idx = 0;

    while (huffman_arr_idx > 0) {

        // printf("huffman pair: %d\n", huffman_arr_idx);

        least_freq_idx = 0;
        second_least_freq_idx = 0;


        while ( pixel_frequency[least_freq_idx] == 0 ) {
            least_freq_idx++;
        }

        // printf("least_freq is now: %d, second_least_freq: %d\n", least_freq_idx, second_least_freq_idx);

        //find the least freq in the frequency array
        for (int i=0; i <= MAX_GRAY ; i++) {
            if ( pixel_frequency[i] != 0 && pixel_frequency[i] <= pixel_frequency[least_freq_idx]) {
                least_freq_idx = i;
            }
        }


        while (pixel_frequency[second_least_freq_idx] == 0 || least_freq_idx == second_least_freq_idx) {
            second_least_freq_idx = pixel_frequency[second_least_freq_idx] == 0 ? second_least_freq_idx + 1 : second_least_freq_idx;
            second_least_freq_idx = least_freq_idx == second_least_freq_idx ? second_least_freq_idx + 1 : second_least_freq_idx;
        }

        //find the second least freq in the frequency array
        for (int i=0; i <= MAX_GRAY ; i++) {
            if ( pixel_frequency[i] != 0 && pixel_frequency[i] <= pixel_frequency[second_least_freq_idx] && i != least_freq_idx) {
                second_least_freq_idx = i;
            }
        }

        struct node huffman_pair;


        huffman_pair.first_value = least_freq_idx;
        huffman_pair.second_value = second_least_freq_idx;

        huffman_node_arr[huffman_arr_idx] = huffman_pair;
        huffman_arr_idx--;

        if (least_freq_idx < second_least_freq_idx) {
            pixel_frequency[least_freq_idx] = pixel_frequency[least_freq_idx] + pixel_frequency[second_least_freq_idx];
            pixel_frequency[second_least_freq_idx] = 0;
        } else {
            pixel_frequency[least_freq_idx] = 0;
            pixel_frequency[second_least_freq_idx] = pixel_frequency[least_freq_idx] + pixel_frequency[second_least_freq_idx];
        }

    }

    return huffman_node_arr;
}