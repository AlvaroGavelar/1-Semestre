/*
Utilize a estrutura Aluno do exercício1 e implemente as funções:
void lerAluno(struct Aluno *a);
void mostrarAluno(struct Aluno a);
float calcularMedia(struct Aluno a);
No programa principal, leia um aluno, calcule sua média e mostre seus dados.
*/

#include <stdio.h>
#include <string.h>

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

void lerAluno(Aluno *a){
    int achou, tam;
    do{
        achou = 0;

        printf("Numero De Matricula:");
        scanf("%d", &a->matricula);
        limpaBuffer();

        printf("Nome Do ALuno:");
        fgets(a->nome, 100, stdin);
        
        tam = strlen(a->nome);
        if(a->nome[tam-1] == '\n')
            a->nome[tam-1] = '\0';

        if(strlen(a->nome) == '\0'){
            achou = 1;
            printf("\nNome Vazio!\n");
        }

        printf("Nota 1:");
        scanf("%f", &a->n1);

        printf("Nota 2:");
        scanf("%f", &a->n2);

        limpaBuffer();
    }while(achou != 0);
}

float calcularMedia(Aluno a){
    float media;

    media = (a.n1 + a.n2) / 2;

    return media;
}

void mostraAluno(Aluno a){
    printf("\nAluno: %s", a.nome);
    printf("\nMatricula: %d", a.matricula);
    printf("\nMedia: %.2f", calcularMedia(a));
}

int main(){
    Aluno a;

    lerAluno(&a);
    mostraAluno(a);
}