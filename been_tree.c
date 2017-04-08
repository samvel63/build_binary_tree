#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int print_not_terminal_vertices(node *tree, int cur_deep, int deep)
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

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

void search(node ** tree, int val)
{
    if(!(*tree))
    {
        return;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        deltree(*tree);
    }
}

int main(void)
{
    char s[10];
    int max_deep = 0;

    node *root;

    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "insert")) {
            //printf("ins\n");
            while (scanf("%d", &ver))
                insert(&root, ver);
        } else if (!strcmp(s, "delete")) {
            //printf("del\n");
            while (scanf("%d", &ver))
                search(&root, ver);
        } else if (!strcmp(s, "quit") || !strcmp(s, "exit") ) {
            break;
        } else if (!strcmp(s, "run")) {
            max_deep = find_max_deep_nodes(root, 1);
            if (print_not_terminal_vertices(root, 1, max_deep - 1) == 1)
                printf("В дереве нет вершин.\n");
            }
    }
    

    return 0;
}
