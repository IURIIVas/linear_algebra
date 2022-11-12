#include <malloc.h>
#include <math.h>

int** init_nxn_matrix(int n)
{
    int** matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }
    return matrix;
}

void free_nxn_matrix(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int** submatrix(int** matrix, int n, int x)
{
    int** small_matrix = init_nxn_matrix(n - 1);
    int subi = 0;
    for (int i = 0; i < n; i++)
    {
        int subj = 0;
        if (i == 0) 
        {
            continue;
        }
        for (int j = 0; j < n; j++)
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

int determinant(int** matrix, int n)
{
    int det = 0;
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return matrix[0][0];
    }
    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
    }
    int power = 1;
    
    for (int x = 0; x < n; x++)
    {
        det += power * matrix[0][x] * determinant(submatrix(matrix, n, x), n - 1);
        power = -power;
    }
    return det;
}