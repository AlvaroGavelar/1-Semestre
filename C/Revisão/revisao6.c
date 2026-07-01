#include <stdio.h>

int main()
{
    int ocupacao[366] = {0};

    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int entrada, saida;

        scanf("%d %d", &entrada, &saida);

        /*
            O hóspede ocupa do dia de entrada
            até o dia anterior à saída.

            Ex:
            entrada = 5
            saída = 10

            ocupa:
            5, 6, 7, 8, 9
        */
        for(int dia = entrada; dia < saida; dia++)
        {
            ocupacao[dia]++;
        }
    }

    /*
        Descobre a maior ocupação.
    */
    int maior = ocupacao[1];

    for(int dia = 2; dia <= 365; dia++)
    {
        if(ocupacao[dia] > maior)
        {
            maior = ocupacao[dia];
        }
    }

    /*
        Imprime todos os dias
        que tiveram a maior ocupação.
    */
    for(int dia = 1; dia <= 365; dia++)
    {
        if(ocupacao[dia] == maior)
        {
            printf("%d\n", dia);
        }
    }

    return 0;
}