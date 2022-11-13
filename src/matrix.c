#include <malloc.h>
#include <math.h>
#include <stdio.h>

int** init_nxn_matrix(int dim)
{
    int** matrix = (int**) malloc(dim * sizeof(int*));
    for (int i = 0; i < dim; i++)
    {
        matrix[i] = (int*) malloc(dim * sizeof(int));
    }
    return matrix;
}

int** init_matrix(int dim_x, int dim_y)
{
    int** matrix = (int**) malloc(dim_x * sizeof(int*));
    for (int i = 0; i < dim_x; i++)
    {
        matrix[i] = (int*) malloc(dim_y * sizeof(int));
    }
    return matrix;
}

void free_nxn_matrix(int** matrix, int dim)
{
    for (int i = 0; i < dim; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void free_matrix(int** matrix, int dim_x, int dim_y)
{
    for (int i = 0; i < dim_x; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void print_matrix(int** matrix, int dim_x, int dim_y)
{
    if (0 == dim_x || 0 == dim_y) return;
    if (1 == dim_x && 1 == dim_y)
    {
        printf("%d", matrix[0][0]);
    }
    else
    {
        for (int i = 0; i < dim_x; i++)
        {
            printf("| ");
            for (int j = 0; j < dim_y; ++j)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("|\n");
        }
    }
    
}

int** submatrix(int** matrix, int dim, int x)
{
    int** small_matrix = init_nxn_matrix(dim - 1);
    int subi = 0;
    for (int i = 0; i < dim; i++)
    {
        int subj = 0;
        if (i == 0) 
        {
            continue;
        }
        for (int j = 0; j < dim; j++)
        {
            if (j == x) 
            {
                continue;
            }
            small_matrix[subi][subj] = matrix[i][j];
            subj++;
        }
        subi++;
    }
    return small_matrix;
}

int determinant(int** matrix, int dim)
{
    int det = 0;
    if (dim == 0)
    {
        return 0;
    }
    if (dim == 1)
    {
        return matrix[0][0];
    }
    if (dim == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    int power = 1;
    
    for (int x = 0; x < dim; x++)
    {
        det += power * matrix[0][x] * determinant(submatrix(matrix, dim, x), dim - 1);
        power = -power;
    }
    return det;
}

int** transpose(int** matrix, int dim_x, int dim_y)
{
    int** transposed = init_matrix(dim_y, dim_x);

    for (int i = 0; i < dim_x; i++)
    {
        for (int j = 0; j < dim_y; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

void multiple_matrix_num(int*** matrix, int dim_x, int dim_y, int number)
{
    int** mat = *matrix;
    for (int i = 0; i < dim_x; i++)
    {
        for (int j = 0; j < dim_y; j++)
        {
            mat[i][j] *= number;
        }
    }
}

void add_matrix(int** A, int** B, int** result_matrix, int dim_x, int dim_y)
{
    if (0 == dim_x || 0 == dim_y) return;
    for (int i = 0; i < dim_x; i++)
    {
        for (int j = 0; j < dim_y; j++)
        {
            result_matrix[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub_matrix(int** A, int** B, int** result_matrix, int dim_x, int dim_y)
{
    if (0 == dim_x || 0 == dim_y) return;
    for (int i = 0; i < dim_x; i++)
    {
        for (int j = 0; j < dim_y; j++)
        {
            result_matrix[i][j] = A[i][j] - B[i][j];
        }
    }
}

// todo: init new unsigned long matrix.
void square_matrix(int** matrix, int dim_x, int dim_y)
{
    if (0 == dim_x || 0 == dim_y) return;
    for (int i = 0; i < dim_x; i++)
    {
        for (int j = 0; j < dim_y; j++)
        {
            matrix[i][j] *= matrix[i][j];
        }
    }
}

