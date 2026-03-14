#include <stdio.h>
    int main(){
    float distancia, gasolina, pgasolina, media, vtotal;
    
        printf("Qual a distancia da viagem:");
        scanf("%f", &distancia);
        printf("Qual a media do carro em Km/L:");
        scanf("%f",&media);
        printf("O preço da gasolina:");
        scanf("%f", &pgasolina);
        /*media=distancia/gasolina*/
        gasolina=media/distancia;
        vtotal=gasolina*pgasolina;
        printf("\nO valor gasto em gasolina é R$ %.2f:\n", vtotal);
        printf("O total de gasolina é %.1fL", gasolina);
    return 0;
}