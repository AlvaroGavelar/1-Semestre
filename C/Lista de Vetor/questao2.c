/*Leia 10 números e mostre-os na ordem inversa*/

#include <stdio.h>
#define QUANTIDADE_NUMERO 10

int main(){
    int i;
    int vet[QUANTIDADE_NUMERO];

    //Leitura
    for(i=0;i<QUANTIDADE_NUMERO;i++){
        printf("Forneça um número:");
        scanf("%d", &vet[i]);
    }

    for(i=QUANTIDADE_NUMERO - 1;i>=0;i--){
        printf("\t%d", vet[i]);
    }

    return 0;
}