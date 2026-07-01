#include <stdio.h>
#include <string.h>

int buscarCorredor(char nome[][50], int qtd, char novoNome[]){
    int i;

    for(i = 0; i < qtd; i++){
        if(strcmp(nome[i], novoNome) == 0){
            //Ja Cadastrado
            return i;
        }
    }

    //Não Existe
    return -1;
}

int corredorMaisFrequente(int participacoes[], int qtdCorredores){
    int i;

    int maior = participacoes[0];

    for(i = 1; i < qtdCorredores; i++){
        if(participacoes[i] > maior)
            maior = participacoes[i];
    }

    return maior;
}

void limpaBuffer(){
    int ch;

    do{
        ch = getchar();
    }while(ch != '\n' && ch != EOF);

}


int main(){
    char nome[100][50];
    char novoNome[50];
    int qtdParticipacoes[100] = {0};
    int Corridas, totalCorredores = 0;
    char nomes[50];

    //Saber a Quantidade de Corridas
    printf("\nForneça A Quantidade de Corridas:\n");
    scanf("%d", &Corridas);
    limpaBuffer();

    for(int qtd = 0; qtd < Corridas; qtd++){

        int participantes, erro;

        do{
            printf("\nCorrida %d\n", Corridas + 1);
            printf("\nForneça A Quantidade de Participantes:\n");
            scanf("%d", &participantes);
            limpaBuffer();
        }while(erro == 1);

        char corridaAtual[100][50];

        for(int i = 0; i < participantes; i++){
            int repetido;
            

            do{
                repetido = 0;

                printf("\nForneca o Nome do Participante:\n");
                fgets(nomes, 50, stdin);

                //Tira o \n
                nomes[strcspn(nomes, "\n")] = '\0';

                for(int j = 0; j < i; j++){
                    if(strcmp(corridaAtual[j], nomes) == 0){
                        repetido = 1;
                        printf("\nParticipante Repetido Nessa Corrida!\n");
                        break;
                    }
                }

            }while(repetido == 1);

            strcpy(corridaAtual[i], nomes);

            int indice;

            indice = buscarCorredor(nome, totalCorredores, nomes);

            if(indice == -1){
                strcpy(nome[totalCorredores], nomes);
                qtdParticipacoes[totalCorredores] = 1;
                totalCorredores++;
            }
            else
                qtdParticipacoes[indice]++;
        }
    }

    printf("\n===== PARTICIPACOES =====\n");

    for(int i = 0; i < totalCorredores; i++){
        printf("\n%s - %d Participacoes\n", nome[i], qtdParticipacoes[i]);
    }

    int maior = corredorMaisFrequente(qtdParticipacoes, totalCorredores);

    printf("\n===== CAMPEAO(ES) =====\n");

    for(int i = 0; i < totalCorredores; i++){
        if(qtdParticipacoes[i] == maior){
            printf("\n%s - %d Participacoes\n", nome[i], qtdParticipacoes[i]);
        }
    }

    return 0;
}