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
    printf("%d/%d", f.numerator, f.denominator);
}

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

void normalize(Fraction *f)
{
    if (f->denominator < 0)
    {
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

    normalize(&result);

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

Fraction multiply(Fraction a, Fraction b)
{
    Fraction result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;

    normalize(&result);

    return result;
}

Fraction divide(Fraction a, Fraction b)
{
    Fraction result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;

    normalize(&result);

    return result;
}

int main()
{
    Fraction f1, f2;
    f1 = read();
    f2 = read();
    normalize(&f1);
    normalize(&f2);

    // Addition
    print(f1);
    printf(" + ");
    print(f2);
    Fraction sum = add(f1, f2);
    normalize(&sum);
    printf(" = ");
    print(sum);
    printf("\n");

    // Subtraction
    print(f1);
    printf(" - ");
    print(f2);
    Fraction diff = subtract(f1, f2);
    normalize(&diff);
    printf(" = ");
    print(diff);
    printf("\n");

    // Multiplication
    print(f1);
    printf(" * ");
    print(f2);
    Fraction prod = multiply(f1, f2);
    normalize(&prod);
    printf(" = ");
    print(prod);
    printf("\n");

    // Division
    print(f1);
    printf(" / ");
    print(f2);
    Fraction quot = divide(f1, f2);
    normalize(&quot);
    printf(" = ");
    print(quot);
    printf("\n");

    return 0;
}