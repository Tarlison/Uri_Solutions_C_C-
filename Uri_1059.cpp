#include<stdio.h>
int main(){
    int a = 100,cont = 1;
    for (cont; cont<=a; cont++){
        if (cont%2 == 0){
        printf("%d\n",cont);
        }
    }
    return 0;
}