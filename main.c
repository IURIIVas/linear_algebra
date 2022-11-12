#include <stdio.h>
#include "src/matrix.h"

int main()
{
    int n = 4;
    int **matrix = init_nxn_matrix(n);
    matrix[0][0] = 3; matrix[0][1] = 5; matrix[0][2] = 2; matrix[0][3] = 1;
    matrix[1][0] = 5; matrix[1][1] = 6; matrix[1][2] = 2; matrix[1][3] = 8;
    matrix[2][0] = 4; matrix[2][1] = 11; matrix[2][2] = 1; matrix[2][3] = 6;
    matrix[3][0] = 7; matrix[3][1] = 5; matrix[3][2] = 4; matrix[3][3] = 3;
    for (int i = 0; i < n; ++i)
    {
        printf("| ");
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("|\n");
    }
    printf("\ndet = %d\n", determinant(matrix, n));
    free_nxn_matrix(matrix, n);
    return 0;
}