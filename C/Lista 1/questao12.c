 #include <stdio.h>
 #include <math.h>
    int main(){
        float an, a1, r, n;
            printf("\nQual o primeiro termo da PA:");
            scanf("%f", &a1);
            printf("Qual a razão:");
            scanf("%f", &r);
            printf("Qual o termo:");
            scanf("%f", &n);
            an=a1+(n-1)*r;
            printf("\nO valor é %.1f",an);
            return 0;
    }