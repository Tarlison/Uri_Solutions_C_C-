#include <stdio.h>
int main(){
    int n[20],x,i = 0,j = 0,aux;
    for (i = 0; i < 20; i++){
        scanf("%d",&x);
        n[i] = x;
    }
    i = 19;
    while (j < 10){
        aux = n[j];
        n[j] = n[i];
        n[i] = aux;
        j = j + 1;
        i = i - 1;
    }
    for (i = 0; i < 20; i++){
        printf("N[%d] = %d\n",i,n[i]);
    }
    return 0;
}