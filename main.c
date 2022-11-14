#include "lib/matrix.h"
#include <stdio.h>

int main()
{
    int n = 4;
    printf("matrix: \n");
    int** matrix = init_nxn_matrix(n);
    matrix[0][0] = 3; matrix[0][1] = 5; matrix[0][2] = 2; matrix[0][3] = 1;
    matrix[1][0] = 5; matrix[1][1] = 6; matrix[1][2] = 2; matrix[1][3] = 8;
    matrix[2][0] = 4; matrix[2][1] = 11; matrix[2][2] = 1; matrix[2][3] = 6;
    matrix[3][0] = 7; matrix[3][1] = 5; matrix[3][2] = 4; matrix[3][3] = 3;
    print_matrix(matrix, n, n);

    printf("\nmatrix det = %d\n", determinant(matrix, n));

    printf("\nmat: \n");
    int** mat = init_matrix(n, n);
    mat[0][0] = 3; mat[0][1] = 5; mat[0][2] = 2; mat[0][3] = 1;
    mat[1][0] = 5; mat[1][1] = 6; mat[1][2] = 2; mat[1][3] = 8;
    mat[2][0] = 4; mat[2][1] = 11; mat[2][2] = 1; mat[2][3] = 6;
    mat[3][0] = 7; mat[3][1] = 5; mat[3][2] = 4; mat[3][3] = 3;
    print_matrix(mat, n, n);

    printf("\none_matrix[3][1] = \n");
    int** one_matrix = init_matrix(3, 1);
    one_matrix[0][0] = 1; one_matrix[1][0] = 2; one_matrix[2][0] = 3;
    print_matrix(one_matrix, 3, 1);
    free_matrix(one_matrix, 3, 1);

    printf("\none_y_matrix[1][3] = \n");
    int** one_y_matrix = init_matrix(1, 3);
    one_y_matrix[0][0] = 4; one_y_matrix[0][1] = 5; one_y_matrix[0][2] = 6;
    print_matrix(one_y_matrix, 1, 3);
    free_matrix(one_y_matrix, 1, 3);

    printf("\nmatrix * 2: \n");
    multiple_matrix_num(&matrix, n, n, 2);
    print_matrix(matrix, n, n);

    printf("\nsum of matrix and mat: \n");
    int** matrix_sum = init_nxn_matrix(n);
    add_matrix(matrix, mat, matrix_sum, n, n);
    print_matrix(matrix_sum, n, n);

    printf("\ndifferense between matrix and mat: \n");
    int** matrix_dif = init_nxn_matrix(n);
    sub_matrix(matrix, mat, matrix_dif, n, n);
    print_matrix(matrix_dif, n, n);

    printf("\ntransposed matrix_dif: \n");
    matrix_dif = transpose(matrix_dif, n, n);
    print_matrix(matrix_dif, n, n);

    printf("\nmatrix square: \n");
    square_matrix(matrix_dif, n, n);
    print_matrix(matrix_dif, n, n);

    printf("\nmatrix multiply: \n");
    int dim_xc = 0;
    int dim_yc = 0;
    int** matrix_c = matrix_multiple(mat, n, n, mat, n, n, &dim_xc, &dim_yc);
    print_matrix(matrix_c, dim_xc, dim_yc);


    free_nxn_matrix(matrix, n);
    free_nxn_matrix(matrix_sum, n);
    free_nxn_matrix(matrix_dif, n);
    free_matrix(mat, n, n);
    free_matrix(matrix_c, dim_xc, dim_yc);
    return 0;
}