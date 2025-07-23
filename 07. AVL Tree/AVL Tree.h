#include <stdlib.h>

#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef int KeyType;
typedef struct Node
{
    KeyType Key;
    struct Node* Left;
    struct Node* Right;
    int Height;
}Node;
typedef Node* AVLTree;

int getMax(int a, int b);
Node* minInorderNode(AVLTree root);

Node* createNode(int value);
int getHeight(AVLTree root);
int getBalance(AVLTree root);
void freeTree(AVLTree root);

AVLTree leftRotate(AVLTree unbalancedNode);
AVLTree rightRotate(AVLTree unbalancedNode);
AVLTree left_rightRotate(AVLTree unbalancedNode);
AVLTree right_leftRotate(AVLTree unbalancedNode);

AVLTree rebalance(AVLTree root);
AVLTree insertNode(int value, AVLTree root);
AVLTree deleteNode(int value, AVLTree root);

#endif