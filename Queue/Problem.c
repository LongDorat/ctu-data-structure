#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LENGTH 100
typedef struct ProblemTag
{
    int operand1, operand2;
    char op;
    int ans;
} Problem;

typedef struct QueueTag
{
    Problem elements[MAX_LENGTH];
    int front, rear;
} Queue;

void InitializeQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

int isQueueEmpty(Queue *queue)
{
    return queue->front == queue->rear;
}

int isQueueFull(Queue *queue)
{
    return queue->rear == MAX_LENGTH;
}

int enqueue(Queue *queue, Problem problem)
{
    if (isQueueFull(queue))
    {
        return 0;
    }
    queue->elements[queue->rear++] = problem;
    return 1;
}

Problem dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        Problem emptyProblem = {0, 0, '\0', 0};
        return emptyProblem;
    }
    return queue->elements[queue->front++];
}

Problem createRandomProblem()
{
    Problem problem;
    srand(time(NULL));
    problem.operand1 = rand() % 100;
    problem.operand2 = rand() % 100;
    int opIndex = rand() % 4;
    switch (opIndex)
    {
    case 0:
        problem.op = '+';
        problem.ans = problem.operand1 + problem.operand2;
        break;
    case 1:
        problem.op = '-';
        problem.ans = problem.operand1 - problem.operand2;
        break;
    case 2:
        problem.op = '*';
        problem.ans = problem.operand1 * problem.operand2;
        break;
    case 3:
        problem.op = '/';
        if (problem.operand2 == 0)
            problem.operand2 = 1;
        problem.ans = problem.operand1 / problem.operand2;
        break;
    }
    return problem;
}

int main()
{
    int n;
    while (true)
    {
        printf("Enter the number of problems (1-100): ");
        scanf("%d", &n);
        if (n >= 1 && n <= 100)
            break;
        else
            printf("Invalid input. Please enter a number between 1 and 100.\n");
    }

    Queue queue;
    InitializeQueue(&queue);

    int mark = 0;
    Problem problem;
    int userAnswer;
    for (int i = 0; i < n; i++)
    {
        problem = createRandomProblem();
        printf("Problem %d: %d %c %d = ?\n", i + 1, problem.operand1, problem.op, problem.operand2);
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == problem.ans)
        {
            printf("Correct!\n");
            mark++;
        }
        else
        {
            printf("Incorrect!\n");
            enqueue(&queue, problem);
        }
    }

    while (!isQueueEmpty(&queue))
    {
        Problem p = dequeue(&queue);
        printf("Retry Problem: %d %c %d = ?\n", p.operand1, p.op, p.operand2);
        printf("Enter your answer: ");
        scanf("%d", &userAnswer);

        if (userAnswer == p.ans)
        {
            printf("Correct!\n");
            mark++;
        }
        else
        {
            printf("Incorrect again! The correct answer is %d.\n", p.ans);
        }
    }

    printf("You answered %d out of %d problems correctly.\n", mark, n);
    return 0;
}