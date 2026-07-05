/*
Escreva um programa que leia valores inteiros para preencher uma matriz M de dimensões 10x20.
Após a leitura de todos os dados, o programa deve processar a matriz e exibir na tela:
1. o maior elemento pertencente a cada uma das linhas; ok
2. a média aritmética dos elementos de cada uma das colunas; ok
3. o resultado do produto (multiplicação) de todos os elementos da matriz que sejam diferentes
de zero;
4. a posição exata (linha e coluna) de todas as ocorrências de um valor específico, o qual deve
ser digitado pelo usuário ao final do programa.
*/

#include <stdio.h>
#define LINHA 10
#define COLUNA 20

int main(){
    int col, erro, lin, valor, maior[LINHA], mA[COLUNA];
    int m[LINHA][COLUNA], produto, pesquisa;

    //Preenche Matriz
    for(lin = 0; lin < LINHA; lin++){
        for(col = 0; col < COLUNA; col++){
            do{
                erro = 0;

                printf("Forneca um Numero Inteiro:");
                scanf("%d", &valor);

                if(valor < 0){
                    erro = 1;
                    printf("\n>= 0\n");
                }

                if(erro == 0)
                    m[lin][col] = valor;

            }while(erro != 0);
        }
    }

    //Acha o Maior da Linha
    for(lin = 0; lin < LINHA; lin++){
        maior[lin] = m[lin][0];
        for(col = 0; col < COLUNA; col++){
            if(m[lin][col] > maior[lin])
                maior[lin] = m[lin][col];
        }
        printf("Maior da linha %d: %d\n", lin+1, maior[lin]);
    }   

    //Media Arit
    for(col = 0; col < COLUNA; col++){
        mA[col] = 0;
        for(lin = 0; lin < LINHA; lin++){
            mA[col] += m[lin][col];
        }
        printf("Media Da Coluna %d: %.1f", col, (float)mA[col] / LINHA);
    }

    produto = 1;

    //Produto de Tudo
    for(lin = 0; lin < LINHA; lin++){
        for(col = 0; col < COLUNA; col++){
            if(m[lin][col] != 0){
                produto *= m[lin][col];
            }
        }
    }

    printf("\nProduto Da Matriz: %d\n", produto);

    printf("\nEscolha Um Numero Inteiro Para Vasculhar:");
    scanf("%d", &pesquisa);

    for(lin = 0; lin < LINHA; lin++){
        for(col = 0; col < COLUNA; col++){
            if(m[lin][col] == pesquisa){
                printf("Encontrado na linha %d coluna %d\n", lin, col);
            }
        }
    }

    return 0;
}