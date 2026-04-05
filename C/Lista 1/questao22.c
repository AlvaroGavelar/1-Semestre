#include <stdio.h>
    int main(){
    float distancia, tempo, velocidade, litros, vmedia;

        printf("Quanto tempo foi gasto (Em Hora):"); 
        scanf("%f", &tempo);
        printf("Qual a velocidade média (Em Km/H):");
        scanf("%f", &vmedia);

        distancia=tempo*vmedia;
        litros=distancia/12;

        printf("\nForam percorridos %.0f Km\n", distancia);
        printf("Foram gastos %.1f Litros de gasolina.", litros);
    return 0;
}