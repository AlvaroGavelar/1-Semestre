/*
Imagine uma matriz 5x5 que representa o mapa de um jogo simples. O número 0 representa o
caminho livre, o número 1 representa uma parede intransponível, e o número 2 representa a posição
inicial do nosso personagem. Faça um programa que:

• Inicialize a matriz estaticamente no código com um caminho válido e algumas paredes.

• 2. Peça para o usuário digitar um caractere para mover o personagem: 'W' (para cima), 'S'
(para baixo), 'A' (para esquerda) ou 'D' (para direita).

• 3. O programa deve calcular a nova posição. Se o movimento for em direção a uma parede
(1) ou para fora dos limites da matriz (5x5), exiba a mensagem "Colisão! Movimento
inválido." e mantenha o personagem no mesmo lugar. Caso contrário, atualize a matriz (a
posição antiga vira 0 e a nova vira 2) e mostre o mapa atualizado.

*/

#include <stdio.h>

int main(){
    int i, j, novaLinha, novaColuna, menu;
    int linhaJogador = 0, colunaJogador = 0;
    char movi;
    int m[5][5] = {
        {2,0,0,1,0},
        {1,1,0,1,0},
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,0,0,0,0}
    };


    //Mapa Inicial
    printf("Mapa Inicial:\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }

    do{
    //Movimentos
    printf("\nDigite um Movimento (W, A, S, D):");
    scanf("%c", &movi);

    novaLinha = linhaJogador;
    novaColuna = colunaJogador;

    switch(movi){
        case 'W':
        case 'w':
            novaLinha--;
            break;
        case 'S':
        case 's':
            novaLinha++;
            break;
        case 'A':
        case 'a':
            novaColuna--;
            break;
        case 'D':
        case 'd':
            novaColuna++;
            break;
        default:
            printf("\nMovimento Invalido\n");
            return 0;
    }

    if(novaLinha < 0 || novaLinha >= 5 || novaColuna < 0 || novaColuna >=5)
        printf("\nColisao! Movimento invalido.\n");
    else
        if(m[novaLinha][novaColuna] == 1)
            printf("\nColisao! Movimento invalido.\n");
            else{
                m[linhaJogador][colunaJogador] = 0;
                m[novaLinha][novaColuna] = 2;

                linhaJogador = novaLinha;
                colunaJogador = novaColuna;

                printf("\nMovimento realizado!\n");
            }

    printf("\nMapa atualizado:\n");

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf("[%d]", m[i][j]);
        }
        printf("\n");
    }

    printf("\n1 - Para Continuar:");
    scanf("%d", &menu);
    int c = getchar();

    }while(menu == 1);

    return 0;
}