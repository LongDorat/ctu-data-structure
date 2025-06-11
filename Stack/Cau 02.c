#include <stdio.h>
#include <stdlib.h>
#include "StackOperations.h"

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // For '(' or any other character
}

void to_postfix(char *inFix, char *postFix)
{
    Stack stack;
    makenull(&stack);
    stack.capacity = 100; // Set initial capacity for the stack
    stack.data = (int *)malloc(stack.capacity * sizeof(int));

    int i = 0, j = 0;
    while (inFix[i] != '\0')
    {
        if (inFix[i] >= '0' && inFix[i] <= '9')
        {
            postFix[j++] = inFix[i]; // If it's an operand, add it to postfix
        }
        else if (inFix[i] == '(')
        {
            push(inFix[i], &stack); // If it's '(', push to stack
        }
        else if (inFix[i] == ')')
        {
            while (!is_empty(&stack) && top(&stack) != '(')
            {
                postFix[j++] = top(&stack); // Pop from stack until '(' is found
                pop(&stack);
            }
            pop(&stack); // Pop the '(' from the stack
        }
        else
        { // Operator case
            while (!is_empty(&stack) && precedence(top(&stack)) >= precedence(inFix[i]))
            {
                postFix[j++] = top(&stack); // Pop operators from stack
                pop(&stack);
            }
            push(inFix[i], &stack); // Push the current operator onto the stack
        }
        i++;
    }

    while (!is_empty(&stack))
    {
        postFix[j++] = top(&stack); // Pop all remaining operators from the stack
        pop(&stack);
    }

    postFix[j] = '\0'; // Null-terminate the postfix expression

    free(stack.data); // Free the allocated memory for stack data
}

int main()
{
    char *inFix = (char *)malloc(100 * sizeof(char));
    scanf("%99s", inFix);
    inFix[99] = '\0'; // Ensure null termination
    char *postFix = (char *)malloc(100 * sizeof(char));

    to_postfix(inFix, postFix);

    printf("%s\n", postFix);

    free(inFix);
    free(postFix);

    return 0;
}