/*
Faça um programa que leia as dimensões de uma matriz quadrada de ordem N, onde N é menor ou
igual a 10. Preencha cada posição da matriz com a soma dos seus próprios índices (ou seja, M[i][k] =
i + k). Ao final, imprima a matriz na tela em formato de tabela.
*/

#include <stdio.h>

int main(){
    int i, k, n;

    do{
        printf("\nForneça um Numero <= 10 para a Ordem da Matriz:");
        scanf("%d", &n);
    }while(n > 10 || n <= 0);

    int m[10][10];

        for(i=0;i<n;i++){
            for(k=0; k<n ;k++){
                m[i][k] = i + k;
            }
        }

    for(i=0;i<n;i++){
        for(k=0;k<n;k++){
            printf("%d \t", m[i][k]);
        }
        printf("\n");
    }

    return 0;
}
