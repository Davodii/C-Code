#include <stdio.h>
#include <math.h>

#define ROWS 41
#define COLLUMNS 41

#define MAX_X 1.0
#define MIN_X -1.0
#define MAX_Y 1.0
#define MIN_Y -1.0
#define X_INCREASE 0.05
#define E 2.718281828459

#pragma region Activation Functions

float linear(float x){
    return x;
}

float binaryStep(float x){
    if(x < 0)
        return 0;
    return 1;
}

float sigmoid(float x){
    float output = 1.0 / (1.0 + pow(E, x * -1.0));
    return output;
}

float GELU(float x){
    float output = 0.5 * x * (1.0 + erf(x / sqrt(2.0)));
    return output;
}

float softplus(float x){
    float output = log(1.0 + pow(E, x));
    return output;
}

float swish_1(float x){
    float output = x / (1.0 + pow(E, x * -1.0));
    return output;
}

float gaussian(float x){
    float output = x * cos(x);
    return output;
}

float sine(float x){
    return sin(x);
}

float cosine(float x){
    return cos(x);
}
#pragma endregion
#pragma region Graph Drawring
void getPoints(char chosenFunction, float* xArr, float* yArr){
    int indexMult = (int)(( fabs(MIN_X) + fabs(MAX_X) ) / X_INCREASE) / 2;
    for(float i = MIN_X; i <= MAX_X +0.01; i += X_INCREASE)
    {
        int index = (i + 1) * indexMult;
        xArr[index] = i;

        switch (chosenFunction)
        {
            case '1': // linear
                yArr[index] = linear(i);
                break;
            case '2': // binary step
                yArr[index] = binaryStep(i);
                break;
            case '3': // sigmoid
                yArr[index] = sigmoid(i);
                break;
            case '4': // GELU
                yArr[index] = GELU(i);
                break;
            case '5': // softplus
                yArr[index] = softplus(i);
                break;
            case '6': // swish 1
                yArr[index] = swish_1(i);
                break;
            case '7': // gaussian
                yArr[index] = gaussian(i);
                break;
            case '8':
                yArr[index] = sine(i);
                break;
            case '9':
                yArr[index] = cosine(i);
                break;
        }
    }

}

void printCoords(float* xArr, float* yArr){
    printf("\nThe points plotted are:\n");
    for (int i = 0; i < ROWS; i++){
        printf("\n(%+1.3f, %+1.3f)", xArr[i], yArr[i]);
    }
}

void drawGraphWithGrid(float *xCoord, float *yCoord){
    int *ptr = 0;
    ptr = (char *)malloc((ROWS * COLLUMNS) * sizeof(char));

    for(int i = 0; i < COLLUMNS * ROWS; i++){
        char currentChar = ' ';
        int x = i % COLLUMNS;
        int y = i / COLLUMNS;

        if(i == (y * COLLUMNS) + ((ROWS + 1) / 2) - 1){
            currentChar = '|';
            if(y == 0){
                currentChar = '^';
            }
            if(y == ROWS - 1){
                currentChar = 'v';
            }
        }

        if(y == (COLLUMNS + 1) / 2 - 1){
            currentChar = '-';
            if(x == 0){
                currentChar = '<';
            }
            if(x == COLLUMNS - 1){
                currentChar = '>';
            }
        }

        if(i == (ROWS * COLLUMNS + 1) / 2 - 1){
            currentChar = '0';
        }

        ptr[i] = currentChar;
    }

    for(int i = 0; i <= 40; i++){
        int x = ((xCoord[i] + 1) * 40) / 2;
        int y = 41 - ((yCoord[i] + 1) * 40) / 2;
        int index = (int)(y * COLLUMNS) + x;
        ptr[index] = 'X';
    }

    for(int i = 0; i < COLLUMNS * ROWS; i++){
        printf("%c ", ptr[i]);
        if(i % COLLUMNS == COLLUMNS - 1){
            printf("\n");
        }
    }

    free(ptr);
}

#pragma endregion

char getInput(){
    // Will return the chosen function by the user

    printf("linear     : 1\n");
    printf("binary step: 2\n");
    printf("sigmoid    : 3\n");
    printf("GELU       : 4\n");
    printf("softplus   : 5\n");
    printf("swish 1    : 6\n");
    printf("gaussian   : 7\n");
    printf("sine       : 8\n");
    printf("cosine     : 9\n");

    printf("Choose the activation function:");
    char input = getchar();

    if(input != '1' && input != '2' && input != '3' && input != '4' && input != '5' && input != '6' && input != '7' && input != '8' && input != '9'){
        printf("Your input is not valid, please try again\n");
        input = getInput();
    }

    return input;
}

// Main
int main(){
    float xCoord[COLLUMNS];
    float yCoord[ROWS];
    char input = getInput();
    getPoints(input, xCoord, yCoord);
    drawGraphWithGrid(xCoord, yCoord);
    //printCoords(xCoord, yCoord);
    return 0;
}
