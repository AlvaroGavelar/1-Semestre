/*Escreva um programa que leia uma linha com vários nomes separados por vírgula e armazene cada
nome em um vetor de strings. Em seguida, exiba todos os nomes na ordem inversa, ou seja, do
último para o primeiro.
*/

#include <stdio.h>

void separarVirgula(char frase[], char Nome[][50]){

    int i;
    int linha = 0;
    int coluna = 0;

    for(i = 0; frase[i] != '\0'; i++){

        if(frase[i] == ','){
            Nome[linha][coluna] = '\0';
            linha ++;
            coluna = 0;
        }
        else 
            if(frase[i] != '\n'){
                Nome[linha][coluna] = frase[i];
                coluna ++;
            }
    }
        Nome[linha][coluna] = '\0';

        for(i = linha; i >= 0; i--) {
        printf("%s\n", Nome[i]);
    }
}

int main() {

    char frase[100];
    char Nome[10][50];

    printf("Digite os nomes separados por virgula:\n");

    fgets(frase, 100, stdin);

    separarVirgula(frase, Nome);

    return 0;
}