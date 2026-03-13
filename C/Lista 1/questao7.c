#include <stdio.h>
#include <math.h>
#define PI 3.1415
    int main(){
        double area ,raio, volume, comprimento;
        int opcao = 0;
        
        while (opcao != 4){
            printf("\nSelecione uma opção:\n");
            printf("\n1 - Area\n");
            printf("2 - Comprimento\n");
            printf("3 - Volume\n");
            printf("4 - Sair\n");
            printf("\nDigite a opção:");
            scanf("%d", &opcao);

    if(opcao == 1){
            printf("\nValor do raio:");
            scanf("%lf", &raio);
            area=PI*pow(raio,2);
            printf("\nO valor da area é %.1lf metros quadrados:", area);
        }
    else if (opcao == 2){
            printf("\nValor do raio:");
            scanf("%lf", &raio);
            comprimento=2*PI*raio;
            printf("\nO valor do perimetro é igual a %.1lf:", comprimento);
        }
    else if(opcao == 3){
            printf("\nValor do raio:");
            scanf("%lf", &raio);
            volume=(4.0/3.0)*PI*pow(raio, 3);
            printf("\nO valor do volume é igual a %.1lf metros cubicos:", volume);
        }       
    else if(opcao == 4){
            printf("\nEncerrando programa\n");
            }
    else {
                printf("\nOpçâo Invalida\n");
            }
        } 
    return 0;
    }