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
    printf("(%.3lf, %.3lf)\n", p->x, p->y);
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