/*Durante uma aula de Educação Física, o professor deseja analisar a altura dos alunos da turma. Para
isso, ele pediu que fossem registradas as alturas de 10 alunos.
Faça um programa que:
• Leia a altura de 10 alunos
• Armazene as alturas em um vetor
• Calcule a altura média
• Mostre quantos alunos possuem altura maior que a média*/

#include <stdio.h>
#define NUMERO_ALUNOS 10

int main(){
    float vet[NUMERO_ALUNOS], media=0;
    int i, cont=0;

    for(i = 0; i < NUMERO_ALUNOS; i++){
        printf("Foneça a Altura do %do. aluno:",i+1);
        scanf("%f",&vet[i]);
        media+=vet[i];
    }

    media = media / NUMERO_ALUNOS;

    for(i=0;i<NUMERO_ALUNOS;i++){
        if(vet[i]>media)
            cont++;
    }

    printf("\nNúmero de alunos com Altura > média = %d\n",cont);
    return 0;
}