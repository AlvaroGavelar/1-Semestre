#include <stdio.h>
    int main(){
        int nvendas, matricula;
        float salario, venda;
            printf("Matricula do vendedor:");
            scanf("%d", &matricula);
            printf("Numero de carros vendidos:");
            scanf("%d", &nvendas);
            printf("Valor total das vendas:");
            scanf("%f", &venda);
                salario = 2000 + (nvendas * 500) + (venda * 0.05);
            printf("\nMatricula %d:\n", matricula);
            printf("O valor do salario nesse mês é %.2f:", salario);
        return 0;
}
