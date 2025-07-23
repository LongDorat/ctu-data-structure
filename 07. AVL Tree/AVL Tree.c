#include "AVL Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int getMax(int a, int b)
{
    return (a > b) ? a : b;
}

Node *minInorderNode(AVLTree root)
{
    Node* current = root;
    while (current && current->Left)
    {
        current = current->Left;
    }
    return current;
}

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Cannot allocate memory for the new node");
        exit(EXIT_FAILURE);
    }

    newNode->Key = value;
    newNode->Height = 1;
    newNode->Left = NULL;
    newNode->Right = NULL;

    return newNode;
}

int getHeight(AVLTree root)
{
    return root ? root->Height : 0;
}

int getBalance(AVLTree root)
{
    return root ? getHeight(root->Left) - getHeight(root->Right) : 0;
}

void freeTree(AVLTree root)
{
    if (root)
    {
        freeTree(root->Left);
        freeTree(root->Right);
        free(root);
    }
}

AVLTree leftRotate(AVLTree unbalancedNode)
{
    Node *newRoot = unbalancedNode->Right;
    Node *subNode = newRoot->Left;

    newRoot->Left = unbalancedNode;
    unbalancedNode->Right = subNode;

    unbalancedNode->Height = 1 + getMax(getHeight(unbalancedNode->Left), getHeight(unbalancedNode->Right));
    newRoot->Height = 1 + getMax(getHeight(newRoot->Left), getHeight(newRoot->Right));

    return newRoot;
}

AVLTree rightRotate(AVLTree unbalancedNode)
{
    Node *newRoot = unbalancedNode->Left;
    Node *subNode = newRoot->Right;

    newRoot->Right = unbalancedNode;
    unbalancedNode->Left = subNode;

    unbalancedNode->Height = 1 + getMax(getHeight(unbalancedNode->Left), getHeight(unbalancedNode->Right));
    newRoot->Height = 1 + getMax(getHeight(newRoot->Left), getHeight(newRoot->Right));

    return newRoot;
}

AVLTree left_rightRotate(AVLTree unbalancedNode)
{
    unbalancedNode->Left = leftRotate(unbalancedNode->Left);
    return rightRotate(unbalancedNode);
}

AVLTree right_leftRotate(AVLTree unbalancedNode)
{
    unbalancedNode->Right = rightRotate(unbalancedNode->Right);
    return leftRotate(unbalancedNode);
}

AVLTree rebalance(AVLTree root)
{
    int balance = getBalance(root);

    if (balance > 1)
    {
        if (getBalance(root->Left) >= 0)
            return rightRotate(root);
        else
            return left_rightRotate(root);
    }

    if (balance < -1)
    {
        if (getBalance(root->Right) <= 0)
            return leftRotate(root);
        else
            return right_leftRotate(root);
    }

    return root;
}

AVLTree insertNode(int value, AVLTree root)
{
    if (!root)
    {
        return createNode(value);
    }
    else if (value < root->Key)
    {
        root->Left = insertNode(value, root->Left);
    }
    else if (value > root->Key)
    {
        root->Right = insertNode(value, root->Right);
    }
    else
    {
        return root;
    }

    root->Height = 1 + (getMax(getHeight(root->Left), getHeight(root->Right)));

    root = rebalance(root);

    return root;
}

AVLTree deleteNode(int value, AVLTree root)
{
    if (!root)
    {
        return NULL;
    }

    if (value < root->Key)
    {
        root->Left = deleteNode(value, root->Left);
    }
    else if (value > root->Key)
    {
        root->Right = deleteNode(value, root->Right);
    }
    else
    {
        if (!root->Left)
        {
            Node *temp = root->Right;
            free(root);
            return temp;
        }
        else if (!root->Right)
        {
            Node *temp = root->Left;
            free(root);
            return temp;
        }
        else
        {
            Node *minNode = minInorderNode(root->Right);
            root->Key = minNode->Key;
            root->Right = deleteNode(minNode->Key, root->Right);
        }
    }

    root->Height = 1 + getMax(getHeight(root->Left), getHeight(root->Right));

    root = rebalance(root);

    return root;
}