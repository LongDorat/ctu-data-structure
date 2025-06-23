#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;

Node *new_node()
{
    Node *p = malloc(sizeof(Node));
    p->next = NULL;
    return p;
}

void insert_node(ElementType x, Node *p)
{
    Node *temp = malloc(sizeof(Node));

    temp->data = x;
    temp->next = p->next;
    p->next = temp;
}

void print(Node *p)
{
    Node *temp = p->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
    printf("\n");
}

int get_size(Node *p)
{
    Node *temp = p->next;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

char *get_line()
{
    int bufsize = 100;
    int i = 0;
    char *line = (char *)malloc(bufsize * sizeof(char));
    if (line == NULL)
        return NULL;

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i >= bufsize - 1)
        {
            bufsize *= 2;
            char *new_line = realloc(line, bufsize * sizeof(char));
            if (new_line == NULL)
            {
                free(line);
                return NULL;
            }
            line = new_line;
        }
        line[i++] = (char)c;
    }
    line[i] = '\0';

    // If the line was too long, consume the rest of the input until newline or EOF
    if (c != '\n' && c != EOF)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    return line;
}

int main()
{
    char *nums = get_line();
    if (nums == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    char *token = strtok(nums, " ");
    Node *head = new_node();
    Node *current = head;
    double average = 0;
    while (token != NULL)
    {
        ElementType value = atoi(token);
        if (value == -1)
            break;
        insert_node(value, current);
        current = current->next;
        average += value;
        token = strtok(NULL, " ");
    }
    average /= get_size(head);
    print(head);
    printf("%.3lf", average);

    return 0;
}