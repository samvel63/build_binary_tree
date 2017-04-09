#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val <= (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int find_max_deep_nodes(node * tree, int deep)
{
    if (!tree)
        return deep - 1;

    return max(find_max_deep_nodes(tree->left, deep + 1), find_max_deep_nodes(tree->right, deep + 1));
}

int print_not_terminal_vertices(node * tree, int cur_deep, int deep)
{
    if (!tree)
        return 1;

    if (cur_deep == deep) {
        printf("Вершина со значением %d является нетерминальной с максимальной глубиной.\n", tree->data);
    } else {
        print_not_terminal_vertices(tree->left, cur_deep + 1, deep);
        print_not_terminal_vertices(tree->right, cur_deep + 1, deep);
    }
    return 0;
}

void delete_node(node ** tree, int val)
{
    if(!tree)
    {
        return;
    }

    if(val < (*tree)->data) {
    	delete_node(&((*tree)->left), val);
    } else if(val > (*tree)->data) {
        delete_node(&((*tree)->right), val);
    } else if(val == (*tree)->data) {
    	free(*tree);
    	*tree = NULL;
    }
}

void print_nodes(node * tree)
{
	if (tree) {
		print_nodes(tree->left);
		printf("%d\n", tree->data);
		print_nodes(tree->right);
	}
}