#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bintree.h"

int main(void)
{
    char s[10];
    int max_deep = 0;

    node *root;

    root = NULL;
    /* Inserting nodes into tree */
    int ver = 0;

    printf("\nДля получения помощи в использовании программы напишите 'help' или 'h'.\n\n");
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "insert") || !strcmp(s, "ins")) {
            //printf("ins\n");
            while (scanf("%d", &ver))
                insert(&root, ver);
        } else if (!strcmp(s, "delete") || !strcmp(s, "del")) {
            node * tmp;
            while (scanf("%d", &ver))
                root = deleteNode(root, ver);
        } else if (!strcmp(s, "quit") || !strcmp(s, "exit") || !strcmp(s, "q")) {
            destroy(root);
            break;
        } else if (!strcmp(s, "run") || !strcmp(s, "r")) {
            max_deep = find_max_deep_nodes(root, 1);
            print_not_terminal_vertices(root, 1, max_deep - 1);
            if (!root)
                printf("В дереве нет вершин.\n");
            else if (!root->right && !root->left)
                printf("В дереве присутствует одна вершина. Этого недостаточно, чтобы найти нетерминальную вершину.\n");
        } else if (!strcmp(s, "print") || !strcmp(s, "p")) {
            if (!root)
                printf("В дереве нет вершин.\n");
            print_nodes(root);
        } else if (!strcmp(s, "help") || !strcmp(s, "h")) {
            printf("\n\nКоманды 'insert num1 num2...' и 'ins num1 num2...' добавляют вершины в дерево.\n\n");
            printf("Команды 'delete' и 'del' удаляет вершины и все вложенные вершины.\n\n");
            printf("Команды 'print' и 'p' печатает вершины дерева.\n\n");
            printf("Команды 'run' и 'r' выводит нетерминальные вершины дерева с максимальной глубиной\n\n");
            printf("Команды 'quit', 'q' и 'exit' заканчивают работу программы.\n\n");
            printf("Команды 'destroy' и 'des' удаляют все дерево.\n\n");
        } else if (!strcmp(s, "destroy") || !strcmp(s, "des")) {
            destroy(root);
            root = NULL;
        }
    }
    
    return 0;
}
