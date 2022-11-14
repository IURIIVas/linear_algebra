#include "../lib/vector.h"
#include <math.h>
#include <stdio.h>
#include <malloc.h>

vector2d* vector2d_init()
{
    vector2d* a = (vector2d*) malloc(sizeof(vector2d));
    a->x = 0;
    a->y = 0;
    return a;
}

void print_vector2d(vector2d* a)
{
    printf("x: %d, y: %d\n", a->x, a->y);
}

vector2d* vector2d_sum(vector2d* a, vector2d* b)
{
    vector2d* c = vector2d_init();
    c->x = a->x + b->x;
    c->y = a->y + b->y;
    return c;
}

vector2d* vector2d_sub(vector2d* a, vector2d* b)
{
    vector2d* c = vector2d_init();
    c->x = a->x - b->x;
    c->y = a->y - b->y;
    return c;
}

void vector2d_mul(vector2d* a, int num)
{
    a->x *= num;
    a->y *= num;
}

double vector2d_module(vector2d* a)
{
    int qx = a->x * a->x;
    int qy = a->y * a->y;

    double module = sqrt(qx + qy);
    return module;
}