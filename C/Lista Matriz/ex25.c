/*
Escreva um programa em C que leia um vetor de 12 elementos inteiros fornecidos pelo usuário. Em
seguida, crie uma função chamada copiaVetorParaMatriz que receba esse vetor e uma matriz de
dimensões 3x4.
A função deve copiar todos os elementos do vetor para a matriz, preenchendo-a linha por linha (os 4
primeiros elementos do vetor vão para a linha 0, os 4 seguintes para a linha 1 e os 4 últimos para a
linha 2).
Ao final, exiba a matriz gerada em formato de tabela no main.
Dica para os alunos: Tente resolver este exercício de duas formas:
1. Utilizando uma variável contadora auxiliar de 0 a 11 para caminhar pelo vetor enquanto
percorre a matriz com dois laços for.
*/
#include <stdio.h>

void copiaVetorMatriz(int v[], int m[4][3]){
    int contador = 0;
    int col, lin;

    for(lin = 0; lin < 3; lin++){
        for(col = 0; col < 4; col++){
            m[lin][col] = v[contador];
            contador++;
        }
    }

    printf("\n");

    for(lin = 0; lin < 3; lin++){
        for(col = 0; col < 4; col++){
            printf("%d\t", m[lin][col]);
        }
        printf("\n");
    }    
}


int main(){
    int v[12];
    int m[4][3];
    int col, lin, i, erro, contador;

    for(i = 0; i < 12; i++){
        erro = 0;
        do{
            printf("Forneça Um Numero Inteiro >= 0:");
            scanf("%d", &v[i]);

            if(v[i] < 0){
                erro = 1;
                printf("\nErro!!\n");
            }
        }while(erro != 0);
    }

    copiaVetorMatriz(v, m);    

return 0;
}

