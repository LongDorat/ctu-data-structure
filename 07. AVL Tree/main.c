#include "AVL Tree.h"
#include <stdlib.h>
#include <stdio.h>

void visualize(AVLTree root, int level);

int main()
{
    AVLTree tree = NULL;

    // Insert nodes
    tree = insertNode(10, tree);
    tree = insertNode(20, tree);
    tree = insertNode(30, tree);
    tree = insertNode(40, tree);
    tree = insertNode(50, tree);
    tree = insertNode(25, tree);

    // Visualize the AVL Tree
    printf("AVL Tree structure:\n");
    visualize(tree, 0);
    printf("\n");

    // Delete a node
    tree = deleteNode(30, tree);

    printf("AVL Tree after deleting 30:\n");
    visualize(tree, 0);
    printf("\n");

    // Free the AVL Tree
    freeTree(tree);

    printf("AVL Tree operations completed successfully.\n");

    return 0;
}

void visualize(AVLTree root, int level)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        printf("   ");
    printf("Level %d: %d (Height: %d)\n", level, root->Key, root->Height);
    visualize(root->Left, level + 1);
    visualize(root->Right, level + 1);
}