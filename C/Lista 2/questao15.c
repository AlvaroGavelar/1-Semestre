/*Escreva um programa que leia o código(matrícula) de um aluno e suas três notas. Calcule a média
ponderada do aluno, considerando que o peso para a maior nota seja 5, a menor tem peso 2 e a
outra peso 3. Mostre o código do aluno, suas três notas, a média calculada e uma mensagem
"APROVADO" se a média for maior ou igual a 5 e "REPROVADO" se a média for menor que 5.
Repita a operação até que o código lido seja negativo.*/


#include <stdio.h>

int main(){
    int matricula;
    float media, maior=0, menor=0, intermediario, nota1, nota2, nota3;

        printf("\nInforme o numero de matricula");
        scanf("%d", &matricula);

    while(matricula >= 0){


        printf("\nDigite a primeira nota: ");
        scanf("%f", &nota1);

        printf("\nDigite a segunda nota: ");
        scanf("%f", &nota2);

        printf("\nDigite a terceira nota: ");
        scanf("%f", &nota3);

        if(nota1 > nota2 && nota1 > nota3){
            maior = nota1;
        }
            else
                if(nota2 > nota3){
                    maior = nota2;
                }
                else
                    maior = nota3;
        if(nota1 < nota2 && nota1 < nota3){
            menor = nota1;
        }
            else
                if(nota2 < nota3){
                    menor = nota2;
                }
                    else
                        menor = nota3;

        intermediario = nota1 + nota2 + nota3 - maior - menor;
        media = ((maior*5) + (intermediario*3) + (menor*2))/10;

        printf("\nCodigo do Aluno:%d", matricula);
        
        if(media >= 5){
            printf("\nAluno aprovado com %.2f de média!", media);
        }
            else
                printf("\nAluno reprovado com %.2f de média", media);

        printf("\nInforme o numero de matricula");
        scanf("%d", &matricula);
    }

    return 0;
}