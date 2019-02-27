#include "generate_huffman_nodes.h"

struct node *generate_huffman_nodes(long int *pixel_frequency, int max_gray_value, int number_of_non_zero_values_in_the_frequency_array) {

    for (int i=0; i<=max_gray_value; i++) {
        printf("freq of pixelvalue %d : %d\n", i, pixel_frequency[i]);
    }

    int n_pairs = number_of_non_zero_values_in_the_frequency_array - 1;
    struct node *huffman_node_arr = (struct node*) malloc((n_pairs) * sizeof(struct node));
    int huffman_arr_idx = n_pairs - 1;

    int least_freq_idx = 0;
    int second_least_freq_idx = 0;
    int last_freq = 0;

    while (!last_freq) {

        least_freq_idx = 0;
        second_least_freq_idx = 0;

        //Move least_freq_idx off of 0 values to initialize least non-zero
        while ( pixel_frequency[least_freq_idx] == 0 ) {
            least_freq_idx++;
        }


        //Find the true least freq in the frequency array
        for (int i=0; i <= max_gray_value ; i++) {
            if ( pixel_frequency[i] != 0 && pixel_frequency[i] <= pixel_frequency[least_freq_idx]) {
                least_freq_idx = i;
            }
        }

        //Move second_least_freq_idx off of 0 values or idx equal to least to initialize least non-zero
        while (pixel_frequency[second_least_freq_idx] == 0 || least_freq_idx == second_least_freq_idx) {
            second_least_freq_idx = pixel_frequency[second_least_freq_idx] == 0 ? second_least_freq_idx + 1 : second_least_freq_idx;
            second_least_freq_idx = least_freq_idx == second_least_freq_idx ? second_least_freq_idx + 1 : second_least_freq_idx;
        }

        //Find the true second least freq in the frequency array
        for (int i=0; i <= max_gray_value ; i++) {
            if ( pixel_frequency[i] != 0 && pixel_frequency[i] <= pixel_frequency[second_least_freq_idx] && i != least_freq_idx) {
                second_least_freq_idx = i;
            }
        }

        struct node *huffman_pair = malloc(sizeof(struct node));

        printf("leastidx: %d and val: %d, secondleastidx: %d and val: %d\n", least_freq_idx, pixel_frequency[least_freq_idx], second_least_freq_idx, pixel_frequency[second_least_freq_idx]);

        //Ensure we are consistently maintaining lesser index on the first_value for consistency
        huffman_pair->first_value = least_freq_idx < second_least_freq_idx ? least_freq_idx : second_least_freq_idx;
        huffman_pair->second_value = least_freq_idx < second_least_freq_idx ? second_least_freq_idx : least_freq_idx;
        huffman_node_arr[huffman_arr_idx] = *huffman_pair;
        huffman_arr_idx--;

        // Ensure we are summing to the lowest index in the array and zeroing out the higher
        if (least_freq_idx < second_least_freq_idx) {
            pixel_frequency[least_freq_idx] = pixel_frequency[least_freq_idx] + pixel_frequency[second_least_freq_idx];
            pixel_frequency[second_least_freq_idx] = 0;
        } else {
            pixel_frequency[least_freq_idx] = 0;
            pixel_frequency[second_least_freq_idx] = pixel_frequency[least_freq_idx] + pixel_frequency[second_least_freq_idx];
        }

        int remaining_freqs = 0;

        for (int i=0;i<=max_gray_value;i++) {
            if (pixel_frequency[i] != 0) {
                remaining_freqs++;
            }
        }
        printf("%d frequencies remain\n",remaining_freqs);

        if (remaining_freqs<=1) {
            last_freq = 1;
        }

    }

    // for ( int i=0;i<n_pairs; i++) {
    //     printf("node at i=%d - first:%d, second:%d\n", i, huffman_node_arr[i].first_value, huffman_node_arr[i].second_value);
    // }
    free(pixel_frequency);
    return huffman_node_arr;
}