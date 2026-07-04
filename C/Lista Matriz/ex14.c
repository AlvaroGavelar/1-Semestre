/*
Faça um programa que receba:
a) 10 nomes de produtos e armazene-os em um vetor (o nome é único);
b) O estoque de cada um destes produtos, em cada um dos 5 armazéns e armazene-os em uma
matriz 5X10;
c) O custo(preço) dos 10 produtos e armazene-os em um vetor.
Deve ser calculado e impresso:
• O total de itens armazenados em cada armazém;
• O total de itens armazenados de cada produto em todos os armazéns 
*/

#include <stdio.h>
#include <string.h>
#define QTD_PRODUTOS  10

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void lerString(char nome[][100], int tamanho){
    int i, erro, tam;
    char nNome[100];

    for(i = 0; i < tamanho; i++){
        do{
            erro = 0;

            printf("Forneça o Nome do Produto (Unico)");
            fgets(nNome, 100, stdin);

            tam = strlen(nNome);
            if(nNome[tam-1] == '\n')
                nNome[tam-1] = '\0';
            else
                limpaBuffer();
            
            if(strcmp(nome[i], nNome) == 0){
                erro = 1;
                printf("\nNome ja Cadastrado\n");
            }
            else
                strcpy(nome[i], nNome);

        }while(erro != 0);
    }
}

int main(){
    char nome[QTD_PRODUTOS][100];
    int mP[10][5];

    lerString(nome, QTD_PRODUTOS);

    
}