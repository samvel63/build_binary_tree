#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef struct bin_tree {
    int data;
    struct bin_tree * right, * left;
} node;

void insert(node ** tree, int val);
node * minValueNode(node* node);
node* deleteNode(node* root, int key);

int find_max_deep_nodes(node *tree, int deep);
int print_not_terminal_vertices(node *tree, int cur_deep, int deep);
void print_nodes(node * tree);

#endif