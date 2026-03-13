#include <stdio.h>
#include <math.h>
int main(){
    float gorgeta, vt, vg, comissao, vgorjeta;
        printf("Valor da conta:");
        scanf("%f", &vg);
        vgorjeta=vg*0.1;
        printf("O valor da gorjeta é:%.0f\n", vgorjeta);
        vt=vgorjeta+vg;
        printf("O valor total é igual a: %.0f", vt);
        return 0;
}