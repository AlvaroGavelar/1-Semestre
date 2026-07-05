    /*
    Faça um programa que leia uma matriz A 12x13 de inteiros e divide todos os 13 elementos de cada
    uma das 12 linhas de A pelo valor do maior elemento em módulo daquela linha. Escrever a matriz A
    lida e a matriz A modificada.
    */

    #include <stdio.h>
    #define COLUNA 3
    #define LINHA 2


    int main(){
        float mA[LINHA][COLUNA], mAm[LINHA][COLUNA];
        int lin, col, maior[LINHA], valor;

        //Preenche a Matriz
        for(lin = 0; lin < LINHA; lin++){
            for(col = 0; col < COLUNA; col++){
                printf("Forneça um Numero Inteiro:");
                scanf("%f", &mA[lin][col]);
            }
        }

        printf("\n");

        //Maior de Cada Linha
        for(lin = 0; lin < LINHA; lin++){
            maior[lin] = mA[lin][0];
            for(col = 0; col < COLUNA; col++){

            if(maior[lin] < mA[lin][col])
                maior[lin] = mA[lin][col];
            }
        }

        //Copia a Matriz
        for(lin = 0; lin < LINHA; lin++){
            for(col = 0; col < COLUNA; col++){
                mAm[lin][col] = mA[lin][col]/maior[lin];
            }
        }

        //Imprime a Matriz
        for(lin = 0; lin < LINHA; lin++){
            for(col = 0; col < COLUNA; col++){
                printf("[%.1f]\t", mA[lin][col]);
            }
            printf("\n");
        }

        printf("\n");

        //Imprime a Matriz Copiada
        for(lin = 0; lin < LINHA; lin++){
            for(col = 0; col < COLUNA; col++){
                printf("[%.1f]\t", mAm[lin][col]);
            }
            printf("\n");
        }

        return 0;
    }