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

void find_parent_vertex(node **tree, int val, int *list_parent_vertex, int *a)
{
    if (((*tree)->right && (*tree)->right->data == val) || ((*tree)->left && (*tree)->left->data == val)) {
            list_parent_vertex = (int*)realloc(list_parent_vertex, (*a + 1) * sizeof(int));
            list_parent_vertex[*a] = (*tree)->data;
            ++*a;
        
    } else if(val > (*tree)->data) {
        find_parent_vertex(&((*tree)->right), val, &list_parent_vertex[0], a);
    } else if (val < (*tree)->data) {
        find_parent_vertex(&((*tree)->left), val, &list_parent_vertex[0], a);
    } 
}

void find_terminal_vertex(node **tree, node **root, int *list_parent_vertex, int *a) {
    if (!((*tree)->right) && !((*tree)->left)) {
        find_parent_vertex(&(*root), (*tree)->data, &list_parent_vertex[0], a);
    }

    if ((*tree)->right)
        find_terminal_vertex(&((*tree)->right), &(*root), &list_parent_vertex[0], a);
    if ((*tree)->left)
        find_terminal_vertex(&((*tree)->left), &(*root), &list_parent_vertex[0], a);
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
    int n = 0;
    int *list_parent_vertex;
    node *root;

    list_parent_vertex = (int *) malloc (sizeof(int));
    
    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;
    while (scanf("%d", &ver) == 1)
        insert(&root, ver);

    find_terminal_vertex(&root, &root, &list_parent_vertex[0], &n);
    //find_parent_vertex(&root, 11, &list_parent_vertex[0]);

    for (int i = 0; i < n; ++i) {
        if (list_parent_vertex[i] != NULL)
            printf("%d\n", list_parent_vertex[i]);
    }
    printf("%d\n", n);
    free(list_parent_vertex);
    //print_inorder(root);
    return 0;
}
