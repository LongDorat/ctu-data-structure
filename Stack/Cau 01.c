#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackOperations.h"

void to_hexa(int numberInDecimal, Stack *S)
{
    int remainder;

    while (numberInDecimal > 0)
    {
        remainder = numberInDecimal % 16;

        push(remainder, S);

        numberInDecimal /= 16;
    }
}

void print(Stack *S)
{
    int hex_num;
    char output[50];
    int outLength = 0;

    while (!is_empty(S))
    {
        hex_num = top(S);
        pop(S);
        if (hex_num > 9)
        {
            output[outLength] = 'A' + (hex_num - 10);
        }
        else
            output[outLength] = '0' + hex_num;
        outLength++;
    }
    
    output[outLength] = '\0';
    printf("%s", output);
}

int main()
{
    Stack S;
    makenull(&S);
    S.capacity = 10;
    S.data = (int *)malloc(S.capacity * sizeof(int));

    int numberInDecimal;
    scanf("%d", &numberInDecimal);

    to_hexa(numberInDecimal, &S);

    print(&S);

    free(S.data);

    return 0;
}