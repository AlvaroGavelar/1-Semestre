/*Crie uma função que recebe uma string e um caractere, e retorne o número de vezes que esse
caractere aparece na string.*/

#include <stdio.h>

int contarCaracteres(char str[], char c){
    int i=0;
    int contador = 0;

    while(str[i] != '\0'){
        if(str[i] == c){
            contador++;
        }

        i++;
    }

    return contador;
}

int main(){
    char frase[100];
    char letra;

    printf("Forneça uma frase:");
    fgets(frase, 100, stdin);
    printf("Forneça uma letra:");
    scanf("%c", &letra);

    printf("Quantidade de repetições: %d", contarCaracteres(frase,letra));

    return 0;
}