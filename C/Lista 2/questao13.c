/*Escreva um programa que calcule a média dos números digitados pelo usuário, se eles forem
pares. Termine a leitura se o usuário digitar zero (0).*/

#include <stdio.h>

int main(){
    int contador=0, numero;
    float media, soma=0;

    printf("Forneça um numero par ou digete 0 (zero) para finalizar:\n");
    scanf("%d", &numero);

    while(numero != 0){
        if(numero % 2 == 0){
            soma+=numero;
            contador++;
        }
        else
        printf("Forneça um numero par ou digete 0 (zero) para finalizar:\n");
        scanf("%d", &numero);
    }

    if(contador > 0){
        media = soma/contador;
        printf("A média é igual a %.2f:\n", media);
    }
        else
        printf("Nenhum número informado!:\n");

    return 0;
}