#include <stdio.h>
#include <string.h>

#define QUANTIDADE_ALUNOS 3

// Limpa o '\n' que o fgets deixa no final do texto
void removeNewline(char string[]) {
    string[strcspn(string, "\n")] = '\0';
}

// Limpa o buffer do teclado para o próximo fgets não bugar
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastrarAlunoCompleto(char nome[QUANTIDADE_ALUNOS][50], float nota1[], float nota2[], int *qtd, char novoNome[]) {
    int i, achou = 0;

    // Impede o cadastro de nomes vazios (caso o buffer falhe)
    if (strlen(novoNome) == 0) {
        printf("\nErro: Nome inválido!\n\n");
        return;
    }

    // Verificar se o aluno já existe
    for (i = 0; i < *qtd; i++) {
        if (strcmp(nome[i], novoNome) == 0) {
            printf("\nAluno já Cadastrado!!\n\n");
            achou = 1;
            break;
        }
    }

    if (achou == 0) {
        if (*qtd < QUANTIDADE_ALUNOS) {
            strcpy(nome[*qtd], novoNome);
            
            printf("Aluno: %s\n", nome[*qtd]);
            printf("Forneça a Primeira Nota: ");
            scanf("%f", &nota1[*qtd]); 
            while (nota1[*qtd] < 0) { 
                printf("Nota inválida! Digite novamente: ");
                scanf("%f", &nota1[*qtd]);
            }
            
            printf("Forneça a Segunda Nota: ");
            scanf("%f", &nota2[*qtd]);
            while (nota2[*qtd] < 0) {
                printf("Nota inválida! Digite novamente: ");
                scanf("%f", &nota2[*qtd]);
            }

            // ESSA LINHA RESOLVE O BUG: Remove o Enter deixado pelo scanf
            limparBuffer(); 

            (*qtd)++;
            printf("\nAluno Cadastrado com Sucesso!!\n\n");
        } else {
            printf("\nLimite de Alunos Atingido\n");
        }
    }
}

void exibirMediasETop(char nome[QUANTIDADE_ALUNOS][50], float nota1[], float nota2[], int qtd) {
    int i, indiceMaior = 0;
    float mediaAluno = 0, maiorMedia = -1; 

    printf("--- RELATÓRIO DE MÉDIAS ---\n");
    for (i = 0; i < qtd; i++) {
        mediaAluno = (nota1[i] + nota2[i]) / 2;
        printf("\nAluno: %s", nome[i]);
        printf("\nMédia: %.2f", mediaAluno);

        if (mediaAluno >= 60) {
            printf("\nSituação: Aprovado!!\n");
        } else {
            printf("\nSituação: Reprovado!!\n");
        }
        
        if (mediaAluno > maiorMedia) {
            maiorMedia = mediaAluno;
            indiceMaior = i;
        }
    }

    if (qtd > 0) {
        printf("\n===== MELHOR ALUNO =====\n");
        printf("Aluno: %s\n", nome[indiceMaior]);
        printf("Maior média: %.2f\n", maiorMedia);
    }
}

void mostrarNotasAluno(float nota1[], float nota2[], int indice) {
    printf("Nota 1: %.2f\n", nota1[indice]);
    printf("Nota 2: %.2f\n", nota2[indice]);
}

void buscaNome(char nome[QUANTIDADE_ALUNOS][50], int qtd, char compararaNome[50], float nota1[], float nota2[]) {
    int i, achou = 0;
    
    for (i = 0; i < qtd; i++) {
        if (strcmp(nome[i], compararaNome) == 0) {
            printf("\n===== ALUNO ENCONTRADO =====\n");
            printf("Aluno: %s\n", nome[i]);
            mostrarNotasAluno(nota1, nota2, i); 
            achou = 1;
            break; 
        }
    }
    
    if (!achou) {
        printf("\nAluno não Encontrado!!\n");
    }
}

int main() {
    char nome[QUANTIDADE_ALUNOS][50];
    char novoNome[50];
    char busca[50];
    int qtd = 0, i;
    float nota1[QUANTIDADE_ALUNOS];
    float nota2[QUANTIDADE_ALUNOS];

    printf("--- CADASTRO DE ALUNOS E NOTAS ---\n");
    
    // Altere o "3" para 10 se quiser testar com a capacidade cheia
    while(qtd < QUANTIDADE_ALUNOS){
        printf("Forneça o Nome: ");
        fgets(novoNome, 50, stdin);
        removeNewline(novoNome); 
    
        cadastrarAlunoCompleto(nome, nota1, nota2, &qtd, novoNome);
    } 

    if (qtd > 0) {
        exibirMediasETop(nome, nota1, nota2, qtd);

        printf("\nDigite o nome para busca: ");
        fgets(busca, 50, stdin);
        removeNewline(busca);
        
        buscaNome(nome, qtd, busca, nota1, nota2);
    }

    return 0;
}