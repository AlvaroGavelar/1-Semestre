/*Escreva um programa que leia 50 valores e encontre o maior e o menor deles. Mostre o resultado*/

#include <stdio.h>

int main(){

    int contador=0;
    float numero, maior=0, menor=0, primeiro=1;

    while(contador < 50){

        printf("\nForneça um número:");
        scanf("%f", &numero);

        if(primeiro == 1){
            maior = numero;
            menor = numero;
            primeiro = 0;
        }
        else
            if(numero > maior){
                maior = numero;
            } 

            if(numero < menor){
            menor = numero;
            }
        
        contador++;        

    }

    printf("\nO maior número é: %f", maior);
    printf("\nO menor número é: %f", menor);

    return 0;
}

