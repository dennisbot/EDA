void matrix_init(int ***M, const int rows, const int cols) {
    int** T;
    T = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        T[i] = (int*)malloc(cols * sizeof(int));
    }
    *M = T;
}

void matrix_read(int ***M, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &((*M)[i][j]));
        }
    }
}
int** matrix_multiplication(int** A, int** B, const int rows, const int cols) {
    if (rows != cols) {
        puts("the number of rows should be the same as the number of columns");
        return NULL;
    }
    int n = rows;
    int** C;
    matrix_init(&C, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
void matrix_print(int **M, const int rows, const int cols) {
    puts("============= MATRIX ==============");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", M[i][j]);
            // printf("%d\t", ((*M)[i][j]));
        }
        puts("");
    }
    puts("======================================");
}

void matrix_readable_print(int **M, const int rows, const int cols) {
    std::string s;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            s = ( (j + 1 == cols) ? "" : " ");
            printf("%d%s", M[i][j], s.c_str());
            // printf("%d\t", ((*M)[i][j]));
        }
        puts("");
    }
}
void test() {
    puts("se ha llamada la método test");
}