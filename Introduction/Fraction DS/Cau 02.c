#include <stdio.h>

typedef struct
{
    int numerator;
    int denominator;
} Fraction;

int main()
{
    Fraction f1, f2;

    scanf("%d %d", &f1.numerator, &f1.denominator);
    scanf("%d %d", &f2.numerator, &f2.denominator);

    printf("Fraction 1: %d/%d\n", f1.numerator, f1.denominator);
    printf("Fraction 2: %d/%d\n", f2.numerator, f2.denominator);

    printf("Product fraction: %d/%d\n",
           f1.numerator * f2.numerator,
           f1.denominator * f2.denominator);

    return 0;
}