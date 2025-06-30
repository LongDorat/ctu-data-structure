#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char Data;
    struct Node *Next;
};
typedef struct Node *Line;

void makenull(Line *L)
{
    *L = (Line)realloc(NULL, sizeof(struct Node));
    (*L)->Next = NULL;
}

void print(const Line *L)
{
    struct Node *current = (*L)->Next;
    if (current == NULL)
    {
        printf("(empty list)\n");
        return;
    }
    
    while (current->Next != NULL)
    {
        printf("%c", current->Data);
        current = current->Next;
    }
    if (current != NULL)
    {
        printf("%c\n", current->Data);
    }
}

void append(char x, Line *L)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->Data = x;
    newNode->Next = NULL;

    struct Node *current = (*L)->Next;
    if (current == NULL)
    {
        (*L)->Next = newNode;
    }
    else
    {
        while (current->Next != NULL)
        {
            current = current->Next;
        }
        current->Next = newNode;
    }
}

void build(const char *s, Line *L)
{
    makenull(L);
    while (*s != '\0')
    {
        append(*s, L);
        s++;
    }
}

int locate(char x, const Line *L)
{
    struct Node *current = (*L)->Next;
    int pos = 0;
    while (current != NULL)
    {
        if (current->Data == x)
        {
            return pos;
        }
        current = current->Next;
        pos++;
    }
    return -1;
}

int count(const Line *L)
{
    struct Node *current = (*L)->Next;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->Next;
    }
    return count;
}

int main()
{
    Line L;
    
    printf("=== Testing Linked List Operations ===\n\n");
    
    // Test 1: makenull function
    printf("Test 1: Testing makenull function\n");
    makenull(&L);
    printf("List initialized successfully\n");
    printf("Count after initialization: %d\n\n", count(&L));
    
    // Test 2: append function
    printf("Test 2: Testing append function\n");
    append('A', &L);
    append('B', &L);
    append('C', &L);
    printf("After appending A, B, C:\n");
    printf("List content: ");
    print(&L);
    printf("Count: %d\n\n", count(&L));
    
    // Test 3: build function
    printf("Test 3: Testing build function\n");
    build("Hello", &L);
    printf("After building with 'Hello':\n");
    printf("List content: ");
    print(&L);
    printf("Count: %d\n\n", count(&L));
    
    // Test 4: locate function
    printf("Test 4: Testing locate function\n");
    printf("Position of 'H': %d\n", locate('H', &L));
    printf("Position of 'e': %d\n", locate('e', &L));
    printf("Position of 'l': %d\n", locate('l', &L));
    printf("Position of 'o': %d\n", locate('o', &L));
    printf("Position of 'Z' (not in list): %d\n\n", locate('Z', &L));
    
    // Test 5: Testing with empty list
    printf("Test 5: Testing with empty list\n");
    makenull(&L);
    printf("After making list null:\n");
    printf("Count: %d\n", count(&L));
    printf("Position of 'A' in empty list: %d\n", locate('A', &L));
    printf("List content: ");
    print(&L);
    printf("\n");
    
    // Test 6: Testing with single character
    printf("Test 6: Testing with single character\n");
    append('X', &L);
    printf("After appending 'X':\n");
    printf("List content: ");
    print(&L);
    printf("Count: %d\n", count(&L));
    printf("Position of 'X': %d\n\n", locate('X', &L));
    
    // Test 7: Testing with longer string
    printf("Test 7: Testing with longer string\n");
    build("Programming", &L);
    printf("After building with 'Programming':\n");
    printf("List content: ");
    print(&L);
    printf("Count: %d\n", count(&L));
    printf("Position of 'P': %d\n", locate('P', &L));
    printf("Position of 'g': %d\n", locate('g', &L));
    printf("Position of 'm': %d\n", locate('m', &L));
    printf("Position of 'Q' (not in list): %d\n\n", locate('Q', &L));
    
    // Test 8: Testing append on existing list
    printf("Test 8: Testing append on existing list\n");
    append('!', &L);
    append('!', &L);
    printf("After appending '!!' to 'Programming':\n");
    printf("List content: ");
    print(&L);
    printf("Count: %d\n\n", count(&L));
    
    printf("=== All tests completed ===\n");
    
    return 0;
}