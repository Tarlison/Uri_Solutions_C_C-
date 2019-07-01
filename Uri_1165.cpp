#include <stdio.h>
int main(){
    int n,x,cont = 0,a = 1,cont2 = 0;
    scanf("%d",&n);
    while (cont2 < n){
        scanf("%d",&x);
        for (a;a <= x; a++){
            if (x%a == 0){
            cont += 1;
            }
        }
        a = 1;
        if (cont == 2){
            printf("%d eh primo\n",x);
        }
        else{
            printf("%d nao eh primo\n",x);
        }
        cont = 0;
        cont2 += 1;
    }
    return 0;
}