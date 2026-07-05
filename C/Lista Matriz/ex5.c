/*
Em um tabuleiro de Batalha Naval de tamanho 6x6, o usuário está tentando adivinhar onde estão os
navios inimigos. Faça um programa que:
1. Preencha uma matriz de inteiros onde a maioria das posições é 0 (água) e exatamente 4
posições sorteadas por você contêm o número 5 (navios ocultos).
2. O usuário deve digitar uma linha e uma coluna para dar um "disparo".
3. Se ele acertar o navio (5), exiba "Fogo! Navio destruído!".
4. Se ele acertar a água (0), o programa deve fazer uma varredura automática na mesma linha e
na mesma coluna do disparo e contar quantos navios estão naquela "linha de visão" do radar,
exibindo: "Água! Mas o radar detectou X navio(s) nessa linha/coluna".
*/

#include <stdio.h>

int main(){
    int col, lin, erro, contador, linha, coluna, radar;
    int m[6][6] = {0,0,0,0,0,5,
                   0,5,0,0,0,0,
                   0,0,0,0,0,0,
                   0,0,0,5,0,0,
                   0,0,0,0,0,0,
                   0,5,0,0,0,0};
                   
    contador = 4;
    do{

        do{
            erro = 0;

            printf("\nForneca uma Linha:");
            scanf("%d", &linha);

            printf("Forneca uma coluna:");
            scanf("%d", &coluna);

            if(linha < 0 || linha > 5 || coluna < 0 || coluna > 5){
                erro = 1;
                printf("\nPosicao invalida!\n");
            }
        }while(erro != 0);

        if(m[linha][coluna] == 5){
            printf("\nFogo! Navio destruído!\n");
            contador--;
            m[linha][coluna] = 0;
        }
        else{
            radar = 0;
            for(lin = 0; lin < 6; lin++){
                if(m[lin][coluna] == 5){
                    radar++;
                }
            }
            for(col = 0; col < 6; col++){
                if(m[linha][col] == 5){
                    radar++;
                }
            }

            printf("Agua! Radar detectou %d navio(s)", radar);
        }   

    }while(contador != 0);

    printf("\nParabens! Todos Navios Foram Derrotados!!\n");

    return 0;
}