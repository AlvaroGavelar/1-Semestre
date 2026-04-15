/*Um explorador registra criaturas mágicas. Cada criatura possui:
- Código do tipo (1, 2 ou 3)
- Nível de poder (1 a 300)
O programa deve:
1. Ler criaturas até que o código seja 0.
2. Se o código for inválido, pedir novamente.
3. Calcular:
 - Quantas criaturas de cada tipo
 - O maior nível registrado
 - A média dos níveis
 - Quantas criaturas têm nível maior que 200
*/

// Ler Codigo e Nivel (0 Finaliza) > Abrir Loop > Verificar o Codigo e repertir ate validar > Guardar Maior nivel > Qntd de Cada > Media dos Niveis > Qtds +200 nivel

#include <stdio.h>

int main (){
    int nivel, codigo, maiorNivel, qntd1=0, qntd2=0; 
    int qntd3=0, qntd200=0, primeiro=1, somaNivel=0, contador=0;

    //Leitura
    printf("Forneça o codigo da criatura (1, 2 ou 3) ou digite 0 (zero para finalizar):");
    scanf("%d", &codigo);
    

    //Loop
    while(codigo != 0){

        //Validar Código
        while(codigo < 0 || codigo > 3){
            printf("\nCodigo Errado!");
            printf("\nForneça o codigo da criatura (1, 2 ou 3) ou digite 0 (zero para finalizar):");
            scanf("%d", &codigo);
        }

        printf("Forneça o nivel de poder (1 a 300):");
        scanf("%d", &nivel);

        //Validar poder
        while(nivel < 1 || nivel > 300){
            printf("\nNível dePoder incompativel!");
            printf("\nForneça o nivel de poder (1 a 300):");
            scanf("%d", &nivel);
        }

        //Contador
        contador++;

        //Maior Nivel de Poder
        if(primeiro == 1){
            maiorNivel = nivel;
            primeiro = 0;
        }
        else if(nivel > maiorNivel){
            maiorNivel = nivel;
        }

        //Quantidade de Cada
        switch(codigo){
            case 1:
                qntd1++;
                break;
            case 2:
                qntd2++;
                break;
            case 3:
                qntd3++;
                break;
        }

        //Soma
        somaNivel+=nivel;

        //Quantidade Nivel 200+
        if(nivel > 200)
        qntd200++;

        printf("\nForneça o codigo da criatura (1, 2 ou 3) ou digite 0 (zero para finalizar):");
        scanf("%d", &codigo);

    }

    if(contador > 0){
        printf("\nQuantidade de cada criatura:");
        printf("\nCriatura 1: %d", qntd1);
        printf("\nCriatura 2: %d", qntd2);
        printf("\nCriatura 3: %d", qntd3);
        printf("\nMaior nível: %d", maiorNivel);
        printf("\nMédia: %.2f", (float)somaNivel/contador);
        printf("\nQuantidade de criaturas com nível maior que 200: %d", qntd200);
    }

    if(codigo == 0){
        printf("\nPrograma Finalizado!");
    }

    return 0;
}