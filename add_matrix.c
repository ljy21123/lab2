#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
void inputMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void addMatrix(int** matrixA, int** matrixB, int** result, int rows, int cols);

int main() {
    int rows, cols;

    // 행렬의 크기 입력
    printf("rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // 행렬 동적 할당
    int** matrixA = createMatrix(rows, cols);
    int** matrixB = createMatrix(rows, cols);
    int** resultMatrix = createMatrix(rows, cols);

    // 행렬 내용 입력
    printf("Matrix A:\n");
    inputMatrix(matrixA, rows, cols);

    printf("Matrix B:\n");
    inputMatrix(matrixB, rows, cols);

    // 두 행렬 덧셈
    addMatrix(matrixA, matrixB, resultMatrix, rows, cols);

    // 결과 출력
    printf("Result Matrix:\n");
    printMatrix(resultMatrix, rows, cols);

    // 메모리 해제
    freeMatrix(matrixA, rows);
    freeMatrix(matrixB, rows);
    freeMatrix(resultMatrix, rows);

    return 0;
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int** matrixA, int** matrixB, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
