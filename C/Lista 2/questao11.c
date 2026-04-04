/*Construir um programa que calcule a média aritmética de vários valores inteiros positivos. O final
da leitura acontecerá quando for lido um valor negativo.*/

#include <stdio.h>

    int main(){
        int numero=0, contador=0;
        float soma=0;

        printf("Fornaça um numero postivo e uma negativo para finalizar:");
        scanf("%d", &numero);

        while(numero >= 0){
            if(contador >= 0)
            contador++;
            soma+=numero;

            printf("Fornaça um numero postivo e uma negativo para finalizar:");
            scanf("%d", &numero);
        }

        if(contador > 0){
            printf("\nA media aritmetica é igual a %.2f", soma/contador);
        }
        else{
            printf("\nNenhum numero positivo foi digitado.");
        }

        return 0;
    }