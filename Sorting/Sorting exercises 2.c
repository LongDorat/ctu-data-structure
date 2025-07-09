#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FanTag
{
    char *name;
    int reactions;
} Fan;

typedef Fan *ListOfFan;

void insertionSort(ListOfFan *nums, int numsSize)
{
    for (int i = 1; i < numsSize; i++)
    {
        char *keyName = (*nums)[i].name;
        int keyReactions = (*nums)[i].reactions;

        int j = i - 1;
        while (j >= 0 && ((*nums)[j].reactions > keyReactions ||
                          ((*nums)[j].reactions == keyReactions &&
                           strcmp((*nums)[j].name, keyName) < 0)))
        {
            (*nums)[j + 1].name = (*nums)[j].name;
            (*nums)[j + 1].reactions = (*nums)[j].reactions;
            j--;
        }

        (*nums)[j + 1].name = keyName;
        (*nums)[j + 1].reactions = keyReactions;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    getchar();

    ListOfFan listOfFan = (Fan *)malloc(n * sizeof(Fan));
    for (int i = 0; i < n; i++)
    {
        char *userInput = (char *)malloc(100 * sizeof(char));
        fgets(userInput, 100, stdin);
        userInput[strlen(userInput) - 1] = '\0';

        char *segment = strtok(userInput, " ");
        while (segment != NULL)
        {
            if (!sscanf(segment, "%d", &listOfFan[i].reactions))
            {
                listOfFan[i].name = (char *)malloc((strlen(segment) + 1) * sizeof(char));
                strcpy(listOfFan[i].name, segment);
            }
            segment = strtok(NULL, " ");
        }

        free(userInput);
    }

    insertionSort(&listOfFan, n);

    for (int i = n - 1; i > n - k - 1; i--)
    {
        printf("%s\n", listOfFan[i].name);
    }

    return 0;
}