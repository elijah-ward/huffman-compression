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
            treeNode left = searchParent(root->left, value);
            if (left) {
                return left;
            }
        }
        if ( root->right != NULL ) {
            return searchParent(root->right, value);
        }
    }
    return NULL;
}

struct treeNode construct_huffman_tree(struct treeNode *root, struct node *nodes, number_of_nodes) {
    if(root.value == -1) {
        struct treeNode left_node;
        struct treeNode right_node;
        left_node.value = nodes[0].first_value;
        right_node.value = nodes[0].second_value;

        root->left = &left_node;
        root->right = &right_node;
    } else {

    }
}

void addHuffmanPair(struct node *huffmanNode, struct treeNode *root) {
    struct treeNode *subParentFirst = searchTree(root, node->first_value );
    struct treeNode *subParentSecond = searchTree(root, node->second_value );

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

    tree_root = struct treeNode;
    tree_root.value = -1;

    for (int i=0;i<number_of_nodes;i++) {
        struct node curr_node = huffman_node[i];
        addHuffmanPair(&curr_node, tree_root);
    }



}