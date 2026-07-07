/*
Crie uma estrutura Produto com código, nome, preço e estoque.
Implemente uma função:
int realizarVenda(struct Produto *p, int quantidade);
A função deve:
• verificar se há estoque suficiente;
• diminuir a quantidade em estoque, caso a venda seja possível;
• retornar 1 se a venda foi realizada;
• retornar 0 caso contrário
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[100];
    float preco;
    int estoque;
}Produto;

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

int realizarVenda(Produto *p, int quantidade){
    if(quantidade > p->estoque)
        return 0;
       
    p->estoque -= quantidade;
    return 1;

}

int main(){
    Produto p;
    int achou, quantidade;

    printf("\nCodigo do Produto:");
    scanf("%d", &p.codigo);
    limpaBuffer();

    printf("\nNome:");
    fgets(p.nome, 100, stdin);

    int tam = strlen(p.nome);
    if(p.nome[tam - 1] == '\n') 
        p.nome[tam - 1] = '\0';
    else
        limpaBuffer();

    printf("\nPreco do Produto:");
    scanf("%f", &p.preco);
    limpaBuffer();

    do{
        achou = 0;
        printf("\nQuantidade em Estoque:");
        scanf("%d", &p.estoque);

        if(p.estoque > 100){
            achou = 1;
            printf("\nEstoque Maximo é igual a 100 Unidades!!\n");
        }
    }while(achou != 0);

    printf("\nQuantidade a Ser Vendida:");
    scanf("%d", &quantidade);

    if(realizarVenda(&p, quantidade) == 0){
        printf("\nVenda Nao Realizada\n");
        printf("Estoque atual: %d\n", p.estoque);
    }
    else{
        printf("\nVenda Realizada\n");
        printf("Estoque restante: %d\n", p.estoque);

    }

    return 0;
}