/*
Cadastre 8 alunos com:
• matrícula;
• nome;
• curso;
• média final.
Leia uma matrícula e informe se o aluno foi encontrado.
Caso seja encontrado, exiba todos os seus dados
*/

#include <stdio.h>
#include <string.h>
#define QTD_ALUNO 2

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

typedef struct{
    int matricula;
    char nome[100];
    char curso[100];
    float mediaF;
}Alunos;

void cadastroALunos(Alunos a[], int tamanho){
    int i, achou, tam;

    for(i = 0; i < tamanho; i++){
        do{
            achou = 0;

            printf("\nAluno: %d\n", i + 1);

            printf("Numero De Matricula:");
            scanf("%d", &a[i].matricula);
            limpaBuffer();

            printf("Nome Do ALuno:");
            fgets(a[i].nome, 100, stdin);
            
            tam = strlen(a[i].nome);
            if(a[i].nome[tam-1] == '\n')
                a[i].nome[tam-1] = '\0';
            else
                limpaBuffer();

            if(strlen(a[i].nome) == '\0'){
                achou = 1;
                printf("\nNome Vazio!\n");
            }

            printf("Nome Do Curso:");
            fgets(a[i].curso, 100, stdin);

            tam = strlen(a[i].curso);
            if(a[i].curso[tam-1] == '\n')
                a[i].curso[tam-1] = '\0';
            else
                limpaBuffer();

            if(strlen(a[i].curso) == '\0'){
                achou = 1;
                printf("\nNome Vazio!\n");
            }

            printf("Media Final:");
            scanf("%f", &a[i].mediaF);
            limpaBuffer();
        }while(achou != 0);
    }
}

int procuraMatri(Alunos a[], int tamanho){
    int i, pMatri;

    printf("\nForneca o Numero de Matricula a Procura:");
    scanf("%d", &pMatri);

    for(i = 0; i < tamanho; i++){
        if(a[i].matricula == pMatri){
            return i;
        }
    }

    return -1;
}

int main(){
    Alunos a[QTD_ALUNO];
    int i, achou, indice, opcao;

        cadastroALunos(a, QTD_ALUNO);

        indice = procuraMatri(a, QTD_ALUNO);
        
        if(indice != -1){
            printf("\nMatricula: %d", a[indice].matricula);
            printf("\nAluno: %s", a[indice].nome);
            printf("\nCurso: %s", a[indice].curso);
            printf("\nMedia Final: %.2f", a[indice].mediaF);
        }
        else
        printf("\nAluno Nao Encontrado\n");

    return 0;
}