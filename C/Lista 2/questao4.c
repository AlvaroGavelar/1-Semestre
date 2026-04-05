/*Faça um programa que imprima todos os números múltiplos de 5,
 no intervalo fechado de 1 a 500*/

#include <stdio.h>

    int main(){
        int numero=0;
    
    printf("Numeros de 1 a 500 dividos por 5");

    do{
        if(numero % 5 == 0){
            printf("%d\n", numero);
        }
        numero++;
    }while(numero<=500);

    return 0;
    }