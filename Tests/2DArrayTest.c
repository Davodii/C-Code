#include <stdio.h>


void test1(){
    int test[3][2];

    int (*p1)[2] = test;
    int *p2 = NULL;

    for (; p1 != test+3; ++p1) {
        for (p2 = *p1; p2 != *p1+2; ++p2 ) {
            printf("%d\n", *p2);
        }
    }
}

int main(){
    test1();

    return 0;

}