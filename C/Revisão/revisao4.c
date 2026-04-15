/*Uma estação mede temperaturas.
O programa deve:
1. Ler temperaturas reais.
2. Encerrar quando for digitado 999.
3. Classificar:
 - Baixa: abaixo de 100
 - Média: 100 a 300
 - Alta: acima de 300
Ao final mostrar:
- Quantas temperaturas em cada tipo Ok
- A média geral Ok
- A maior temperatura de cada classe Ok
- A menor temperatura de cada classe Ok
- A maior temperatura geral Ok
- A menor temperatura geral Ok
- Quantas temperaturas ficaram entre 150 e 250 Ok*/

//Ler temperatura (999 sai) > Classificar > Quantas de Cada > Maior e Menor de cada Classe > Maior e Menor Geral > A Média Geral > Entre 150 e 250
#include <stdio.h>

int main(){
    int temperatura, maiorBaixa=0, menorBaixa=0, maiorMedia=0;
    int menorMedia=0, maiorAlta=0, menorAlta=0;
    int qtdBaixa=0, qtdMedia=0, qtdAlta=0, qtdFaixa=0;
    int menorGeral=0, maiorGeral=0, primeiraTemp=1;
    int somabaixa=0, somaMedia=0, somaAlta=0, somaTotal=0, qtd=0;

    printf("Forneça uma temperatura ou 999 para sair:");
    scanf("%d", &temperatura);

    while(temperatura != 999){

        //Classificar
        if(temperatura < 100){
            qtdBaixa++;
            somabaixa+=temperatura;
        }
        if(temperatura >= 100 && temperatura <= 300){
            qtdMedia++;
            somaMedia+=temperatura;
        }
        if(temperatura > 300){
            qtdAlta++;
            somaAlta+=temperatura;
        }
        
        //Maior e Menor Geral
        if(primeiraTemp == 1){
            maiorGeral = temperatura;
            menorGeral = temperatura;
            primeiraTemp = 0;
        }
        else if(temperatura > maiorGeral){
            maiorGeral = temperatura;
        }
        else if(temperatura < menorGeral){
            menorGeral = temperatura;
        }

        //Maior e Menor Individual
        if(qtdBaixa == 1){
            maiorBaixa = temperatura;
            menorBaixa = temperatura;
        }
        else if(temperatura > maiorBaixa){
            maiorBaixa = temperatura;
        }
        else if(temperatura < menorBaixa){
            menorBaixa = temperatura;
        }

        if(qtdMedia == 1){
            maiorMedia = temperatura;
            menorMedia = temperatura;
        }
        else if(temperatura > maiorMedia){
            maiorMedia = temperatura;
        }
        else if(temperatura < menorMedia){
            menorMedia = temperatura;
        }

        if(qtdAlta = 1){
            maiorAlta = temperatura;
            menorAlta = temperatura;
        }
        else if(temperatura > maiorAlta){
            maiorAlta = temperatura;
        }
        else if(temperatura < menorAlta){
            menorAlta = temperatura;
        }

        //Entre 150 e 250
        if(temperatura >= 150 && temperatura <= 250){
            qtdFaixa++;
        }

        //Soma total
        somaTotal = somaAlta + somabaixa + somaMedia;

        printf("\nForneça uma temperatura ou 999 para sair:");
        scanf("%d", &temperatura);

        qtd++;
    }

    if(qtd > 0){
        printf("\nClassificação das Temperaturas");
        printf("\nBaixa: %d Maior Temperatura: %d Menor Temperatura: %d", qtdBaixa, maiorBaixa, menorBaixa);
        printf("\nMedia: %d Maior Temperatura: %d Menor Temperatura: %d", qtdMedia, maiorMedia, menorMedia);
        printf("\nAlta: %d Maior Temperatura: %d Menor Temperatura: %d", qtdAlta, maiorAlta, menorAlta);
        printf("\nMédia : %.2f",(float)somaTotal/qtd);
        printf("\nMaior temperatura: %d", maiorGeral);
        printf("\nMenor temperatura: %d", menorGeral);
        printf("\nQuantidade entre 150 e 250: %d", qtdFaixa);
    }

    return 0;
}