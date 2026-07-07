/*
Crie uma estrutura Aluno com os campos:
• matrícula;
• nome;
• nota1;
• nota2.
Leia os dados de um aluno e exiba:
• nome;
• matrícula;
• média das duas notas;
• situação: Aprovado se a média for maior ou igual a 60 e Reprovado caso contrário
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

int main(){
    Aluno a;
    int achou, tam;
    float media;

    do{
        achou = 0;

        printf("Numero De Matricula:");
        scanf("%d", &a.matricula);
        limpaBuffer();

        printf("Nome Do ALuno:");
        fgets(a.nome, 100, stdin);
        
        tam = strlen(a.nome);
        if(a.nome[tam-1] == '\n')
            a.nome[tam-1] = '\0';

        if(strlen(a.nome) == '\0'){
            achou = 1;
            printf("\nNome Vazio!\n");
        }

        printf("Nota 1:");
        scanf("%f", &a.n1);

        printf("Nota 2:");
        scanf("%f", &a.n2);

        limpaBuffer();

        media = 0;
        media = (a.n1 + a.n2)/2;

        if(media >= 60)
            printf("\nAluno Aprovado Com Media de: %.2f\n", media);
        else
            printf("\nAluno Reprovado Com Media de: %.2f\n", media);
        

    }while(achou != 0);

    return 0;
}