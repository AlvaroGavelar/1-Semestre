/*
Crie uma estrutura Aluno com:
• matrícula;
• nome;
• três notas;
• média;
• situação.
Cadastre até 30 alunos.
O programa deve apresentar um menu:
1 - Cadastrar aluno
2 - Listar alunos
3 - Consultar aluno por matrícula
4 - Exibir aprovados
5 - Exibir reprovados
0 - Sair
A média deve ser calculada automaticamente. Considere aprovação com média maior ou igual a 60.
*/

#include <stdio.h>
#include <string.h>
#define QTD_AlUNO 30

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

typedef struct{
    int matricula;
    char nome[100];
    float nota1;
    float nota2;
    float nota3;
    float media;
    char situacao[15];
}TAluno;

int procuraAluno(TAluno tA[], int ultimaPos, int matricula){
    int i;
    for(i = 0; i <= ultimaPos; i++){
        if(tA[i].matricula == matricula);
            return i;
    }
    return -1;
}

int cadastroAluno(TAluno tA[], int tamanho, int *ultimaPos){
    int mat, achou, tam;

    //Matricula
    if(*ultimaPos == tamanho - 1){
        return 0;
    }
    else
        do{
            printf("\nNumero De Matricula Do Aluno:");
            scanf("%d", &mat);
            limpaBuffer();

            if(mat < 0){
                achou = 1;
                printf("Tem Que ser Maior ou Igual a 0");

                if(procuraAluno(tA, *ultimaPos, mat) != -1){
                    printf("\nMatricula Ja Cadastrada!!\n");
                    return 0;
                }
            }
        }while(achou != 0);

        (*ultimaPos)++;

        tA[*ultimaPos].matricula = mat;

        //Nome
        do{
            achou = 0;
            printf("\nNome:");
            fgets(tA[*ultimaPos].nome, 100, stdin);

            tam = strlen(tA[*ultimaPos].nome);
            if(tA[*ultimaPos].nome[tam - 1] == '\n')
                tA[*ultimaPos].nome[tam - 1] = '\0';
            else
                limpaBuffer();

            if(strlen(tA[*ultimaPos].nome) == 0)
                printf("Nome nao pode ser vazio!\n");

        }while(strlen(tA[*ultimaPos].nome) == 0);


        //Nota
        do{
            achou = 0;

            printf("Nota 1:");
            scanf("%f", &tA[*ultimaPos].nota1);

            if(tA[*ultimaPos].nota1 < 0){
                achou = 1;
                printf("\nNota Tem Que Ser Maior que 1\n");
            }

            printf("Nota 2:");
            scanf("%f", &tA[*ultimaPos].nota2);

            if(tA[*ultimaPos].nota2 < 0){
                achou = 1;
                printf("\nNota Tem Que Ser Maior que 1\n");
            }

            printf("Nota 3:");
            scanf("%f", &tA[*ultimaPos].nota3);

            if(tA[*ultimaPos].nota3 < 0){
                achou = 1;
                printf("\nNota Tem Que Ser Maior que 1\n");
            }
        
        }while(achou != 0);

        //Media
        tA[*ultimaPos].media = (tA[*ultimaPos].nota1 + tA[*ultimaPos].nota2 + tA[*ultimaPos].nota3)/3;

        if(tA[*ultimaPos].media >= 60){
            strcpy(tA[*ultimaPos].situacao, "Aprovado");
        }
        else
            strcpy(tA[*ultimaPos].situacao, "Reprovado");

    return 1;
}

void listarAlunos(TAluno tA[], int ultimaPos){
    int i;

    if(ultimaPos == -1){
        printf("\nNenhum Aluno Cadastrado!\n");
        return;
    }
    else
        for(i = 0; i <= ultimaPos; i++){
            printf("\n========================");
            printf("\nMatricula: %d", tA[i].matricula);
            printf("\nNome: %s", tA[i].nome);
            printf("\nNota 1: %.2f", tA[i].nota1);
            printf("\nNota 2: %.2f",tA[i].nota2);
            printf("\nNota 3: %.2f", tA[i].nota3);
            printf("\nMedia: %.2f", tA[i].media);
            printf("\nSituacao: %s\n", tA[i].situacao);
        }

}

void consultaAluno(TAluno tA[], int ultimaPos){
    int cod, pos;

    if(ultimaPos == -1){
        printf("\nNenhum Aluno Cadastrado!\n");
        return;
    }

    printf("\nMatricula do Aluno:");
    scanf("%d", &cod);

    pos = procuraAluno(tA, ultimaPos, cod);

    if(pos == -1){
        printf("\n Aluno Nao Cadastrado!\n");
        return;
    }

    printf("\n========================");
    printf("\nMatricula: %d", tA[pos].matricula);
    printf("\nNome: %s", tA[pos].nome);
    printf("\nNota 1: %.2f", tA[pos].nota1);
    printf("\nNota 2: %.2f", tA[pos].nota2);
    printf("\nNota 3: %.2f", tA[pos].nota3);
    printf("\nMedia: %.2f", tA[pos].media);
    printf("\nSituacao: %s\n", tA[pos].situacao);

}

void exibirAprovados(TAluno tA[], int ultimaPos){
    int i, encontrou = 0;

    if(ultimaPos == -1){
        printf("\nNenhum Aluno Cadastrado!\n");
        return;
    }

    printf("\n=== ALUNOS APROVADOS ===\n");

    for(i = 0; i <= ultimaPos; i++){
        if(tA[i].media >= 60){
            encontrou = 1;

            printf("\nMatricula: %d", tA[i].matricula);
            printf("\nNome: %s", tA[i].nome);
            printf("\nMedia: %.2f\n", tA[i].media);
        }
    }

    if(encontrou == 0)
        printf("\nNenhum aluno aprovado.\n");
}

void exibirReprovados(TAluno tA[], int ultimaPos){
    int i, encontrou = 0;

    if(ultimaPos == -1){
        printf("\nNenhum Aluno Cadastrado!\n");
        return;
    }

    printf("\n=== ALUNOS REPROVADOS ===\n");

    for(i = 0; i <= ultimaPos; i++){
        if(tA[i].media < 60){
            encontrou = 1;

            printf("\nMatricula: %d", tA[i].matricula);
            printf("\nNome: %s", tA[i].nome);
            printf("\nMedia: %.2f\n", tA[i].media);
        }
    }

    if(encontrou == 0)
        printf("\nNenhum aluno reprovado.\n");
}

int main(){
    TAluno tA[QTD_AlUNO];
    int ultimaPos = -1;
    int opcao;

    do{
        printf("\n\n===== MENU =====");
        printf("\n1 - Cadastrar aluno");
        printf("\n2 - Listar alunos");
        printf("\n3 - Consultar aluno por matricula");
        printf("\n4 - Exibir aprovados");
        printf("\n5 - Exibir reprovados");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                if(cadastroAluno(tA, QTD_AlUNO, &ultimaPos) == 0){
                    printf("\nAluno Ja Cadastrado!!\n");
                }
                else
                    printf("\nCadastro Realizado!!\n");
                break;
            case 2:
                listarAlunos(tA, ultimaPos);
                break;
            case 3:
                consultaAluno(tA, ultimaPos);
                break;
            case 4:
                exibirAprovados(tA, ultimaPos);
                break;
            case 5:
                exibirReprovados(tA, ultimaPos);
                break;
            case 0:
                printf("\nPrograma encerrado.\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    }while(opcao != 0);

    return 0;
}