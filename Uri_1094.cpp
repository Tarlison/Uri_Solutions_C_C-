#include <stdio.h>
int main(){
    int n,quantia,cont = 0,quant_coelho = 0,quant_rato = 0,quant_sapo = 0;
    int total;
    char tipo;
    float porc_c, porc_r,porc_s;

    scanf("%d",&n);

    for (cont; cont < n; cont++){
        scanf("%d %c",&quantia, &tipo);
        if (tipo == 'C'){
            quant_coelho += quantia;
        }
        else if (tipo == 'R'){
            quant_rato += quantia;
        }
        else{
            quant_sapo += quantia;
        }
    }
    
    total = quant_sapo + quant_rato + quant_coelho;
    porc_c = (100.00*quant_coelho) / total;
    porc_r = (100.00*quant_rato) / total;
    porc_s = (100.00*quant_sapo) / total;
    
    printf("Total: %d cobaias\n",total);
    printf("Total de coelhos: %d\n",quant_coelho);
    printf("Total de ratos: %d\nTotal de sapos: %d\n",quant_rato,quant_sapo);
    printf("Percentual de coelhos: %.2f %%\n",porc_c);
    printf("Percentual de ratos: %.2f %%\n",porc_r);
    printf("Percentual de sapos: %.2f %%\n",porc_s);
    
    return 0;
}
