#include <stdio.h>

int main(){
    int quantidadeClients, contador, codigo, nota, quantidadeHamburguer=0, quantidadeBatata=0, quantidadeMilk=0, somaHamburguer=0, somaBatata=0, somaMilk=0, somaTotal=0, menorNota=5;
    float mediaHamburguer=0, mediaBatata=0, mediaMilk=0;

        printf("Quantos clientes vão participar da enquete:");
        scanf("%d", &quantidadeClients);

    if(quantidadeClients>0){
        for(contador=1; contador <= quantidadeClients; contador++){
            printf("\nForneça o codigo do item: \n 1 - Hamburguer Byte \n 2 - Batata Turbo \n 3 - Milk Shake Mega\n");
            scanf("%d", &codigo);

            while(codigo != 1 && codigo != 2 && codigo != 3){
                printf("Codigo Incorreto!!\n");
                printf("\nForneça o codigo do item: \n 1 - Hamburguer Byte \n 2 - Batata Turbo \n 3 - Milk Shake Mega\n");
                scanf("%d", &codigo);
            }

                printf("Escolha uma nota de 0 a 5 para o lanche:");
                scanf("%d", &nota);
                
            while(nota < 0 || nota > 5){
                printf("Nota Invalida!! Escolha uma nota de 0 a 5 para o lanche:\n");
                scanf("%d", &nota);}    

            switch(codigo){
                case 1:
                    quantidadeHamburguer++;
                    somaHamburguer+=nota;
                    somaTotal+=nota;
                    break;
                case 2:
                    quantidadeBatata++;
                    somaBatata+=nota;
                    somaTotal+=nota;
                    break;
                case 3:
                    quantidadeMilk++;
                    somaMilk+=nota;
                    somaTotal+=nota;
                    break;
            }
                if(nota < menorNota){
                    menorNota = nota;}
        }
    }

        if(quantidadeHamburguer > 0){
            mediaHamburguer = (float)somaHamburguer/quantidadeHamburguer;}
        if(quantidadeBatata > 0){
            mediaBatata = (float)somaBatata/quantidadeBatata;}
        if(quantidadeMilk > 0){
            mediaMilk = (float)somaMilk/quantidadeMilk;}

            printf("\nRanking dos lanches:\n");
            printf("Hamburguer Byte: %d votos e média de %.2f\n", quantidadeHamburguer, mediaHamburguer);
            printf("Batata Turbo: %d votos e média de %.2f\n", quantidadeBatata, mediaBatata);
            printf("Milk Shake Mega: %d votos e média de %.2f\n", quantidadeMilk, mediaMilk);

            if(quantidadeHamburguer > quantidadeBatata && quantidadeHamburguer > quantidadeMilk){
                printf("Mais votado: Hamburguer Byte\n");}
            else 
                if(quantidadeBatata > quantidadeHamburguer && quantidadeBatata > quantidadeMilk){
                printf("Mais votado: Batata Turbo\n");}
                else    
                    if(quantidadeMilk > quantidadeHamburguer && quantidadeMilk > quantidadeBatata){
                    printf("Mais votado: Milk Shake Mega\n");}
                    else
                        printf("\nEmpate entre lanches mais votados");

            if(mediaHamburguer > mediaBatata && mediaHamburguer > mediaMilk){
                printf("Melhor Avaliado: Hamburguer Byte\n");}
            else 
                if(mediaBatata > mediaHamburguer && mediaBatata > mediaMilk){
                printf("Melhor Avaliado: Batata Turbo\n");}
                else    
                    if(mediaMilk > mediaHamburguer && mediaMilk > mediaBatata){
                    printf("Melhor Avaliado: Milk Shake Mega\n");}
                    else
                        printf("\nEmpate entre lanches mais avaliados");
            
            printf("\nCliente mais exigente deu nota: %d", menorNota);
            if(quantidadeClients > 0){
                printf("\nMedia geral do restaurante: %.2f", (float)somaTotal/quantidadeClients);
            }
}
        

