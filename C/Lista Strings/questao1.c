/*Implemente uma função que transforme todos os caracteres de uma string para maiúsculos.*/

#include <stdio.h>
#include <ctype.h>
#define TAMANHO 50

void converterMaiusculo(char vFrase[], int tamanho){
    int i;

    for(i=0; vFrase[i] != '\0'; i++){
        vFrase[i] = toupper(vFrase[i]);
    }
}

int main(){
    char frase[TAMANHO];


    printf("Forneça uma frase:");
    fgets(frase, TAMANHO, stdin);

    converterMaiusculo(frase, TAMANHO);

    printf("\nResultado: %s", frase);


    return 0;
}