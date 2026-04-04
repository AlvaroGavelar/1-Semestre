/*Faça um programa que tenha como entrada um conjunto de numeros inteiros. Calcular e
imprimir:
a) A media dos numeros lidos;
b) O maior número;
c) O menor número.
Obs. Flag de saida= número zero (não deve ser considerado)*/

#include <stdio.h>

    int main(){
        int contador=0, numero, maiorNumero, menorNumero;
        float soma=0;

        printf("\nForneça um numero inteiro ou digite 0 para finalizar: ");
        scanf("%d", &numero);

        if(numero != 0){
            maiorNumero = numero;
            menorNumero = numero;
        }

        while(numero != 0){
            soma+=numero;
            contador++;

            if(numero > maiorNumero){
                maiorNumero = numero;
            }

            else if(numero < menorNumero){
                menorNumero = numero;
            }

            printf("\nForneça um numero inteiro ou digite 0 para finalizar: ");
            scanf("%d", &numero);
        }

        if(contador > 0){

            printf("\nA media é igual a %.2f", soma/contador);
            printf("\nO maior número é %.2d", maiorNumero);
            printf("\nO menor número é %.2d", menorNumero);

        }
        
        else
            printf("Valor invalido, digite um valor valido");

        return 0;
    }