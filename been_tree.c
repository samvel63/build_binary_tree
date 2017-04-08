#include <stdlib.h>
#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

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

int find_max_deep_nodes(node *tree, int deep)
{
    if (!tree)
        return deep - 1;

    return max(find_max_deep_nodes(tree->left, deep + 1), find_max_deep_nodes(tree->right, deep + 1));
}

void print_not_terminal_vertices(node *tree, int cur_deep, int deep)
{
    if (!tree)
        return 0;

    if (cur_deep == deep) {
        printf("Вершина со значением %d является нетерминальной с максимальной глубиной.\n", tree->data);
    } else {
        print_not_terminal_vertices(tree->left, cur_deep + 1, deep);
        print_not_terminal_vertices(tree->right, cur_deep + 1, deep);
    }
}

int main(void)
{
    int max_deep = 0;

    node *root;

    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;
    while (scanf("%d", &ver) == 1)
        insert(&root, ver);
    max_deep = find_max_deep_nodes(root, 1);
    print_not_terminal_vertices(root, 1, max_deep);
    printf("%d\n", max_deep);
    return 0;
}
