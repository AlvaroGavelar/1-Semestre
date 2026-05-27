/*Cadastro e busca de alunos
Crie um programa que cadastre até 10 alunos.

Para cada aluno:

nome OK
nota 1 OK 
nota 2 OK

Depois o programa deve:
calcular média de cada aluno OK
mostrar o aluno com maior média OK
permitir buscar um aluno pelo nome OK
informar se foi aprovado (média >= 60)*/

#include <stdio.h>
#include <string.h>
#define QUANTIDADE_ALUNOS 10

void cadastro(char nome[QUANTIDADE_ALUNOS][50], int *qtd, char novoNome[]){
    int i, achou = 0;

    for(i=0;i<*qtd;i++){
        
        //Verificar se ja existe
        if(strcmp(nome[i], novoNome) == 0){
            printf("\nAluno já Cadastrado!!\n");
            achou = 1; //Já Cadastrado
        }


       if(achou == 0){
            if(*qtd < QUANTIDADE_ALUNOS){
                strcpy(nome[*qtd],novoNome);
                (*qtd)++;
                printf("\nAluno Cadastrado com Sucesso!!\n");
            }
            else
                printf("\nLimite de Alunos Atingido\n");
        }
    }
}   

    void lerNotas(char nome[][50], float nota1[], float nota2[], int qtd){
        int i;

        for(i=0;i<qtd;i++){

            printf("\n ALuno: %s", nome[i]);
            printf("\nForneça a Primeira Nota:");
            scanf("%df", &nota1[i]);
                while(nota1[i] < 0){ 
                    printf("\nNota invalida! Digite novamente: ");
                    scanf("%f", &nota1[i]);
                }
            
            printf("\nForneça a Segunda Nota:");
            scanf("%f", &nota2[i]);
                while(nota2[i]<0){
                    printf("\nNota invalida! Digite novamente: ");
                    scanf("%f", &nota2[i]);
                }
            }
        }

    void media(char nome[QUANTIDADE_ALUNOS][50], float nota1[], float nota2[], int qtd){
        int i, indiceMaior = 0;
        float media = 0,
              maiorMedia = 0;

        for(i=0; i < qtd; i++){
            media = (nota1[i] + nota2[i])/2;
            printf("\nAluno: %s", nome[i]);
            printf("\nMedia: %.2f\n", media);
            
            //Ver se é a maior media
            if(media > maiorMedia){
                maiorMedia = media;
                indiceMaior = i;
            }
        }

        printf("\n===== MELHOR ALUNO =====\n");
        printf("Aluno: %s\n", nome[indiceMaior]);
        printf("Maior media: %.2f\n", maiorMedia);
    }

    void mostrarNotas(float nota1[], float nota2[], int qtd){
        int i;

        for(i = 0; i < qtd; i++){

            printf("\nNota 1: %.2f", nota1[i]);
            printf("\nNota 2: %.2f\n", nota2[i]);

        }
    }

    void buscaNome(char nome[QUANTIDADE_ALUNOS][50], int qtd, char compararaNome[50],
    float nota1[], float nota2[]){
        int i, achou = 0;
        
        for(i=0; i < qtd; i++){
            if(strcmp(nome[i],compararaNome) == 0){
                printf("\n===== ALUNO ENCONTRADO =====\n");
                printf("Aluno: %s\n", nome[i]);
                mostrarNotas(nota1, nota2, qtd);
            }
            else
            printf("\nAluno não Encontrado!!\n");
        }
    }

    int aprovacao(char nome[QUANTIDADE_ALUNOS][50],float nota1[], float nota2[], int qtd){
        int i;

        for(i=0, i < qtd; i++){
            if()
        }

    }