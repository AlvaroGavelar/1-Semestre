/*Faça um programa que imprima todos os números inteiros de 
200 a 100 (em ordem decrescente).*/

#include <stdio.h>

    int main(){
        int numero=200;

    printf("Numeros inteiros de 200 a 100 em ordem decrescente:\n");

    do{
        printf("%d\n", numero);
        numero--;
        
    }while(numero >= 100);

    return 0;
    }