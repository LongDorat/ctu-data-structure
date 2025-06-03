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

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void normalize(Fraction *f)
{
    if (f->denominator < 0) {
        f->numerator = -f->numerator;
        f->denominator = -f->denominator;
    }

    int gcd = GCD(f->numerator, f->denominator);
    f->numerator /= gcd;
    f->denominator /= gcd;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;

    return result;
}

Fraction subtract(Fraction f1, Fraction f2)
{
    Fraction result;
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;

    normalize(&result);

    return result;
}