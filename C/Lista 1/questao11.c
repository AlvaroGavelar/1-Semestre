#include <stdio.h>
#include <math.h>
    int main(){
        double y, a, x, b;
        /*Menu*/
        int opcao;
            while (opcao != 5){
            printf("\nEscolha uma opção:\n"); 
            printf("\n1 - Calcular x\n");
            printf("2 - Calcular y\n");
            printf("3 - Calcular a\n");
            printf("4 - Calcular b\n");
            printf("5 - Sair\n");
            printf("\nDigite a opção:");
            scanf("%d", &opcao);
        /*Opções*/
            if(opcao == 1){
                printf("\nVoce escolheu calcular X\n");
                printf("Valor de y:");
                scanf("%lf", &y);
                printf("Valor de b:");
                scanf("%lf", &b);
                printf("Valor de a:");
                scanf("%lf", &a);
            if (a != 0){
                x=(y-b)/a;
                printf("\nO valor de x é igual a %.1lf:\n", x);}
            else{
                printf("\nCalculo inexistente\n");
                } 
            }                                                                     
            
            else if(opcao == 2){
                printf("\nVoce escolheu calcular y\n");
                printf("Valor de a:");
                scanf("%lf", &a);
                printf("Valor de x:");
                scanf("%lf", &x);
                printf("Valor de b:");
                scanf("%lf", &b);             
            if(y != 0){
                y=a*x+b;
                printf("\nO valor de y é igual a %.1lf\n", y);} 
            else{
                printf("\nO y é nulo");
                }                   
            }
            
            else if(opcao ==3){               
                printf("\nVoce escolheu calcular a\n");
                printf("Valor de y:");
                scanf("%lf", &y);
                printf("Valor de b:");
                scanf("%lf", &b);
                printf("Valor de x:");
                scanf("%lf", &x);             
            if(y != 0){
                a=(y-b)/x;
                printf("\nO valor de a é igual %.1lf\n", a);}
            else{
                printf("\nCalculo inexistente\n");
                }
            }
            
            else if(opcao == 4){
                printf("\nVoce escolheu calcular b\n");
                printf("Valor de y:");
                scanf("%lf", &y);
                printf("Valor de b:");
                scanf("%lf", &b);
                printf("Valor de x:");
                scanf("%lf", &x);             
            if(y != 0){
                b=y-a*x;
                printf("\nO valor de b é igual %.1lf\n", b);}
            else{
                printf("\nCalculo inexistente\n");
                }
            }
            
            else if(opcao == 5){
            printf("\nEncerrando programa\n");
            }


            else {
                printf("\nopcao Invalida\n");
            }
        }
    return 0;
 }