#include <stdio.h>
#define NUMERO 20

int main() {
    int vet[NUMERO];
    int i, j;
    int repetido;

    // leitura
    for(i = 0; i < NUMERO; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    // verificar repetidos
    for(i = 0; i < NUMERO; i++) {
        repetido = 0;

        // verifica se já apareceu antes
        for(j = 0; j < i; j++) {
            if(vet[i] == vet[j]) {
                repetido = 1;
                break;
            }
        }

        // se ainda não apareceu, procura repetição depois
        if(repetido == 0) {
            for(j = i + 1; j < NUMERO; j++) {
                if(vet[i] == vet[j]) {
                    printf("Numero repetido: %d\n", vet[i]);
                    break;
                }
            }
        }
    }

    return 0;
}