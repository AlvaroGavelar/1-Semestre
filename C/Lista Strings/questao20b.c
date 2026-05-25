/*Escreva uma função que receba uma frase e retorne o número de palavras presentes nela*/

#include <stdio.h>

int lerQuantidadePalavar(char frase[]){

    int i;
    int contador = 0;

    for(i = 0; frase[i] != '\0'; i++) {

        if(frase[i] != ' ' && (i == 0 || frase[i-1] == ' ')) {

            contador++;
        }
    }

    return contador;

}

int main (){
    
    char frase[50];

    printf("Forneça uma frase:");
    fgets(frase, 50, stdin);

    printf("Quantidadde de Frases é : %d", lerQuantidadePalavar(frase));


}