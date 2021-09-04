#include <stdio.h>

#define ROWS 4
#define COLLUMNS 3

int values[ROWS][COLLUMNS] = {{1,2,3}, 
                              {4,5,6}, 
                              {7,8,9}, 
                              {10,11,12}};
int newValues[COLLUMNS] = {3,6,9};


// Change the first int[] of values to that of newValues
void changeFirstSet(){
    int i;
    for(i = 0; i < sizeof(values[0]) / sizeof(int); i++){
        values[0][i] = newValues[i];
    }
}

// Change the row of a 2D array with the values of a normal int array
void changeArrayRowWithRow(int** arrayToChange, int* arrayOfNewValues, int rowtoChange){
    int i;
    int* rowPointer = arrayToChange;
    for(i = 0; i < COLLUMNS; i++){
        *(int*)(rowPointer + i + (rowtoChange * COLLUMNS)) = *(int*)(arrayOfNewValues + i);
    }
}

void print2DArray(int** arrayToPrint){
    int i,j;
    for(i = 0; i < sizeof(values) / sizeof(values[0]); i++){
        printf("[ ");
        for( j = 0; j < COLLUMNS; j++){
            printf("%d ", values[i][j]);
        }
        printf("]\n");
    }
}

int main(){
    print2DArray(values);
    printf("\n");

    changeFirstSet();
    print2DArray(values);
    printf("\n");

    changeArrayRowWithRow(values, newValues, 2);

    print2DArray(values);

    return 0;
}


// Have a 2D array of values
// Create a new 2D empty array with specifed sizes
// Output the array
// Change a row / value inside the newly created array
// Output the array