#include <stdio.h>
int main(){
    int n[10],x,aux = 0,i = 0,aux2 = 0;
    scanf("%d",&x);
    aux = x;
    for(i = 0; i < 10; i++){
        printf("N[%d] = %d\n",i,aux);
        aux2 = aux * 2;
        aux = aux2;
    }
    return 0;
}