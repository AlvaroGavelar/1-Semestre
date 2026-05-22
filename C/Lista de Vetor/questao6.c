//Leia 50 números e mostre o segundo maior valor.

#include <stdio.h>
#define QUANTIDADE_ALUNOS 50

int main(){
    int qntA[QUANTIDADE_ALUNOS];
    int i, maior, segundoMaior;

    for(i=0; i<QUANTIDADE_ALUNOS; i++){
        printf("Forneça um número:");
        scanf("%d", &qntA[i]);
    }

    for(i=0; i<QUANTIDADE_ALUNOS; i++){
        if(qntA[i] > maior){
            segundoMaior = maior;
            maior = qntA[i];
        }
        else if(qntA[i] > segundoMaior && qntA[i] != maior)
            segundoMaior = qntA[i];
        
    }

    printf("O segundo maior é: %d", segundoMaior);

}