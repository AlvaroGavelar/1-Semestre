/*Faça um programa que receba quinze números inteiros positivos do usuário
 e imprima a soma da raiz quadrada de cada número.*/

#include <stdio.h>
#include <math.h>

    int main(){
        int numero, contador=0;
        float soma, raiz;


        do{
            printf("Forneça um numero positivo:\n");
            scanf("%d", &numero);
            if(numero>=0){
                soma += sqrt(numero);
                contador++;
            }
            else
            
            printf("\nNumero necessita ser positivo");
        }while(contador < 15);

        printf("\nA raiz da soma é igual a : %.2f", soma);

        return 0;
    }