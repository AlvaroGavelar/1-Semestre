/*Escreva uma função que receba uma frase e retorne o número de letras presentes nela*/
#include <stdio.h>
#include <string.h>

int lerQuantidadePalavaras(char frase[]){
    int i, j, t;

    for(i=0; frase[i] != '\0'; i++){
        if(frase[i] == ' '){
            for(j=i;frase[j] != '\0'; j++){
                frase[j] = frase[j + 1];
            }
            i--;
        }
    }

    t = strlen(frase);

    return t;
}

int main (){
    
    char frase[50];
    int tamanho;

    printf("Forneça uma frase:");
    fgets(frase, 50, stdin);
    tamanho = lerQuantidadePalavaras(frase) - 1;

    printf("Quantidadde de Palavras é : %d", tamanho);

    return 0;
}

