#include<stdio.h>
int main(){
    int n = -1,cont1 = 0,cont2 = 0,cont3 = 0;

    while (n != 4){
        scanf("%d",&n);

        if (n >= 1 && n <= 3){
            if (n ==  1){
                cont1 += 1;
            }
            else if(n == 2){
                cont2 += 1;
            }
            else if (n == 3){
                cont3 += 1;
            }
        }

    }
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",cont1,cont2,cont3);
    return 0;
}