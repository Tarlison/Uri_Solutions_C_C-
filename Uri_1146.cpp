#include<stdio.h>

int main(){
    int x,y = 1;
    scanf("%d",&x);

    while (x != 0){
        for (y; y <= x; y++){
            if (y < x){
                printf("%d ",y);
            }
            else{
                printf("%d\n",y);

            }
        }
        y = 1;
        scanf("%d",&x);

    }

    return 0;
}