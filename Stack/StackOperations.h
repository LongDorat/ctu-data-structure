#include <stdlib.h>

typedef struct
{
    int *data;      // Pointer to the stack's data
    int top;        // Index of the top element in the stack
    int capacity;   // Maximum number of elements the stack can hold
} Stack;

void makenull(Stack *S)
{
    S->data = NULL; // Initialize data pointer to null
    S->top = -1;       // Set top index to -1 indicating the stack is empty
    S->capacity = 0;   // Set capacity to 0
}

int is_empty(Stack *S)
{
    return S->top == -1; // Return true if top index is -1, indicating the stack is empty
}

int top(Stack *S)
{
    if (is_empty(S)) {
        // Handle error: stack is empty
        return -1; // or throw an exception, or handle as appropriate
    }
    return S->data[S->top]; // Return the top element of the stack
}

void pop(Stack *S)
{
    if (is_empty(S)) {
        // Handle error: stack is empty
        return; // or throw an exception, or handle as appropriate
    }
    S->top--; // Decrease the top index to remove the top element
}

void push(int x, Stack *S)
{
    if (S->top + 1 >= S->capacity) {
        // Handle error: stack is full
        return; // or throw an exception, or handle as appropriate
    }
    if (S->data == NULL) {
        // Allocate memory for the stack data if it hasn't been allocated yet
        S->data = (int*)malloc(S->capacity * sizeof(int));
    }
    S->data[++S->top] = x; // Increment top index and add the new element
}