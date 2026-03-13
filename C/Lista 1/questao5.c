#include <stdio.h>
    int main(){
    float centigrados, fahrenheit;
        printf("\nQual a temperatura em Fahrenheit:");
        scanf("%f", &fahrenheit);
        centigrados=5*(fahrenheit-32)/9;
        printf("\nO valor em centrigrados é igual a %.1f:", centigrados);
        return 0;
    }