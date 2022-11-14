#ifndef VECTOR_H
#define VECTOR_H

typedef struct {
    int x;
    int y;
} vector2d;

vector2d* vector2d_init();
void print_vector2d(vector2d* a);

vector2d* vector2d_sum(vector2d* a, vector2d* b);
vector2d* vector2d_sub(vector2d* a, vector2d* b);
void vector2d_mul(vector2d* a, int num);

double vector2d_module(vector2d* a);
#endif