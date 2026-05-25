//Crie uma função que calcule o comprimento de uma string.

#include <stdio.h>
#include <string.h>

int lerTamanhoString(char str[], int tamanho){
    int t; // tamanho
    fgets(str,tamanho,stdin);
    t=strlen(str);

    return t;

}

int main(){
    char frase[50];
    int tamanho;


    printf("Forneça uma frase:");
    tamanho = lerTamanhoString(frase, 50) - 1;

    printf("Tamanho da string: %d", tamanho);

    return 0;
}