/*
(Escreva um programa que solicite ao usuário o número de linhas e o número de colunas para uma
matriz retangular A, garantindo, por meio de uma estrutura de validação, que ambos os valores
fornecidos sejam estritamente maiores que zero e menores que dez.) (Em seguida, o programa deve
ler os valores inteiros para preencher essa matriz A.) Após a entrada de dados, e de forma
completamente separada da leitura e da exibição na tela, o programa deve utilizar laços de repetição
específicos para processar e gerar dois vetores: o vetor SL, onde cada elemento armazena a soma
dos elementos de uma linha correspondente da matriz, e o vetor SC, onde cada elemento armazena a
soma dos elementos de uma coluna correspondente. Por fim, o programa deve imprimir os vetores
SL e SC resultantes. 
*/

#include <stdio.h>

int main(){
    int nL, nC, erro, lin, col, valor;
    int m[10][10];
    int SL[10], SC[10];
    
    //Proporção da Matriz
    do{
        erro = 0;

        printf("\nForneça a Quantidade de Linhas:");
        scanf("%d", &nL);

        printf("Forneça a Quantidade de Colunas:");
        scanf("%d", &nC);

        if(nL <= 0 || nC <= 0 || nL > 10 || nC > 10){
            erro = 1;
            printf("\nERRO!!\n");
        }
    }while(erro != 0);

    //Colocar Dados
    for(lin = 0; lin < nL; lin++){
        printf("\nLinha: %d\n", lin+1);
        for(col = 0; col < nC; col++){
            printf("Coluna: %d\n", col+1);

            printf("\nForneça Um Numero Inteiro:");
            scanf("%d", &valor);

            m[lin][col] = valor;
        }
    }

    //Soma da Linha (SL)
    for(lin = 0; lin < nL; lin++){
        SL[lin] = 0;
        for(col = 0; col < nC; col++){
            SL[lin] += m[lin][col];
        }
    }

    //Soma das Colunas (SC)
    for(col = 0; col < nC; col++){
        SC[col] = 0;
        for(lin = 0; lin < nL; lin++){
            SC[col] += m[lin][col];
        }
    }

    //Soma Das Linhas
    for(lin = 0; lin < nL; lin++)
        printf("\nLinha %d a Soma é: %d", lin+1, SL[lin]);
  

    //Soma das Colunas (SC)
    for(col = 0; col < nC; col++)
        printf("\nColuna %d a Soma é: %d", col+1, SC[col]);

    return 0;
}