#include <stdio.h>

int main(){
    int i, j, n, somaSec=0, somaPrinc=0;

    do{
        printf("\nForneça um Numero <= 10 para a Ordem da Matriz:");
        scanf("%d", &n);
    }while(n < 1|| n > 10);

    int m[10][10];


    //Adiciona Os Numeros
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("\nForneça o Valor da Coluna [%d] Linha [%d]:", j, i);
            scanf("%d", &m[i][j]);

            //Veridica se é da diagonal secundaria
            if(i + j == n - 1)
                somaSec+=m[i][j];
            
            //Verifica se é da Diagonal Principal
            if(i == j)
                somaPrinc+=m[i][j];

        }
    }

    printf("\nMatriz:\n\n");

    for(i = 0; i < n; i++){
        for(j=0; j < n; j++){

            //Coloca () na Secundaria
            if(i + j == n - 1){
                printf("(%d)\t",m[i][j]);
            }
            else
                //Coloca {} na Principal
                if(i == j){
                    printf("{%d}\t", m[i][j]);
                }
                else
                    printf("%d \t", m[i][j]);
        }

        printf("\n");
    }

    printf("\nSoma da Diagonal Principal: %d", somaPrinc);
    printf("\nSoma da Diagonal Secundaria: %d\n", somaSec);

    return 0;
}