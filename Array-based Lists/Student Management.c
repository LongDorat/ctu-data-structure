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

char *str_dup(char *str)
{
    int len = strlen(str);
    if (len == 0)
        return NULL;

    char *new_str = (char *)malloc((len + 1) * sizeof(char));
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

        // Getting the ID, theory score, and lab score
        sscanf(buffer, "%d %lf %lf",
               &pL->list[pL->size].id,
               &pL->list[pL->size].theory_score,
               &pL->list[pL->size].lab_score);
        
        // Allocate memory for the name
        pL->list[pL->size].name = (char *)malloc(100 * sizeof(char));
        if (pL->list[pL->size].name == NULL)
        {
            printf("Memory allocation failed.\n");
            free(buffer);
            return;
        }

        // Extracting the name from the buffer
        // Assuming the name is the rest of the line after the ID, theory score, and lab score
        char *name_part = strtok(buffer, " ");
        char *first_name = NULL, *last_name = NULL;
        int dumpster; // Variable to hold the integer part of the buffer
        while (name_part != NULL)
        {
            if (sscanf(name_part, "%d", &dumpster) != 1)
            {
                if (first_name == NULL)
                {
                    first_name = str_dup(name_part);
                }
                else
                {
                    last_name = str_dup(name_part);
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
        free(name_part);
        free(first_name);
        free(last_name);

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