#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char *name;
    double theory_score, lab_score, final_score;
} Student;

typedef struct
{
    Student list[40];
    int size;
} List;

char *str_dub(char *str)
{
    int len = 0;
    while (str[len] != '\0')
        len++;

    char *new_str = (char *)malloc((2 * len + 1) * sizeof(char));
    if (new_str == NULL)
        return NULL;

    for (int i = 0; i < len; i++)
    {
        new_str[i] = str[i];
    }
    new_str[len] = '\0';

    return new_str;
}

char *get_line()
{
    char *line = (char *)malloc(100 * sizeof(char));
    if (line == NULL)
        return NULL;

    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        line[i++] = c;
        if (i >= 100) // Prevent buffer overflow
            break;
    }
    line[i] = '\0';

    return line;
}

void readList(List *pL)
{
    int n;
    scanf("%d", &n);
    getchar();

    pL->size = 0;
    for (int i = 0; i < n; i++)
    {
        char *buffer = get_line();
        if (buffer == NULL)
        {
            printf("Error reading input.\n");
            return;
        }

        sscanf(buffer, "%d %lf %lf",
               &pL->list[pL->size].id,
               &pL->list[pL->size].theory_score,
               &pL->list[pL->size].lab_score);

        pL->list[pL->size].name = (char *)malloc(100 * sizeof(char));
        char *name_part = strtok(buffer, " ");
        char *first_name = NULL, *last_name = NULL;
        int dumpID;
        while (name_part != NULL)
        {
            if (sscanf(name_part, "%d", &dumpID) != 1)
            {
                if (first_name == NULL)
                {
                    first_name = str_dub(name_part);
                }
                else
                {
                    last_name = str_dub(name_part);
                    if (last_name != NULL)
                    {
                        snprintf(pL->list[pL->size].name, 100, "%s %s", first_name, last_name);
                        free(last_name);
                    }
                    free(first_name);
                }
            }
            name_part = strtok(NULL, " ");
        }

        pL->size++;
        free(buffer);
    }
}

void print(List *pL)
{
    for (int i = 0; i < pL->size; i++)
    {
        printf("%d\t%s\t%lf\t%lf\t%lf\n",
               pL->list[i].id, pL->list[i].name,
               pL->list[i].theory_score,
               pL->list[i].lab_score,
               pL->list[i].final_score);
    }
}

void printHighestScore(List *pL)
{
    int HighestScoreCount = 0;
    List HighestScoreList;
    HighestScoreList.size = 0;

    double HighestScore = 0;
    for (int i = 0; i < pL->size; i++)
    {
        if (pL->list[i].final_score > HighestScore)
        {
            HighestScoreList.size = 0;
            HighestScoreList.list[HighestScoreList.size++] = pL->list[i];
            HighestScoreCount = 1;
            HighestScore = pL->list[i].final_score;
        }
        else if (pL->list[i].final_score == HighestScore)
        {
            HighestScoreList.list[HighestScoreList.size++] = pL->list[i];
            HighestScoreCount++;
        }
    }

    for (int i = 0; i < HighestScoreList.size; i++)
    {
        printf("%d\t%s\t%lf\t%lf\t%lf\n", HighestScoreList.list[i].id, HighestScoreList.list[i].name, HighestScoreList.list[i].theory_score, HighestScoreList.list[i].lab_score, HighestScoreList.list[i].final_score);
    }
    printf("There are %d students received %lf", HighestScoreCount, HighestScoreList.list[0].final_score);
}
void printAverageScore(List *pL)
{
    double averageTheory = 0;
    double averageLab = 0;
    double averageFinal = 0;

    for (int i = 0; i < pL->size; i++)
    {
        averageTheory += pL->list[i].theory_score;
        averageLab += pL->list[i].lab_score;
        averageFinal += pL->list[i].final_score;
    }

    averageTheory /= pL->size;
    averageLab /= pL->size;
    averageFinal /= pL->size;

    printf("%lf\t%lf\t%lf", averageTheory, averageLab, averageFinal);
}

int main()
{
    List studentList;
    readList(&studentList);

    for (int i = 0; i < studentList.size; i++)
    {
        studentList.list[i].final_score =
            (studentList.list[i].theory_score + studentList.list[i].lab_score) / 2;
    }

    printf("\n");
    print(&studentList);
    printf("\n");
    printHighestScore(&studentList);
    printf("\n\n");
    printAverageScore(&studentList);

    // Free allocated memory
    for (int i = 0; i < studentList.size; i++)
    {
        free(studentList.list[i].name);
    }

    return 0;
}