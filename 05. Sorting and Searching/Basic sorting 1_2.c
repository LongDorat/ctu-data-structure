#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct NodeTag
{
    ElementType data;
    struct NodeTag *next;
} Node;

Node *new_node()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = 0;
    newNode->next = NULL;
    return newNode;
}

void print_list(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void read_list(Node *head, int n)
{
    Node *current = head;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new_node();
        scanf("%d", &newNode->data);
        current->next = newNode;
        current = newNode;
    }
    print_list(head);
}

void selection_sort(Node *list, int loopTh)
{
    Node *minNumber = list->next;

    int loopCount = 0;
    while (minNumber != NULL && loopCount < loopTh)
    {
        Node *minNode = minNumber;
        Node *current = minNumber->next;
        while (current != NULL)
        {
            if (minNode->data > current->data)
            {
                minNode = current;
            }
            current = current->next;
        }
        if (minNumber != minNode)
        {
            int temp = minNumber->data;
            minNumber->data = minNode->data;
            minNode->data = temp;
        }

        minNumber = minNumber->next;
        loopCount++;
    }
    print_list(list);
}

int main()
{
    Node *list = new_node();
    read_list(list, 5);
    selection_sort(list, 3);
    free(list);
    return 0;
}