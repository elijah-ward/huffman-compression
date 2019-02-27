#include "huffman_decode_image.h"

struct treeNode
{
    int value;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode * searchTree(struct treeNode *root, int value) {
    if ( root->value == value ) {
        return root;
    } else {

        if ( root->left != NULL ) {
            struct treeNode *left = searchTree(root->left, value);
            if (left != NULL) {
                return left;
            }
        }
        if ( root->right != NULL ) {
            return searchTree(root->right, value);
        }
    }
    return NULL;
}

void addHuffmanPair(struct node *huffmanNode, struct treeNode *root) {
    struct treeNode *subParentFirst = searchTree(root, huffmanNode->first_value );
    struct treeNode *subParentSecond = searchTree(root, huffmanNode->second_value );

    if (subParentFirst == NULL && subParentSecond == NULL) {
        root->left = huffmanNode->first_value;
        root->right = huffmanNode->second_value;
        root->value = -1;
    }

    struct treeNode *targetNode = subParentFirst ? subParentFirst : subParentSecond;

    struct treeNode newLeftNode = {.value = huffmanNode->first_value };
    struct treeNode newRightNode = {.value = huffmanNode->second_value };

    targetNode->left = &newLeftNode;
    targetNode->right = &newRightNode;
    targetNode->value = -1;
}


struct PGM_Image *huffman_decode_image( int image_width, int image_height, int max_gray_value, int number_of_nodes,
    struct node *huffman_node, long int length_of_encoded_image_array, unsigned char *encoded_image) {

    struct PGM_Image decomp_output_image;

    struct treeNode tree_root;
    tree_root.value = -1;

    for (int i=0;i<number_of_nodes;i++) {
        struct node curr_node = huffman_node[i];
        addHuffmanPair(&curr_node, &tree_root);
    }



}