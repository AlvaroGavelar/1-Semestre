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
#define NUMERO_MAXIMO_FUNCIONARIO 20
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

void adcVendas(int m[][QTD_DIAS], char Nome[][100],int melhorVenda[], int qtdVenda[]){
    int lin, col, i, venda, erro;

    for(lin = 0; lin < NUMERO_MAXIMO_FUNCIONARIO; lin++){

        printf("\nFuncionario: %s \n", Nome[lin]);
        melhorVenda[lin] = 0;
        qtdVenda[lin] = 0;

        for(col = 0; col < QTD_DIAS; col++){

            do{
                erro = 0;

                printf("\nVendas do dia %d:", col + 1);
                scanf("%d", &venda);

                if(venda < 0){
                    erro = 1;
                    printf("\nValor tem que ser maior que 0!!\n");
                    break;
                }
                else
                    m[lin][col] = venda;
                    qtdVenda[lin]+=venda;
                    
                    if(melhorVenda[lin] < venda)
                    melhorVenda[lin] = venda;
            }while(erro != 0);
        }
    }
    limpaBuffer();
}

void mtVendaDia(int m[][QTD_DIAS], char nome[][100], int totalVenda[]){
    int col, lin;

    printf("\n--- TABELA DE VENDAS ---\n");
    printf("Nome \t\tDia \t\tVendas");
    
    for(lin = 0; lin < NUMERO_MAXIMO_FUNCIONARIO; lin++){
        for(col = 0; col < QTD_DIAS; col++){
            printf("\n%s\t\t%d.\t\t%d", nome[lin], col+1, m[lin][col]);
        }
        printf("\nTotal de Vendas = %d\n", totalVenda[lin]);
    }
}

void mtMelhorDia(int m[][QTD_DIAS], char nome[][100], int melhorVenda[]){
    int lin, col;

    printf("\n--- DIAS COM MAIOR VENDA DE CADA FUNCIONARIO ---\n");

    for(lin = 0; lin < NUMERO_MAXIMO_FUNCIONARIO; lin++){

        printf("\n%s obteve (%d vendas) no(s) dia(s): ",
               nome[lin],
               melhorVenda[lin]);

        for(col = 0; col < QTD_DIAS; col++){

            if(m[lin][col] == melhorVenda[lin])
                printf("%d ", col + 1);
        }

        printf("\n");
    }
}

void melhorVendedor(char nome[][100], int qtdVenda[]){
    int i, maior;

    maior = qtdVenda[0];

    for(i = 0; i < NUMERO_MAXIMO_FUNCIONARIO; i++){
        if(qtdVenda[i] > maior)
            maior = qtdVenda[i];
    }

    printf("\n--- MAIOR(ES) VENDEDOR(ES) DA SEMANA ---\n");

    for(i = 0; i < NUMERO_MAXIMO_FUNCIONARIO; i++){
        if(qtdVenda[i] == maior){
            printf("\n%s - Total: %d vendas\n", nome[i], qtdVenda[i]);
        }
    }
    printf("\n");
}

int main(){
    int m[NUMERO_MAXIMO_FUNCIONARIO][QTD_DIAS];
    int melhorDia[NUMERO_MAXIMO_FUNCIONARIO], totalVenda[NUMERO_MAXIMO_FUNCIONARIO];
    char nome[NUMERO_MAXIMO_FUNCIONARIO][100];
    char novoNome[100];
    int i, lin, col;

    lerString(nome, NUMERO_MAXIMO_FUNCIONARIO, novoNome);
    adcVendas(m,nome, melhorDia, totalVenda);
    mtVendaDia(m, nome, totalVenda);
    mtMelhorDia(m,nome,melhorDia);
    melhorVendedor(nome, totalVenda);

    return 0;
}