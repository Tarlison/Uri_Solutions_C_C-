#include<stdio.h>
int main(){
    int x[10],i = 0,y;
    for (i = 0; i < 10; i++){
        scanf("%d",&y);
        if (y > 0){
            printf("X[%d] = %d\n",i,y);
        }
        else{
            printf("X[%d] = 1\n",i);
        }
    }
    return 0;
}