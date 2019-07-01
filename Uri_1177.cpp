#include<stdio.h>
int main(){
    int n[1000],t,i = 0,aux = 0;
    scanf("%d",&t);
    for (i = 0; i < 1000; i++){
        printf("N[%d] = %d\n",i,aux);
        aux = aux + 1;
        if (aux == t){
            aux = 0;
        }
    }
    return 0;
}