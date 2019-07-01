#include <stdio.h>
int main(){
    int x,cem = 0, cinq = 0,vinte = 0,dez = 0, cinco = 0, dois = 0, um = 0,z;
    scanf("%d",&x);
    z = x;

    while (x != 0){
        while  (x >= 100){
            x -= 100;
            cem += 1;
        }
        while   (x >= 50){
            x -= 50;
            cinq += 1;
        }
        while   (x >= 20){
            x -= 20;
            vinte += 1;
        }
        while   (x >= 10){
            x -= 10;
            dez += 1;
        }
        while   (x >= 5){
            x -= 5;
            cinco += 1;
        }
        while   (x >= 2){
            x -= 2;
            dois += 1;
        }
        while   (x >= 1){
            x -= 1;
            um += 1;
        }
    }
    printf("%d\n",z);
    printf("%d nota(s) de R$ 100,00\n",cem);
    printf("%d nota(s) de R$ 50,00\n",cinq);
    printf("%d nota(s) de R$ 20,00\n",vinte);
    printf("%d nota(s) de R$ 10,00\n",dez);
    printf("%d nota(s) de R$ 5,00\n",cinco);
    printf("%d nota(s) de R$ 2,00\n",dois);
    printf("%d nota(s) de R$ 1,00\n",um);
    return 0;
}