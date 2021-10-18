#include <stdio.h>
#include <stdlib.h>

typedef struct matrix{
    int width;
    int height;
    int* values; 
} matrix_t;

matrix_t* createMatrix(int width, int height, const int *values){
    matrix_t *new = (matrix_t *)malloc((sizeof(matrix_t)));
    new->height = height;
    new->width = width;
    new->values = values;
    return new;
}

matrix_t* addMatrices(matrix_t *a, matrix_t *b){
    if(a->height != b->height || a->width != b->width){
        printf("ERROR: WHEN ADDING, MATRIX A MUST BE THE SAME SIZE AS MATRIX B!");
        exit(0);
    }
    int size = a->width * a->height;
    int *sumValues = malloc(sizeof(int) * size);
    for(int x = 0; x < a->width; x++){
        for(int y = 0; y < a->height; y++){
            int index = x * a->width + y;
            sumValues[index] = (int)(a->values[index]) + (int)(b->values[index]);
        }
    }
    matrix_t *sum = createMatrix(a->width, a->height, sumValues);
    return sum;
}

matrix_t* scalarMatrixMultiplication(matrix_t *matrixToBeMultiplied, int scalar){
    int *new = malloc(sizeof(int) * (matrixToBeMultiplied->height * matrixToBeMultiplied->width));
    for(int i = 0; i < matrixToBeMultiplied->height * matrixToBeMultiplied->width; i++){
        new[i] = matrixToBeMultiplied->values[i] * scalar;
    }

    matrix_t *product = createMatrix(matrixToBeMultiplied->width, matrixToBeMultiplied->height, new);
    return product;
}

matrix_t* matrixTransposition(matrix_t *matrixToBeTransposed){
    int *newValues = malloc(sizeof(int) * (matrixToBeTransposed->width * matrixToBeTransposed->height));

    for(int x = 0; x < matrixToBeTransposed->width; x++){
        for(int y = 0; y < matrixToBeTransposed->height; y++){
            int index = x * matrixToBeTransposed->width + y;
            int transposedIndex = y * matrixToBeTransposed->height + x;
            newValues[transposedIndex] = matrixToBeTransposed->values[index];
        }
    }

    matrix_t *transposedMatrix = createMatrix(matrixToBeTransposed->width, matrixToBeTransposed->height, newValues);
    return transposedMatrix;
}

void printMatrix(matrix_t *matrixToPrint){
    int width = matrixToPrint->width;
    for(int i = 0; i < width * matrixToPrint->height; i++){
        printf((i + 1) % width != 0 ? "|" : "");
        printf(" %-2d", matrixToPrint->values[i]);
        printf((i + 1) % width == 0 ? " |\n" : "");
    }
}

int main(){
    int aValues[4] = {1,2,3,4}; 
    int bValues[4] = {5,6,7,8};
    matrix_t *a = createMatrix( 2, 2, aValues);
    matrix_t *b = createMatrix( 2, 2, bValues);

    matrix_t* sum = addMatrices(a, b); 
    printf("Matrix addition of matrix A and matrix B:\n");
    printMatrix(sum);
    free(sum);
    printf("\n\n");

    matrix_t *scalarProduct = scalarMatrixMultiplication(a, 3);
    printf("Matrix scalar multiplication:\n");
    printMatrix(scalarProduct);
    free(scalarProduct);
    printf("\n\n");

    matrix_t *transposed = matrixTransposition(a);
    printf("Matrix transposition of Matrix B:\n");
    printMatrix(transposed);
    free(transposed);
    printf("\n\n");


    free(a);
    free(b);
    return 0;
}