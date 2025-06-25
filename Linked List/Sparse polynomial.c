#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double coef;
    int expo;
} Monomial;

typedef struct NodeTag
{
    Monomial data;
    struct NodeTag *next;
} Node;
typedef Node *Polynomial;

Polynomial init()
{
    Polynomial polynominal = malloc(sizeof(Polynomial));
    polynominal->next = NULL;
    return polynominal;
}

void add_node_after_current(Monomial monomial, Polynomial *polynomial, Node *current)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = monomial;
    new_node->next = NULL;

    if (current == NULL)
    {
        // Add at the end of the polynomial
        Node *last = (*polynomial);
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    else
    {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void add_node_before_current(Monomial monomial, Polynomial *polynomial, Node *current)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = monomial;
    new_node->next = current;

    Node *prev = (*polynomial);
    while (prev->next != current)
    {
        prev = prev->next;
    }
    prev->next = new_node;
}

void addMonomial(Monomial monomial, Polynomial *polynomial)
{
    // No node in the polynomial
    if ((*polynomial)->next == NULL)
    {
        add_node_after_current(monomial, polynomial, NULL);
        return;
    }

    Node *current = (*polynomial)->next;
    while (current != NULL)
    {
        // If the exponent is equal, add the coefficient
        if (current->data.expo == monomial.expo)
        {
            current->data.coef += monomial.coef;
            // If the coefficient becomes zero, remove the node
            if (current->data.coef == 0)
            {
                Node *to_delete = current;
                current = current->next;
                // If it was the first node, update the head
                if ((*polynomial)->next == to_delete)
                {
                    (*polynomial)->next = current;
                }
                free(to_delete);
            }
            return;
        }
        // If the exponent is less than the current node's exponent, insert before
        else if (monomial.expo < current->data.expo)
        {
            add_node_before_current(monomial, polynomial, current);
            return;
        }
        // Move to the next node
        current = current->next;
    }

    add_node_after_current(monomial, polynomial, current);
}

void print(Polynomial polynomial)
{
    Node *current = polynomial->next;
    while (current != NULL)
    {
        if (current->data.coef != 0)
        {
            printf("(%.2lf, %d) ", current->data.coef, current->data.expo);
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Polynomial d = init();

    Monomial s1 = {6.2, 4};
    Monomial s2 = {4.2, 0};
    Monomial s3 = {2, 4};
    addMonomial(s1, &d);
    addMonomial(s2, &d);
    addMonomial(s3, &d);
    print(d);
}