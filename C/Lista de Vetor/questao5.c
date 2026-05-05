#include <stdio.h>
#define IDADE 15

int main(){
    int vet[IDADE], i, j, cont, maiorF = 0, moda = 0;

    // Leitura
    for(i = 0; i < IDADE; i++){
        printf("Digite a idade %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // Moda
    for(i = 0; i < IDADE; i++){
        cont = 0;

        for(j = 0; j < IDADE; j++){
            if(vet[i] == vet[j]){
                cont++;
            }
        }

        if(cont > maiorF){
            maiorF = cont;
            moda = vet[i];
        }
    }

    printf("Moda: %d (aparece %d vezes)\n", moda, maiorF);

    return 0;
}