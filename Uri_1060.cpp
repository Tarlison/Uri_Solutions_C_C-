#include <stdio.h>
int main(){
    float x;
    int contador1 = 1;
    int contador2 = 0;
    while(contador1 <= 6){
        scanf("%f",&x);
        if (x > 0){
            contador2 = contador2 + 1;
        }
        contador1 = contador1 + 1;
    }
    printf("%d valores positivos\n",contador2);
    return 0;
}