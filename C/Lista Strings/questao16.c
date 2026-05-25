/*Escreva um programa que gerencie uma lista de presença de uma turma com até 30 alunos. O
programa deve apresentar um menu com as seguintes opções:
1. Adicionar aluno
2. Remover aluno
3. Listar todos os alunos
4. Sair
Observações:
• Não permitir adicionar alunos duplicados;
• Não permitir remover um aluno que não existe;
• Manter a lista sempre ordenada alfabeticamente;
• Após cada operação, o menu deve ser reapresentado*/

#include <stdio.h>
#include <string.h>
#define QUANTIDADE_AlUNOS 50

int adicionarAluno(char alunos[][50], int quantidade, char nome[]){
    int i, j;

    //Verificar cadastro
    for(i = 0; i < quantidade; i++){

        if(strcmp(nome, alunos[i]) == 0){
            printf("Aluno já cadastrado!");
            return 1;
        }
    }

    //Adicionar Aluno
    for(j = 0; nome[j] != '\0'; j++){

        alunos[quantidade][j] = nome[j]; 
    }
    
    alunos[quantidade][j] = '\0'; //Finalizar String

    //Ordenar
    for(i = 0; i < quantidade; i++){

        if(strcmp(alunos[i], alunos[i+1]) > 0){

            char temp[50]; //String temporaria

            strcpy(temp, alunos[i]);
            strcpy(alunos[i], alunos[i + 1]);
            strcpy(alunos[i + 1], temp);

        }
    }

        printf("Aluno Cadastrado!\n");
        return 0;
}

int removerAluno(char alunos[][50], int quantidade, char nome[]){
    int i, j;

    //Procurar Aluno
    for(i = 0; i < quantidade; i++){

        if(strcmp(nome, alunos[i]) == 0){
            
            //Deslocar Aluno
            for(j = 0; j < quantidade; j++){

                strcpy(alunos[j], alunos[j+1]);

            }

            printf("Aluno removido!\n");

            return 1;
        }
    }
    printf("Aluno não Existente!\n");
    return 0;
}

void listarAlunos(char alunos[][50], int quantidade){
    int i;

    for(i = 0; i <  quantidade; i++){

        //Posição e Nome do Aluno
        printf("Alunos: %d - %s\n", i + 1, alunos[i]); 
    }
}   

int main(){

    char alunos[30][50];
    char nome[50];
    int opcao = 0;
    int quantidade = 0;

    while(opcao != 4){
        
        printf("\n1 - Adicionar aluno\n");
        printf("2 - Remover aluno\n");
        printf("3 - Listar alunos\n");
        printf("4 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:

                printf("Digite o nome do aluno: ");
                fgets(nome, QUANTIDADE_AlUNOS, stdin);

                nome[strcspn(nome, "\n")] = '\0'; //Troca \n pelo \0

                if(adicionarAluno(alunos, quantidade, nome) == 0)
                    quantidade++;
                
                break;

            case 2:

                printf("Digite o nome do aluno: ");
                fgets(nome, QUANTIDADE_AlUNOS, stdin);

                nome[strcspn(nome, "\n")] = '\0';

                if(removerAluno(alunos, quantidade, nome) == 1);
                    quantidade--;

                break;

            case 3:

                listarAlunos(alunos, quantidade);
                break;

            case 4:

                printf("Programa Encerrado! \n");
                break;
            
            default:
                
                printf("Opção Invalida! \n");
        }
    }
    return 0;
}