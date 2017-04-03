#include <stdlib.h>
#include <stdio.h>

struct bin_tree {
    int data;
    struct bin_tree * right, * left;
};
typedef struct bin_tree node;

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

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        print_inorder(tree->right);
    }
}


int main(void)
{
    int *list_parent_vertex;
    node *root;


    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;
    while (scanf("%d", &ver) == 1)
        insert(&root, ver);
    
    print_inorder(root);
    return 0;
}
