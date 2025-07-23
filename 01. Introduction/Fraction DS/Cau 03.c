#include <stdio.h>

typedef struct
{
    int numerator;
    int denominator;
} Fraction;

Fraction read()
{
    Fraction f;
    scanf("%d %d", &f.numerator, &f.denominator);
    return f;
}

void print(Fraction f)
{
    printf("%d/%d\n", f.numerator, f.denominator);
}