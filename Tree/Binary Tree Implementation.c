#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node *Tree;

Tree createNode(DataType value, Tree left, Tree right)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void printInPreorder(Tree tree)
{
    if (tree == NULL)
        return;

    printf("%c ", tree->data);
    printInPreorder(tree->left);
    printInPreorder(tree->right);
}

void printInInorder(Tree tree)
{
    if (tree == NULL)
        return;

    printInInorder(tree->left);
    printf("%c ", tree->data);
    printInInorder(tree->right);
}

void printInPostorder(Tree tree)
{
    if (tree == NULL)
        return;

    printInPostorder(tree->left);
    printInPostorder(tree->right);
    printf("%c ", tree->data);
}

int main()
{
    Tree tree = createNode('D',
                           createNode('A', NULL, createNode('B', NULL, NULL)),
                           createNode('F', createNode('E', NULL, NULL), NULL));

    printInPreorder(tree);
    printf("\n");
    printInInorder(tree);
    printf("\n");
    printInPostorder(tree);

    return 0;
}
