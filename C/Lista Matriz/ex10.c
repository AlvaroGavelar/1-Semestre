/*
Escreva um programa que leia valores inteiros para preencher uma matriz M de dimensões 10x20.
Após a leitura de todos os dados, o programa deve processar a matriz e exibir na tela:
1. o maior elemento pertencente a cada uma das linhas;
2. a média aritmética dos elementos de cada uma das colunas;
3. o resultado do produto (multiplicação) de todos os elementos da matriz que sejam diferentes
de zero;
4. a posição exata (linha e coluna) de todas as ocorrências de um valor específico, o qual deve
ser digitado pelo usuário ao final do programa.
*/

#include <stdio.h>
#define LINHA 10
#define COLUNA 20

int main(){
    int col, erro, lin, valor, maior[LINHA], mA[COLUNA];
    int m[LINHA][COLUNA];

    //Preenche Matriz
    for(lin = 0; lin < LINHA; lin++){
        for(col = 0; col < COLUNA; col++){
            do{
                erro = 0;

                printf("Forneca um Numero Inteiro:");
                scanf("%d", &valor);

                if(valor < 0){
                    erro = 1;
                    printf("\n>= 0\n");
                }

                if(erro == 0)
                    m[lin][col] = valor;

            }while(erro != 0);
        }
    }

    //Acha o Maior da Linha
    for(lin = 0; lin < LINHA; lin++){
        maior[lin] = m[lin][0];
        for(col = 0; col < COLUNA; col++){
            if(m[lin][col] > maior[lin])
                maior[lin] = m[lin][col];
        }
    }   

    //Media Ari

    return 0;
}