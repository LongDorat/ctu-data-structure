#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FanNode
{
    char *name;
    int reactions;
    struct FanNode *next;
} FanNode;

typedef FanNode *ListOfFan;

FanNode *createFanNode(char *name, int reactions)
{
    FanNode *newNode = (FanNode *)malloc(sizeof(FanNode));

    newNode->name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(newNode->name, name);

    newNode->reactions = reactions;

    newNode->next = NULL;

    return newNode;
}

void insertSorted(ListOfFan *head, char *name, int reactions)
{
    FanNode *newNode = createFanNode(name, reactions);
    
    if (*head == NULL || (*head)->reactions < reactions ||
        ((*head)->reactions == reactions && strcmp((*head)->name, name) > 0))
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    
    FanNode *current = *head;
    while (current->next != NULL &&
           (current->next->reactions > reactions ||
            (current->next->reactions == reactions && strcmp(current->next->name, name) < 0)))
    {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();

    ListOfFan listOfFan = NULL;
    
    for (int i = 0; i < n; i++)
    {
        char *userInput = (char *)malloc(100 * sizeof(char));
        fgets(userInput, 100, stdin);
        userInput[strlen(userInput) - 1] = '\0';

        char *name = NULL;
        int reactions = 0;
        
        char *token = strtok(userInput, " ");
        while (token != NULL)
        {
            if (!sscanf(token, "%d", &reactions))
            {
                name = token;
            }
            token = strtok(NULL, " ");
        }
        
        if (name != NULL)
        {
            insertSorted(&listOfFan, name, reactions);
        }

        free(userInput);
    }
    
    FanNode *current = listOfFan;
    int count = 0;
    while (current != NULL && count < k)
    {
        printf("%s\n", current->name);
        current = current->next;
        count++;
    }

    current = listOfFan;
    while (current != NULL)
    {
        FanNode *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }

    return 0;
}