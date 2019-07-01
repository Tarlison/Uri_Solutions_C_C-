#include<stdio.h>
int main(){
    int n,x,cont = 0, i = 0,aux;
    scanf("%d",&n);
    aux = n;
    for (i; i < n; i++){
        scanf("%d",&x);
        if (x >= 10 && x <= 20){
            cont += 1;
        }
    }
    printf("%d in\n",cont);
    printf("%d out\n",aux - cont);
    return 0;
}