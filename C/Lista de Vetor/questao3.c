//Leia as notas de 30 alunos e calcule quantos ficaram acima da média.

#include <stdio.h>
#define QTND_ALUNOS 30

int main(){
    int vet[QTND_ALUNOS];
    int i, notaAcima=0;
    float media, nota, soma=0;

    for(i=0;i<QTND_ALUNOS;i++){
        printf("Forneça a nota do aluno:");
        scanf("%d", &vet[i]);
        soma += vet[i];
    }

    media = soma/QTND_ALUNOS;

    for(i=0;i<QTND_ALUNOS;i++){
        if(vet[i] > media)
        notaAcima++;
    }

    printf("Quantidade de Alunos aprovados: %d", notaAcima);

    return 0;
}