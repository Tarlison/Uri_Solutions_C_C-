#include <stdio.h>
int main(){
    int n,cont = 0;
    float media = 0.0;
    scanf("%d",&n);
    while (n > 0){
        media += n;
        cont += 1;
        scanf("%d",&n);
    }
    printf("%.2f\n",media/cont);
    return 0;
}