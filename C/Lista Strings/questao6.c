/*Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses
caractere na string. */

#include <stdio.h>

void apagarCaractere(char str[], char c){
    int i, j;

    for(i=0; str[i] != '\0'; i++){
        if(str[i] == c){
            for(j=i;str[j] != '\0'; j++){
                str[j] = str[j + 1];
            }
            i--;
        }
    }
}

int main(){
    char frase[100];
    char letra;

    printf("Forneça uma frase:");
    fgets(frase, 100, stdin);
    printf("Forneça uma letra:");
    scanf("%c", &letra);

    apagarCaractere(frase,letra);

    printf("Frase sem os caracteres: %s", frase);
}