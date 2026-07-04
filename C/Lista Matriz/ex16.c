/*
Faça um programa que leia uma matriz de inteiros e em seguida imprima os índices das linhas
onde se encontra o maior valor.
*/

#include <stdio.h>

int main(){
    int lin, col, achou, n, valor, achado, fim;
    int m[10][10];
    int maior[10];

    do{
        achou = 0;
        printf("\nEscolha A Proporção da Matriz Quadratica ( > 0 || <= 10):");
        scanf("%d", &n);

        if(n <= 0 || n > 10){
            achou = 1;
            printf("\nErro!!\n");
            break;
        }
    }while(achou != 0);

    //Adiciona Valor
    for(lin = 0; lin < n; lin++){
        printf("\nLinha: %d\n", lin+1);
        maior[lin]=0;
        for(col = 0; col < n; col++){
            printf("Coluna: %d\n", col+1);
            printf("\nForneça Um Numero Inteiro:");
            scanf("%d", &valor);

            //Acha o Maior
            if(maior[lin] < valor)
                maior[lin] = valor;
                fim = maior[lin];
        }
    }

    //Acha a Linha do Maior
    for(lin = 0; lin < n; lin++){
        for(col = 0; col < n; col++){
            if(m[lin][col] == maior[lin])
                achado = lin;
        }
    }

    printf("\nO indice da Linha é %d e o Valor é %d:", achado+1, fim);

    return 0;
}