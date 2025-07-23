#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node *List;

void insertNode(ElementType x, Node *p, List *L);
void print(const List *L);
void partition(List L, List *L1, List *L2);

int main()
{
    List L = (List)malloc(sizeof(Node));
    List L1 = (List)malloc(sizeof(Node));
    List L2 = (List)malloc(sizeof(Node));

    L->next = NULL;
    L1->next = NULL;
    L2->next = NULL;

    Node *current = L->next;
    for (int i = 0; i < 10; i++)
    {
        insertNode(i, current, &L);
    }

    partition(L, &L1, &L2);

    print(&L);
    print(&L1);
    print(&L2);

    return 0;
}

void insertNode(ElementType x, Node *p, List *L)
{
    Node *newNode = (List)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (p == NULL)
    {
        Node *current = (*L)->next;
        if (current == NULL)
        {
            (*L)->next = newNode;
        }
        else
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    else
    {
        newNode->next = p->next;
        p->next = newNode;
    }
}

void print(const List *L)
{
    Node *current = (*L)->next;

    if (current == NULL)
    {
        printf("\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void partition(List L, List *L1, List *L2)
{
    Node *current = L->next;

    if (current == NULL)
        return;

    if (current->next == NULL)
    {
        insertNode(current->data, NULL, L1);
        return;
    }

    Node *fast = current->next->next;
    while (fast != NULL)
    {
        insertNode(current->data, NULL, L1);
        current = current->next;
        fast = fast->next->next;
    }

    insertNode(current->data, NULL, L1);
    current = current->next;

    while (current != NULL)
    {
        insertNode(current->data, NULL, L2);
        current = current->next;
    }
}