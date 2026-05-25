/*Implemente uma função que compare duas strings e retorne 0 se forem iguais, e 1 se forem
diferentes.
Obs.: não é permitido o uso de funções da biblioteca string.h*/

#include <stdio.h>

int compararStrings(char str1[],char str2[]){
    int i = 0;
    
    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i] != str2[i]){
            return 1;
        }
        i++;
    }
    if(str1[i] == '\0' && str2[i] == '\0'){
        return 0;
    }
    return 1;
}

int main(){
    char a[50];
    char b[50];

    printf("Digite a primeira string: ");
    fgets(a, 50, stdin);

    printf("Digite a segunda string: ");
    fgets(b, 50, stdin);

    if(compararStrings(a,b)==0){
        printf("Strings Iguais");
    }
    else
        printf("Strings Diferentes");

    return 0;
}