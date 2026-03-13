#include <stdio.h>
int main(){
    float area, perimetro, base, altura;
    int opcao = 0;
        while (opcao !=3){
            printf("\n\nEscolha a Opção\n");
            printf("\n1 - Area\n \n2 - Perimetro\n \n3 - Sair\n \nDigite a opção:");
            scanf("%d", &opcao);

            if(opcao == 1){
                printf("\nValor Da Base:");
                scanf("%f", &base);
                printf("Valor Da Altura:");
                scanf("%f", &altura);
                    if(area != 0){
                        area=base*altura;
                        printf("\nA area é igual a %.1f mestros quadrados", area);}
                    else{
                        printf("\nRetangulo Inexistente\n");
                    }
            }
            
            if(opcao == 2){
                printf("\nValor Da Base:");
                scanf("%f", base);
                printf("Valor Da Altura:");
                scanf("%f", altura);
                    if(perimetro != 0){
                        perimetro=2*(base+altura);
                        printf("\nA area é igual a %.1f mestros quadrados", perimetro);}
                    else{
                        printf("\nRetangulo Inexistente\n");
                    }
            }        
        }
        printf("\nPrograma encerrado\n");
        return 0;
    }