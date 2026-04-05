/*Chico tem 1,50 metros e cresce 2 centímetros por ano, enquanto Zé tem 1,10 metros e cresce 3
centímetros por ano. Construa um programa que calcule e imprima quantos anos serão necessários
para que Zé seja maior que Chico. */

#include <stdio.h>

    int main (){
        float alturaChico=1.5, alturaZe=1.1;
        int ano=0;

        printf("Vamos calcular quantos anos demora para Zé ser maior que Chico:");

        while(alturaChico > alturaZe){
            ano++;
            alturaChico = alturaChico + 0.02;
            alturaZe = alturaZe + 0.03;

            printf("\nAltura de Chico %.1f e de Zé %.1f", alturaChico, alturaZe);
            printf("\nAnos passados = %d", ano);
            
        }

        printf("\nSerão necessário %d anos.", ano);

        return 0;
    }