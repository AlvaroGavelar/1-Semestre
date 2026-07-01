#include <stdio.h>
#include <string.h>

#define TAM_NOME 100
#define MAX_BARRACAS 20

/* Busca o Nome Das Barracas e Retorna A Posicao se Achado */
int buscaLoja(char nomebarraca[][TAM_NOME], int quantidade, char nome[]){
    int i;

    for(i = 0; i < quantidade; i++){

        /* Loja Existe */
        if(strcmp(nomebarraca[i], nome) == 0){
            return i;
        }
    }

    /* Não Existe */
    return -1;
}


void limpaBuffer(){
    char ch;
    do{
        ch = getchar();
    }while(ch != '\n' && ch != EOF);
}

int main(){
    int i, semanas, repetido;
    char nomeBarraca[MAX_BARRACAS][TAM_NOME];
    char nome[TAM_NOME];
    int totalBarracas = 0;
    int vendas;
    int vVendas[MAX_BARRACAS] = {0};
    char barracaSemana[MAX_BARRACAS][TAM_NOME];

    printf("\nQuantidade de Semanas:\n");
    scanf("%d", &semanas);
    limpaBuffer();

    for(int semana = 0; semana < semanas; semana++){
        int nParticipantes;

        printf("\nSemana %d\n", semana + 1);
        printf("\nForneça a Quantidade de Participantes:\n");
        scanf("%d", &nParticipantes);
        limpaBuffer();

        for(i = 0; i < nParticipantes; i++){
            do{
                repetido = 0;                
                
                printf("\nNome Da Barraca:\n");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                

                for(int j = 0; j < i; j++){
                    if(strcmp(barracaSemana[j], nome) == 0){
                        repetido = 1;
                        printf("\nNome repetido na semana!\n");
                        break;
                    }
                }
            }while(repetido);

            /* Guarda o Nome da Semana */
            strcpy(barracaSemana[i], nome);


            printf("\nQuantidade de Vendas:\n");
            scanf("%d", &vendas);
            limpaBuffer();

            /* Pega o Indice para o Ranking */
            int indice = buscaLoja(nomeBarraca, totalBarracas, nome);
            
            /* Soma Quantidade de Vendas */

            /* Novo Barraca */
            if(indice == -1){
                strcpy(nomeBarraca[totalBarracas], nome);
                vVendas[totalBarracas] = vendas;
                totalBarracas++;
            }
            else
                vVendas[indice] += vendas;
        }
    }

    printf("\n===== RANKING GERAL =====\n");
    for(i = 0; i < totalBarracas; i++){
        printf("\nBarraca %s - %d Vendas\n", nomeBarraca[i], vVendas[i]);
    }

    /* Maior numero de Vendas */
    int maior = vVendas[0];

    /* Verificar Se tem Maior */
    for(i = 0; i < totalBarracas; i++){
        if(vVendas[i] > maior){
            maior = vVendas[i];
        }
    }

    printf("\n===== CAMPEAO(ES) =====\n");

    for(i = 0; i < totalBarracas; i++){
        if(vVendas[i] == maior){
            printf("\nBarraca %s - %d Vendas\n", nomeBarraca[i], vVendas[i]);
        }
    }

    return 0;
}