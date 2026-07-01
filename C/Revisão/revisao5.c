#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 15600
#define TAM_NOME 101

// Procura um jogador no ranking geral
// Retorna a posição dele ou -1 se não existir
int buscarJogador(char jogadores[][TAM_NOME], int total, char nome[])
{
    int i;

    for(i = 0; i < total; i++)
    {
        if(strcmp(jogadores[i], nome) == 0)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // Guarda os nomes dos jogadores
    char jogadores[MAX_JOGADORES][TAM_NOME];

    // Guarda a pontuação total dos jogadores
    int pontos[MAX_JOGADORES] = {0};

    // Quantidade de jogadores únicos cadastrados
    int totalJogadores = 0;

    int S; // quantidade de semanas

    printf("Digite a quantidade de semanas: ");
    scanf("%d", &S);
    getchar();

    // Loop das semanas
    for(int semana = 0; semana < S; semana++)
    {
        int N;

        printf("\nSemana %d\n", semana + 1);

        printf("Quantidade de participantes: ");
        scanf("%d", &N);
        getchar();

        // Loop dos jogadores da semana
        for(int posicao = 0; posicao < N; posicao++)
        {
            char nome[TAM_NOME];

            printf("%do colocado: ", posicao + 1);

            fgets(nome, TAM_NOME, stdin);

            // Remove o ENTER
            nome[strcspn(nome, "\n")] = '\0';

            /*
                Procura se o jogador já existe
                no ranking geral
            */
            int indice = buscarJogador(
                jogadores,
                totalJogadores,
                nome
            );

            /*
                Calcula os pontos da posição

                1º -> 10
                2º -> 9
                3º -> 8
                ...
            */
            int pontuacao = 10 - posicao;

            // Jogador novo
            if(indice == -1)
            {
                strcpy(jogadores[totalJogadores], nome);

                pontos[totalJogadores] = pontuacao;

                totalJogadores++;
            }
            else
            {
                /*
                    Jogador já existe.

                    Soma os pontos na posição
                    correta do vetor.
                */
                pontos[indice] += pontuacao;
            }
        }
    }

    printf("\n===== RANKING GERAL =====\n");

    for(int i = 0; i < totalJogadores; i++)
    {
        printf("%s - %d pontos\n",
               jogadores[i],
               pontos[i]);
    }

    // Descobrir maior pontuação
    int maior = pontos[0];

    for(int i = 1; i < totalJogadores; i++)
    {
        if(pontos[i] > maior)
        {
            maior = pontos[i];
        }
    }

    printf("\n===== CAMPEAO(ES) =====\n");

    for(int i = 0; i < totalJogadores; i++)
    {
        if(pontos[i] == maior)
        {
            printf("%s - %d pontos\n",
                   jogadores[i],
                   pontos[i]);
        }
    }

    return 0;
}