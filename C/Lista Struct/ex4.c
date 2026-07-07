/*
Cadastre 10 pessoas com:
• nome;
• telefone;
• idade.
Leia um nome e procure essa pessoa no vetor. Se ela existir, exiba seu telefone e sua idade.
Considere que os nomes são únicos
*/

#include <stdio.h>
#include <string.h>
#define QTD_PESSOA 2

typedef struct{
    char nome[100];
    char telefone[20];
    int idade;
}Pessoa;

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void cadastro(Pessoa p[], int tamanho){
    int i, j, achou, tam;
    char nNome[100];
    char numero[20];

    for(i = 0; i < tamanho; i++){
        do{

            //Nome
            printf("\nPessoa: %d\n", i + 1);
            achou = 0;

            printf("Nome:");
            fgets(nNome, 100, stdin);

            tam = strlen(nNome);
            if(nNome[tam - 1] == '\n')
                nNome[tam - 1] = '\0';
            else
                limpaBuffer();

            for(j = 0; j < i; j++){
                if(strcmp(p[j].nome, nNome) == 0){
                    achou = 1;
                    printf("\nJa Cadastrado!\n");
                }
            }

            if(achou == 0)
                strcpy(p[i].nome,nNome);

            //Telefone
            printf("Numero de Telefone:");
            fgets(numero, 20, stdin);

            tam = strlen(numero);
            if(numero[tam - 1] == '\n')
                numero[tam - 1] = '\0';
            else
                limpaBuffer();

            for( j = 0; j < i; j++){
                if(strcmp(p[i].telefone, numero) == 0){
                    achou = 1;
                    printf("\nJa Cadastrado!\n");
                }
            }

            if(achou == 0)
                strcpy(p[i].telefone,numero);

            //Idade
            printf("Idade:");
            scanf("%d", &p[i].idade);
            limpaBuffer();

            if(p[i].idade < 0){
                achou = 1;
                printf("Numero Tem que Ser Maior que 0");
            }

        }while(achou != 0);
    }
}

int pesquisaNome(Pessoa p[], int tamanho){
    int i, tam;
    char pesquisa[100];

    printf("\nNome A Ser Procurado:");
    fgets(pesquisa, 100, stdin);

    tam = strlen(pesquisa);
            if(pesquisa[tam - 1] == '\n')
                pesquisa[tam - 1] = '\0';
            else
                limpaBuffer();
    
    for(i = 0; i < tamanho; i++){
        if(strcmp(p[i].nome, pesquisa) == 0){
            return i;
        }
    }
    return -1;
}

int main(){
    Pessoa p[QTD_PESSOA];
    int indice;

    cadastro(p, QTD_PESSOA);
    indice = pesquisaNome(p, QTD_PESSOA);

    if(indice != -1){
        printf("\nNome: %s", p[indice].nome);
        printf("\nNumero: %s", p[indice].telefone);
        printf("\nIdade: %d", p[indice].idade);
    }
    else
        printf("\nNome nao Encontrado!\n");

    return 0;
}