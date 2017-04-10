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

node * minValueNode(node* tree)
{
    node* current = tree;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

node* deleteNode(node* root, int key)
{
    if (root == NULL) return root;
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
 
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void print_nodes(node * tree)
{
	if (tree) {
		print_nodes(tree->left);
		printf("%d\n", tree->data);
		print_nodes(tree->right);
	}
}