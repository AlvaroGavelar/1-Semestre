/*Uma companhia de carros paga a seu vendedor um salario de R$ 2.000,00 por m^es mais uma
comissão de R$ 500,00 para cada carro vendido e mais 5% do valor da venda. Todo mês a
companhia prepara os seguintes dados para um determinado vendedor: matrícula (somente
números), número de carros vendidos e o valor total das vendas. Elabore um algoritmo para calcular
e imprimir o salario do vendedor num dado mês.*/

#include <stdio.h>
    inf main(){
        int nvendas, matricula;
        float salario, comissao, venda;
            printf("Matricula do vendedor:");
            scand("%f", &matricula);
            printf("Numero de carros vendidos:");
            scanf("%d", &nvendas);
            printf("Valor total das vendas:");
            scanf("%f", &venda)
            salario=2000+(nvendas*500)+(venda*0.05);
            printf("\nMatricula %d:\n", matricula);
            printf("O valor do salario nesse mês é %f:", salario);
        return 0;
}
