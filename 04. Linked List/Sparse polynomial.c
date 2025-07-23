#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double coeff;
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
    Polynomial polynomial = malloc(sizeof(Node));
    polynomial->next = NULL;
    return polynomial;
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
            current->data.coeff += monomial.coeff;
            // If the coefficient becomes zero, remove the node
            if (current->data.coeff == 0)
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

Polynomial read_from_console(int nums)
{
    Polynomial polynomial = init();
    Monomial monomial;
    for (int i = 0; i < nums; i++)
    {
        scanf("%lf %d", &monomial.coeff, &monomial.expo);
        addMonomial(monomial, &polynomial);
    }
    return polynomial;
}

void print(Polynomial polynomial)
{
    Node *current = polynomial->next;
    while (current != NULL)
    {
        if (current->data.coeff != 0)
        {
            printf("(%.2lf, %d) ", current->data.coeff, current->data.expo);
        }
        current = current->next;
    }
    printf("\n");
}

Polynomial addition(Polynomial polynomial1, Polynomial polynomial2)
{
    Polynomial result = init();
    Node *current1 = polynomial1->next;
    Node *current2 = polynomial2->next;

    while (current1 != NULL || current2 != NULL)
    {
        Monomial monomial;
        if (current1 == NULL)
        {
            monomial = current2->data;
            current2 = current2->next;
        }
        else if (current2 == NULL)
        {
            monomial = current1->data;
            current1 = current1->next;
        }
        else if (current1->data.expo < current2->data.expo)
        {
            monomial = current1->data;
            current1 = current1->next;
        }
        else if (current1->data.expo > current2->data.expo)
        {
            monomial = current2->data;
            current2 = current2->next;
        }
        else
        {
            monomial.coeff = current1->data.coeff + current2->data.coeff;
            monomial.expo = current1->data.expo;
            current1 = current1->next;
            current2 = current2->next;
        }
        addMonomial(monomial, &result);
    }

    return result;
}

double valuate(Polynomial polynomial, double x)
{
    double result = 0;
    Node *current = polynomial->next;
    while (current != NULL)
    {
        result += current->data.coeff * pow(x, current->data.expo);
        current = current->next;
    }
    return result;
}

Polynomial derivative(Polynomial polynomial)
{
    Monomial temp_monomial;

    Polynomial result = init();

    Node *polynomial_current = polynomial->next;
    while (polynomial_current != NULL)
    {
        if (polynomial_current->data.expo == 0)
        {
            polynomial_current = polynomial_current->next;
            continue;
        }

        temp_monomial.coeff = polynomial_current->data.coeff;
        temp_monomial.expo = polynomial_current->data.expo;

        temp_monomial.coeff *= temp_monomial.expo;
        temp_monomial.expo--;

        addMonomial(temp_monomial, &result);
        polynomial_current = polynomial_current->next;
    }

    return result;
}

int main()
{
    int nums;
    double x;
    scanf("%d %lf", &nums, &x);

    Polynomial polynomial = init();
    polynomial = read_from_console(nums);

    print(polynomial);
    printf("%.8lf\n", valuate(polynomial, x));
    print(derivative(polynomial));
}