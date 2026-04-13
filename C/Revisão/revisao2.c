/* Suponha que você foi contratado por um corretor de seguros para desenvolver um programa de
computador que auxilie o corretor no cálculo de seguros de automóveis. Este corretor trabalha com
duas companhias de seguro: ALFA Seguros e a BETA Seguros. O corretor fornecerá o sexo
(codificado como: 1 para feminino e 2 para masculino) e a idade do segurado, além do valor do
automóvel a ser segurado. Sabe-se que o valor da apólice para as seguradoras ALFA Seguros e
BETA Seguros são de 4% e 6%, respectivamente. A seguradora ALFA Seguros não faz distinção
quanto ao sexo dos segurados. No entanto, segurados com menos de 30 anos têm um acréscimo de
1% para cada ano abaixo dos 30, chegando à 12% no caso do segurado ter 18 anos. Já os segurados
com mais de 50 anos têm desconto de 1% por ano, limitando-se à 15% de desconto. A BETA
Seguros dá desconto de 5% para clientes do sexo feminino e mais 10% de desconto caso o cliente
tenha 30 anos de idade ou mais. Todos os acréscimos e descontos para ambas as seguradoras são
com base no valor bruto da apólice. Após o cálculo das apólices, o programa deve apresentar ambos
os valores, referentes ao ALFA Seguros e a BETA Seguros. O programa deve estar apto a processar
vários clientes, encerrando a execução quando um código inválido para o sexo do cliente ou
segurado seja digitado. Então, pede-se que seja elaborado um programa, a fim de gerar o produto
desejado para o corretor.
Obs.: validar a idade, ou seja, apenas valores maiores ou iguis a 18 e o valor do carro tem que ser
maior que R$10.000,00 */


#include <stdio.h>

int main (){
int sexo, idade;
float valorCarro, valorCarroAlfa=0, valorSeguroAlfa=0, acrescimoIdadeAlfa=0, descontoIdadeAlfa=0, valorCarroBeta=0, acrescimoIdadeBeta=0, descontoIdadeBeta=0, valorSeguroBeta=0, descontoSexo=0;

    printf("Forneça o sexo \n 1 - Feminino \n 2 - Masculino \n Opção:");
    scanf("%d", &sexo);
    printf("\nForneça a idade (maior que 18 anos):");
    scanf("%d", &idade);
    printf("\nForneça o valor do carro (sem pontos e maior ou igual a 10000):");
    scanf("%f", &valorCarro);

    while(sexo == 1 || sexo == 2){

        
        while(idade < 18){
                printf("\nIdade Inválida!");
                printf("\nForneça a idade (maior que 18 anos):");
                scanf("%d", &idade);
        }

        while(valorCarro < 10000){
                printf("\nValor inválido");
                printf("\nForneça o valor do carro (sem pontos e maior ou igual a 10000):");
                scanf("%f", &valorCarro);
            
        }

        printf("\n\nSeguradora Alfa Segundos:");

        valorSeguroAlfa = valorCarro * 0.04;

        if(idade < 30){
            acrescimoIdadeAlfa += (valorSeguroAlfa * (30 - idade)/100);
            valorCarroAlfa = valorSeguroAlfa + acrescimoIdadeAlfa;
        }
            else
                if(idade >=30 && idade <= 50){
                    valorCarroAlfa = valorSeguroAlfa;
                }
                else 
                    if(idade >= 65){
                        descontoIdadeAlfa += valorSeguroAlfa * 0.15;
                    }
                    else
                        if(idade > 50){
                            descontoIdadeAlfa += (valorSeguroAlfa * (idade - 50)/100);
                            valorCarroAlfa = valorSeguroAlfa - descontoIdadeAlfa;
                        }
                    
        
        printf("\nValor do Seguro é igual a: R$ %.2f", valorCarroAlfa);

        printf("\nSeguradora Beta Seguros:");

        valorSeguroBeta = valorCarro * 0.06;

        if(sexo == 1){
            descontoSexo = valorSeguroBeta - (0.05 * valorSeguroBeta);
        }
            else
                if(sexo == 2){
                descontoSexo = 0;
            }

        if(idade >= 30){
            descontoIdadeBeta = valorSeguroBeta - (0.1 * valorSeguroBeta);
        }
            else   
                descontoIdadeBeta = 0;

        valorCarroBeta = valorSeguroBeta - descontoIdadeBeta - descontoSexo;

        printf("\nO valor do seguro é igual a: R$ %.2f", valorCarroBeta);
        printf("\n\nForneça o sexo \n 1 - Feminino \n 2 - Masculino \n Opção:");
        scanf("%d", &sexo);
        printf("\nForneça a idade (maior que 18 anos):");
        scanf("%d", &idade);
        printf("\nForneça o valor do carro (sem pontos e maior ou igual a 10000):");
        scanf("%f", &valorCarro);
    }

    return 0;
}