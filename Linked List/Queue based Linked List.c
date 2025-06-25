#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Node
{
    ElementType data;
    struct Node *next;
};
typedef struct
{
    struct Node *front;
    struct Node *rear;
    int size;
} Queue;

void makenull(Queue *queue)
{
    queue->front = malloc(sizeof(struct Node));
    queue->front->next = NULL;
    queue->rear = queue->front;
    queue->size = 0;
}

int is_empty(const Queue *queue)
{
    return queue->size == 0;
}

void en_queue(ElementType x, Queue *queue)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    queue->rear->next = newNode;
    queue->rear = newNode;
    queue->size++;
}

ElementType front(Queue *queue)
{
    if (is_empty(queue))
    {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return queue->front->next->data;
}