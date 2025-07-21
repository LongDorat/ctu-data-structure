#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{
    KeyType key;
    struct Node *left;
    struct Node *right;
};
typedef struct Node *Tree;

Tree init_tree()
{
    Tree newTree = NULL;
    return newTree;
}

int is_empty(Tree tree)
{
    if (tree == NULL)
        return 1;
    return 0;
}

void pre_order(Tree tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->key);
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void in_order(Tree tree)
{
    if (tree != NULL)
    {
        in_order(tree->left);
        printf("%d ", tree->key);
        in_order(tree->right);
    }
}

void post_order(Tree tree)
{
    if (tree != NULL)
    {
        in_order(tree->left);
        in_order(tree->right);
        printf("%d ", tree->key);
    }
}

Tree insert_node(KeyType value, Tree tree)
{
    if (tree == NULL)
    {
        Tree newNode = (Tree)malloc(sizeof(struct Node));
        newNode->key = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < tree->key)
    {
        tree->left = insert_node(value, tree->left);
    }
    else if (value > tree->key)
    {
        tree->right = insert_node(value, tree->right);
    }
    return tree;
}

Tree search(int value, Tree tree)
{
    if (tree == NULL)
        return NULL;

    if (tree->key == value)
        return tree;
    else if (value < tree->key)
        return search(value, tree->left);
    else
        return search(value, tree->right);
}

Tree get_parent(int value, Tree tree)
{
    if (tree == NULL)
        return NULL;

    if ((tree->left != NULL && tree->left->key == value) ||
        (tree->right != NULL && tree->right->key == value))
        return tree;

    if (value < tree->key)
        return get_parent(value, tree->left);
    else
        return get_parent(value, tree->right);
}

Tree right_sibling(int value, Tree tree)
{
    if (tree == NULL)
        return NULL;

    if ((tree->left != NULL && tree->left->key == value) && tree->right != NULL)
        return tree->right;
    else
        return NULL;

    if (value < tree->key)
        return right_sibling(value, tree->left);
    else
        return right_sibling(value, tree->right);
}

void print_path(int value, Tree tree)
{
    if (tree == NULL)
    {
        printf(" --> Tim khong thay");
        return;
    }

    if (tree->key == value)
    {
        printf("%d  --> Tim thay", tree->key);
        return;
    }

    if (value < tree->key)
    {
        printf("%d ", tree->key);
        print_path(value, tree->left);
    }
    else
    {
        printf("%d ", tree->key);
        print_path(value, tree->right);
    }
}

Tree delete_node(int value, Tree tree)
{
    if (tree == NULL)
        return NULL;

    if (value < tree->key)
    {
        tree->left = delete_node(value, tree->left);
    }
    else if (value > tree->key)
    {
        tree->right = delete_node(value, tree->right);
    }
    else
    {
        if (tree->left == NULL)
        {
            Tree temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->right == NULL)
        {
            Tree temp = tree->left;
            free(tree);
            return temp;
        }
        else
        {
            Tree minNode = tree->right;
            while (minNode->left != NULL)
                minNode = minNode->left;

            tree->key = minNode->key;

            tree->right = delete_node(minNode->key, tree->right);
        }
    }
    return tree;
}

int main()
{
    Tree T = NULL;

    int x;

    T = insert_node(27, T);
    T = insert_node(12, T);
    T = insert_node(40, T);
    T = insert_node(4, T);
    T = insert_node(20, T);
    T = insert_node(34, T);
    T = insert_node(30, T);
    T = insert_node(50, T);
    x = 12;

    T = delete_node(x, T);
    in_order(T);
}