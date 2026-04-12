/*Alvinópolis city, considerada a mais bela e agradável cidade do Brasil, possui um invejável parque
industrial, e as empresas lá instaladas, pertencem a um dos segmentos de atuação: Mineração, TI e
Hotelaria. Faça um programa, usando a Linguagem C, que leia o código de atuação (1 – Mineração,
2 – TI e 3 – Hotelaria) e o saldo do balanço (que pode ser negativo) do ano de 2022 de cada
empresa e, calcule e imprima:
a) A média do faturamento das empresas de TI;
b) O menor faturamento dentre todas as empresas;
c) O maior e o menor faturamento das empresas de Mineração;
d) A quantidade de empresas de Hotelaria.
Obs. O término da entrada de dados é identificado por um código de atuação diferente de 1, 2 e 3.*/

#include <stdio.h>

int main(){
    int codigo, contadorMineração=0, primeiro=1, contadorTI=0, contadorHotel=0;
    float faturamento, maiorMineração, menorMineração, menorGeral, somaTI=0, mediaTI;

    printf("Forneça o codigo do segmento: \n 1 - Mineração \n 2 - TI \n 3 - Hotelaria \n Codigo:");
    scanf("%d", &codigo);

    while(codigo >= 1 && codigo <=3){
            printf("\nFaturamento da Empresa:");
            scanf("%f", &faturamento);

            if(primeiro == 1){ //menor faturamento
                menorGeral = faturamento;
                primeiro=0;
            }
                else
                    if(faturamento < menorGeral){
                        menorGeral = faturamento;
                    }

            if(codigo == 1){ //mineração
                contadorMineração++;
                    if(contadorMineração==1){
                        maiorMineração = faturamento;
                        menorMineração = faturamento;
                    }
                    else
                        if(faturamento>maiorMineração){
                            maiorMineração = faturamento;
                        }
                        else
                            if(faturamento<menorMineração){
                                menorMineração = faturamento;
                            }
            }
            if(codigo == 2){ //TI
                contadorTI++;
                somaTI+=faturamento;
            }
            
            if(codigo == 3){ //Hotel
                contadorHotel++;
            }
            printf("Forneça o codigo do segmento: \n 1 - Mineração \n 2 - TI \n 3 - Hotelaria \n Codigo:");
            scanf("%d", &codigo);
        }
        
            if(contadorTI > 0){ //calculo media TI
                mediaTI = somaTI / contadorTI;
                printf("Media do faturamento das empresas de TI: %.2f\n", mediaTI);
                }
                else
                    printf("Nenhuma empresa informada!\n");  

            if(primeiro == 0){ //menor faturamento
                printf("Menor faturamento geral: %.2f\n", menorGeral);
            }
                else
                    printf("Nenhuma empresa informada!\n");

            if(contadorMineração > 0){ //menor e maior faturamento mineração
                printf("Maior faturamento da Mineracao: %.2f\n", maiorMineração);
                printf("Menor faturamento da Mineracao: %.2f\n", menorMineração);
            }
                else
                    printf("Nenhuma empresa informada!\n");

            printf("A quantidade de Hotelarias é: %.0d", contadorHotel); //hotelaria

    return 0;
}