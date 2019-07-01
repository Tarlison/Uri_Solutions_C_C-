#include <stdio.h>
int main(){
    float a[100], x;
    int i = 0;
    for (i = 0; i < 100; i++){
        scanf("%f",&x);
        if (x <= 10){
            printf("A[%d] = %.1f\n",i,x);
        }
    }
    return 0;
}