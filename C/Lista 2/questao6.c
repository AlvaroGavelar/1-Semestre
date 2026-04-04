/*Faça um programa que leia 20 números e imprima a soma dos positivos e o 
total de números negativos.*/

#include <stdio.h>

    int main(){
        int contador=0, totalNegativos=0;
        float numero, somaPositivos=0;

    do{
        printf("\nForneça um numero:");
        scanf("%f", &numero);
        if(numero > 0){
            somaPositivos+=numero;
        }
        else
            if(numero < 0){
            totalNegativos++;
        }

        contador++;
        printf("\nContador: %d", contador);
    }while(contador < 20);

    printf("\nSoma dos numeros positivos é igual a %.2f", somaPositivos);
    printf("\nTotal de numeros negativos é igual a %d", totalNegativos);
    
    return 0;
}