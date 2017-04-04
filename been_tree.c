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

void find_parent_vertex(node **tree, int val, int *list_parent_vertices, int *a)
{
    if (((*tree)->right && (*tree)->right->data == val) || ((*tree)->left && (*tree)->left->data == val)) {
            list_parent_vertices = (int*)realloc(list_parent_vertices, (*a + 1) * sizeof(int));
            list_parent_vertices[*a] = (*tree)->data;
            ++*a;
        
    } else if(val > (*tree)->data) {
        find_parent_vertex(&((*tree)->right), val, &list_parent_vertices[0], a);
    } else if (val < (*tree)->data) {
        find_parent_vertex(&((*tree)->left), val, &list_parent_vertices[0], a);
    } 
}

void find_terminal_vertex(node **tree, node **root, int *list_parent_vertices, int *a) {
    if (!((*tree)->right) && !((*tree)->left)) {
        find_parent_vertex(&(*root), (*tree)->data, &list_parent_vertices[0], a);
    }

    if ((*tree)->right)
        find_terminal_vertex(&((*tree)->right), &(*root), &list_parent_vertices[0], a);
    if ((*tree)->left)
        find_terminal_vertex(&((*tree)->left), &(*root), &list_parent_vertices[0], a);
}

int find_deep_vertex(node **tree, int ver, int deep)
{
    if ((*tree)->data == ver)
        return deep;
    if ((*tree)->data > ver)
        return find_deep_vertex(&((*tree)->left), ver, deep + 1);
    if ((*tree)->data < ver)
        return find_deep_vertex(&((*tree)->right), ver, deep + 1);
}

void print_max_deep_vertex(int deep, int *list1, int *list2)
{
    while (deep != *list1) {
        *list1++;
        *list2++;       
    }

    printf("Максимально глубокая нетерминальная вершина со значенем %d\n", *list2);
}


int main(void)
{
    int cap_not_terminal_vertex = 0, max_deep = 0;
    int *list_parent_vertices;
    node *root;

    list_parent_vertices = (int *) malloc (sizeof(int));
    
    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;
    while (scanf("%d", &ver) == 1)
        insert(&root, ver);

    find_terminal_vertex(&root, &root, &list_parent_vertices[0], &cap_not_terminal_vertex);
    int list_deep_vertices[cap_not_terminal_vertex];

    for (int i = 0; i < cap_not_terminal_vertex; ++i) {
        list_deep_vertices[i] = find_deep_vertex(&root, list_parent_vertices[i], 0);
        max_deep = max(max_deep, list_deep_vertices[i]);
       // printf("%d %d\n", list_parent_vertices[i], list_deep_vertices[i]);
    }
    print_max_deep_vertex(max_deep, &list_deep_vertices[0], &list_parent_vertices[0]);
    free(list_parent_vertices);

    return 0;
}
