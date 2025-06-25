#include <stdio.h>
#include <stdlib.h>

typedef struct{
      double coeff;
      int expo;
}Monomial;

typedef struct NodeTag{
      Monomial e;
      struct NodeTag* next;
}Node;
typedef Node* Polynomial;

Polynomial init()
{
    Polynomial polynominal = malloc(sizeof(Polynomial));
    polynominal->next = NULL;
    return polynominal;
}