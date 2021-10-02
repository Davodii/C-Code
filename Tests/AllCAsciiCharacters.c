#include <stdio.h>

int main(){
    int i = 0;
    for (i; i <= 255; i++){
        if(i != 0 && i != 7 && i!= 8 && i!= 9 && i!= 10 && i!= 11 && i!= 12 && i!= 13 && i!= 14 && i!= 15 && i!= 27) {break;}
            //printf("\n%3d : %c", i, i);
    }

    printf("%d", (int)-1.5);
    return 0;
}