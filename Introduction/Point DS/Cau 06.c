#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

void read(Point *p)
{
    scanf("%lf %lf", &p->x, &p->y);
}

void print(const Point *p)
{
    printf("(%.3lf, %.3lf)", p->x, p->y);
}

double distance(const Point *p1, const Point *p2)
{
    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}

int equal(const Point *p1, const Point *p2, double epsilon)
{
    return distance(p1, p2) < epsilon;
}

void shift(Point *p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

int main()
{
    Point A, B;
    read(&A);
    read(&B);

    // Distance
    print(&A);
    printf(" - ");
    print(&B);
    printf(": %.8lf\n", distance(&A, &B));

    // Point A to (0, 0)
    print(&A);
    printf(" to origin: %.8lf\n", distance(&A, &(Point){0, 0}));
    // Point B to (0, 0)
    print(&B);
    printf(" to origin: %.8lf\n", distance(&B, &(Point){0, 0}));

    // Equality
    switch (equal(&A, &B, 1e-4))
    {
        case 0:
            print(&A);
            printf(" != ");
            print(&B);
            break;
        case 1:
            print(&A);
            printf(" ~= ");
            print(&B);
            break;
    }
    printf("\n");

    // Shifting
    double dx, dy;
    dx = 0.05;
    dy = 0.05;
    shift(&A, dx, dy);
    print(&A);
    printf("\n");
    shift(&B, dx, dy);
    print(&B);

    return 0;
}