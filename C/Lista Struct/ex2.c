/*
Utilize a estrutura Aluno e cadastre 5 alunos.
Ao final, exiba:
• os dados de todos os alunos;
• a média da turma;
• o nome do aluno com a maior média.
*/

#include <stdio.h>
#include <string.h>
#define QTD_ALUNO 5

typedef struct{
    int matricula;
    char nome[100];
    float n1;
    float n2;
}Aluno;

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

int main(){
    Aluno Al[QTD_ALUNO];
    int i, achou, tam;
    float media[QTD_ALUNO];

    for(i = 0; i < QTD_ALUNO; i++){
        do{
            achou = 0;

        printf("\nAluno: %d\n", i + 1);

        printf("Numero De Matricula:");
        scanf("%d", &Al[i].matricula);
        limpaBuffer();

        printf("Nome Do ALuno:");
        fgets(Al[i].nome, 100, stdin);
        
        tam = strlen(Al[i].nome);
        if(Al[i].nome[tam-1] == '\n')
            Al[i].nome[tam-1] = '\0';

        if(strlen(Al[i].nome) == '\0'){
            achou = 1;
            printf("\nNome Vazio!\n");
        }

        printf("Nota 1:");
        scanf("%f", &Al[i].n1);

        printf("Nota 2:");
        scanf("%f", &Al[i].n2);

        limpaBuffer();

        media[i] = 0;
        media[i] = (Al[i].n1 + Al[i].n2)/2;

        }while(achou != 0);
    }

    for(i = 0; i < QTD_ALUNO; i++){

        printf("\nAluno: %s\n", Al[i].nome);
        printf("Numero De Matricula: %d", Al[i].matricula);
        
        if(media[i] >= 60)
            printf("\nAluno Aprovado Com Media de: %.2f\n", media[i]);
        else
            printf("\nAluno Reprovado Com Media de: %.2f\n", media[i]);
    }

    return 0;
}