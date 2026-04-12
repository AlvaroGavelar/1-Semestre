/*Escreva um programa que calcule a média aritmética das 3 notas dos alunos de uma classe. O
programa deverá ler, além das notas, o código do aluno e deverá ser encerrado quando o código
for igual a zero*/

#include <stdio.h>

int main(){
    int codigo;
    float media, nota1, nota2, nota3;

    printf("Informe o codigo do aluno (0 encerra):");
    scanf("%d", &codigo);

    while(codigo != 0){

        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        media = nota1 + nota2 + nota3 /3;

        printf("Codigo do aluno: %d\n", codigo);
        printf("Media: %.2f\n\n", media);

        printf("Digite o codigo do aluno (0 encerra): ");
        scanf("%d", &codigo);
    }

        printf("Programa encerrado!\n");

    return 0;
}