/*Faça um programa que imprima os 100 primeiros inteiros positvos pares.*/

#include <stdio.h>

    int main(){
        int numero=0,
            contador=0;

    printf("Os 100 primeiros numeros inteiros pares:\n");

        do{
            if(numero % 2 == 0){
                printf("%d\n", numero);
                contador++;
            }
        numero ++;  
        }while(contador < 100);
    
    return 0;
    }