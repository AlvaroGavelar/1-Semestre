/*Escreva um programa que leia uma frase do usuário e divida a frase em palavras usando o espaço
como delimitador. Imprima cada palavra em uma linha separada.*/

#include <stdio.h>

void separarFrase(char frase[]){
    int i=0;

    for(i = 0; frase [i] != '\0'; i++){

        if(frase[i] == ' '){
            printf("\n");
        }
        else
            printf("%c", frase[i]);
    }
}

int main (){
    char frase[100];
    int opcao = 0;

    while(opcao != 2){

        printf("1 - Para inicializar - 2 - Para sair\n");
        scanf("%d", &opcao);
        getchar();

        if(opcao == 1){
            printf("Forneça uma frase:\n");
            fgets(frase, 100, stdin);
            separarFrase(frase);
        }

    }

    return 0;
    
}

