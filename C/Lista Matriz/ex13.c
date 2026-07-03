/*
Uma empresa que possui 20 funcionários, guarda a quantidade vendida por cada um de seus
funcionários em cada um dos 7 dias dasemana. Faça um programa que:
• Mostre a quantidade vendida por cada funcionário;
• Mostre em qual ou quais dias da semana cada funcionário vendeu mais;
• O nome do funcionário ou funcionários com maior valor de venda na semana;
• Para cada dia da semana, a quantidade vendida por cada funcionário.
*/

#include <stdio.h>
#include <string.h>
#define NUMERO_MAXIMO_FUNCIONARIO 3
#define QTD_DIAS 7

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void lerString(char nome[][100], int tamanho, char novoNome[]){
    int i, j, repetido, tam;

    for(i = 0; i < tamanho; i++){
        do{
            repetido = 0;

            printf("\nForneça o Nome Do Funcionario:");
            fgets(novoNome, 100, stdin);

            tam = strlen(novoNome);
            if(novoNome[tam-1] == '\n')
                novoNome[tam - 1] = '\0';
            else    
                limpaBuffer();

            for(j = 0; j < tamanho; j++){
                if(strcmp(nome[j],novoNome) == 0){
                    repetido = 1;
                    printf("\nErro!! Nome Repetido!!\n");
                    break;
                }
            }
            
            if(repetido == 0)
                strcpy(nome[i],novoNome);

        }while(repetido != 0);
    }
}

void adcVendas(int m[][QTD_DIAS], char Nome[][100], int melhorVenda[]){
    int lin, col, i, venda;

    for(lin = 0; lin < NUMERO_MAXIMO_FUNCIONARIO; lin++){

        printf("\nFuncionario: %s \n", Nome[lin]);
        melhorVenda[lin] = 0;

        for(col = 0; col < QTD_DIAS; col++){

            printf("\nVendas do dia %d:", col + 1);
            scanf("%d", &venda);
            
            if(venda > 0)
                m[lin][col] = venda;
            
            if(melhorVenda[lin] < venda)
            melhorVenda[lin] = venda;
        }
    }
    limpaBuffer();
}

void mtVendaDia(int m[][QTD_DIAS], char nome[][100], int melhorVenda[]){
    int col, lin;

    printf("\n--Tabela de Venda--\n");
    
    for(lin = 0; lin < NUMERO_MAXIMO_FUNCIONARIO; lin++){
        printf("\nFuncionario: %s \n", nome[lin]);
        for(col = 0; col < QTD_DIAS; col++){
            printf("Nome %s\t\tDia %d\t\tVendas %d");
            printf("\n%s\t\t%d\t\t", nome[lin], m[lin][col]);
        }

    }
}

int main(){
    int m[NUMERO_MAXIMO_FUNCIONARIO][QTD_DIAS];
    int melhorDia[NUMERO_MAXIMO_FUNCIONARIO];
    char nome[NUMERO_MAXIMO_FUNCIONARIO][100];
    char novoNome[100];
    int i, lin, col;

    lerString(nome, NUMERO_MAXIMO_FUNCIONARIO, novoNome);
    adcVendas(m,nome, melhorDia);
    mtVendaDia(m, nome, melhorDia);

    return 0;
}