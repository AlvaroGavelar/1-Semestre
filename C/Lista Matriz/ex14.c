/*
Faça um programa que receba:
a) 10 nomes de produtos e armazene-os em um vetor (o nome é único);
b) O estoque de cada um destes produtos, em cada um dos 5 armazéns e armazene-os em uma
matriz 5X10;
c) O custo(preço) dos 10 produtos e armazene-os em um vetor.
Deve ser calculado e impresso:
• O total de itens armazenados em cada armazém;
• O total de itens armazenados de cada produto em todos os armazéns 
*/

#include <stdio.h>
#include <string.h>
#define QTD_PRODUTOS 3
#define QTD_ARMAZEM 5

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void lerString(char nome[][100], int tamanho, char nNome[100]){
    int i, j, erro, tam;

    for(i = 0; i < tamanho; i++){
        do{
            erro = 0;

            printf("Forneça o Nome do Produto (Unico):");
            fgets(nNome, 100, stdin);

            tam = strlen(nNome);
            if(nNome[tam-1] == '\n')
                nNome[tam-1] = '\0';
            else
                limpaBuffer();

            if(nNome[0] == '\0'){
                erro = 1;
                printf("\nNome nao pode ser vazio!\n");
            }
            else
                for(j = 0; j < i; j++){
                    if(strcmp(nome[j], nNome) == 0){
                        erro = 1;
                        printf("\nNome ja Cadastrado\n");
                        break;
                    }
                }
            if(erro == 0)
                strcpy(nome[i], nNome);
            
        }while(erro != 0);
    }
}

void cadastroItens(int m[][QTD_ARMAZEM], char nome[][100]){
    int lin, col, quantidade, achou;

    for(lin = 0; lin < QTD_PRODUTOS; lin++){
        printf("\nProduto: %s", nome[lin]);
        for(col = 0; col < QTD_ARMAZEM; col++){
            printf("\nArmazem %d:", col + 1);

            do{

                achou = 0;

                printf("\nQuantidade de Estoque:");
                scanf("%d", &quantidade);
                limpaBuffer();

                if(quantidade <= 0){
                    achou = 1;
                    printf("\nE necessario ter mais de UM de volume!!\n");
                }
                else
                    m[lin][col] = quantidade;

            }while(achou != 0);

        }
    }
}

void contagemProd(int m[][QTD_ARMAZEM], int qtdColuna[], int qtdProduto[]){
    int col, lin;


    //Total cada produto
    for(lin = 0; lin < QTD_PRODUTOS; lin++){
        qtdProduto[lin] = 0;
        for(col = 0; col < QTD_ARMAZEM; col++){
           qtdProduto[lin] += m[lin][col];
        }
    }

    //Total de Cada Armazem
    for(col = 0; col < QTD_ARMAZEM; col++){
        qtdColuna[col] = 0;
        for(lin = 0; lin < QTD_PRODUTOS; lin++){
            qtdColuna[col] += m[lin][col];
        }
    }

}

void adcPreco(char nome[][100], float preco[]){
    int i, erro;
    float valor;

    for(i = 0; i < QTD_PRODUTOS; i++){
        do{
            erro = 0;

            printf("\nProduto: %s\n", nome[i]);
            printf("\nValor:");
            scanf("%f", &valor);
            limpaBuffer();

            if(valor <= 0){
                erro = 1;
                printf("\nO Item deve Valer Mais que 0 Reais\n");
            }

            if(erro == 0)
                preco[i] = valor;
            
        }while(erro != 0);
    }
}


int main(){
    char nome[QTD_PRODUTOS][100];
    char nNome[100];
    int mP[QTD_PRODUTOS][QTD_ARMAZEM];
    int qtdColuna[QTD_ARMAZEM], qtdProduto[QTD_PRODUTOS];
    float preco[QTD_PRODUTOS], valorTotal;
    int i;


    lerString(nome, QTD_PRODUTOS, nNome);
    adcPreco(nome, preco);
    cadastroItens(mP, nome);
    contagemProd(mP, qtdColuna, qtdProduto);

    for(i = 0; i < QTD_PRODUTOS; i++){
        printf("\n%s: %d\n", nome[i], qtdProduto[i]);
        printf("Valor Unitario: R$ %.2f\n", preco[i]);
        valorTotal = 0;
        valorTotal = qtdProduto[i] * preco[i];
        printf("Valor Total = R$ %.2f\n", valorTotal);
    }

    for(i = 0; i < QTD_ARMAZEM; i++){
        printf("\nArmazen %d: %d\n", i+1, qtdColuna[i]);
    }
    
    return 0;
}