#include <stdio.h>

int main(){
    int i, j, m[4][4];

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            m[i][j] = 0;

            if(i == j)
                m[i][j] = 1;
        }
    }

    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("[%d]\t",m[i][j]);
        }
        printf("\n");
    }

    return 0;
}