#include <stdio.h>
 
int main() {
    int cod,quant;
    scanf("%d %d",&cod,&quant);
    if (cod == 1){
        printf ("Total: R$ %.2f\n",quant * 4.00);
    }
    if (cod == 2){
        printf ("Total: R$ %.2f\n",quant * 4.50);
    }
    if (cod == 3){
        printf ("Total: R$ %.2f\n",quant * 5.00);
    }
    if (cod == 4){
        printf ("Total: R$ %.2f\n",quant * 2.00);
    }
    if (cod == 5){
        printf ("Total: R$ %.2f\n",quant * 1.50);
    }
 
    return 0;
}