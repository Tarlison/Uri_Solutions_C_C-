#include <stdio.h>
int main() {
 float  x,total,media;
  int cont,totalx;
     totalx = 0;
     total = 0;
     media = 0;
  
        for (cont = 1; cont <= 6; cont++) {
          scanf("%f", &x);
        if (x > 0) {
          totalx += 1;
          total += x;
       }
      }
      media = total / totalx;

     printf("%d valores positivos\n", totalx);
     printf("%.1f\n",media);
    return 0;
}