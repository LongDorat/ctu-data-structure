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