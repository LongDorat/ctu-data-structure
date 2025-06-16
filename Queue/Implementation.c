#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int *data;
    int rear, front;
} Queue;

void InitializeQueue(Queue *queue)
{
    queue->data = (int *)malloc(100 * sizeof(int));
    queue->rear = 100;
    queue->front = 100;
}

int dequeue(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        return 0; // Queue is empty or improperly used
    }

    queue->front--;
    return queue->data[queue->front];
}

int enqueue(Queue *queue, int value)
{
    if (queue->rear == 0)
    {
        return 0;
    }
    queue->rear--;
    queue->data[queue->rear] = value;
    return 1;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

int isQueueFull(Queue *queue)
{
    return queue->rear == 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character after reading n

    char userInputs[100][5];
    for (int i = 0; i < n; i++)
    {
        fgets(userInputs[i], sizeof(userInputs[i]), stdin);
        userInputs[i][strlen(userInputs[i]) - 1] = '\0'; // Remove newline character
    }

    Queue queue;
    InitializeQueue(&queue);

    for (int i = 0; i < n; i++)
    {
        if (userInputs[i][0] == 'D')
        {
            int value, size;
            if (isQueueEmpty(&queue))
            {
                value = -1;
                size = 0;
            }
            else
            {
                value = dequeue(&queue);
                size = queue.front - queue.rear;
            }
            printf("%d %d\n", value, size);
        }
        else if (userInputs[i][0] == 'E')
        {
            int value;
            if (isQueueFull(&queue))
            {
                value = -1;
            }
            else
            {
                sscanf(userInputs[i] + 2, "%d", &value);
                enqueue(&queue, value);
                int size = queue.front - queue.rear;
                printf("%d\n", size);
            }
        }
    }

    // Free allocated memory
    free(queue.data);

    return 0;
}