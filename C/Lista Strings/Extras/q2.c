/*Crie uma agenda com:
-nome
-telefone

O usuário pode:
-cadastrar contato OK
-listar contatos
-buscar contato pelo nome
-remover contato

Ao remover:
os elementos do vetor devem “andar para trás”*/

#include <stdio.h>
#include <string.h>

void limpaBuffer(){
    char ch;
    do{
        ch=getchar();
    }while(ch != '\n');
}

int cadastroNumero(int *qtd, char numero[20][15], char novoNumero[15], char nome[20][50], char novoNome[50]){
    int i, iguais = 0, achou = 0;

    for(i=0;i<*qtd;i++){

        //Comparações
        if(strcmp(nome[i],novoNome)==0){
            printf("\nNome já Cadastrado!!\n");
            achou = 1;
            break;
        }
        if(strcmp(numero[i],novoNumero)==0){
            printf("\nNúmero já Cadastrado!!\n");
            iguais = 1;
            break;
        }
    }

    //Passa o nome e numero
    if(achou == 0 && iguais == 0){
        strcpy(nome[*qtd],novoNome);
        strcpy(numero[*qtd], novoNumero);

        (*qtd)++;

        printf("\nContato cadastrado com sucesso!\n");
        return 1;
    }
    else
        return 0;
}


int main(){
    int totalContatos = 0, i;
    char nome[20][50]; 
    char novoNome[50];
    char numero[20][15];
    char novoNumero[15];


    for(i=0; i<10;i++){
        printf("Forneça o Nome do %d.o Numero:", i+1);
        fgets(novoNome, 50, stdin);
        printf("Forneça um Número de Telefone com +55 e DDD: ");
        fgets(novoNumero, 15, stdin);
        

        if (cadastroNumero(&totalContatos, numero, novoNumero, nome, novoNome) == 0) {
            printf("Por favor, tente novamente.\n");
            i--; // <--- O TRUQUE ESTÁ AQUI! Volta uma iteração no loop
        }
    }

    return 0;
}