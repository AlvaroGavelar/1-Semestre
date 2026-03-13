#include <stdio.h>
#include <math.h>
    int main(){
        float an,a1,q,n;
        printf("\nQual o primeiro termo da PG:");
        scanf("%f", &a1);
        printf("Qual a razão:");
        scanf("%f", &q);
        printf("Qual o termo:");
        scanf("%f", &n);
        an=a1*pow(q,n-1);
        printf("\nO valor é %.1f", an);
        return 0;
    }