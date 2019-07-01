#include <stdio.h>
int main(){
        int tempo,vm;
        float gasto;
        scanf("%d %d",&tempo,&vm);
        gasto = (vm * tempo) / 12.0;
        printf("%.3f\n",gasto);
        return 0;
}
