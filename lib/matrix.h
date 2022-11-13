int** init_nxn_matrix(int dim);
int** init_matrix(int dim_x, int dim_y);
void free_nxn_matrix(int** matrix, int dim);
void free_matrix(int** matrix, int dim_x, int dim_y);

void print_matrix(int** matrix, int dim_x, int dim_y);

int determinant(int** matrix, int dim);
int** transpose(int** matrix, int dim_x, int dim_y);

void multiple_matrix_num(int*** matrix, int dim_x, int dim_y, int number);
void square_matrix(int** matrix, int dim_x, int dim_y);
int** add_matrix(int** A, int** B, int** result_matrix, int dim_x, int dim_y);
int** sub_matrix(int** A, int** B, int** result_matrix, int dim_x, int dim_y);