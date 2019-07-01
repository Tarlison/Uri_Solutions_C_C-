#include <stdio.h>
#import <math.h>
int main(){
    double a,b,c,r1,r2,delta;
    scanf("%lf %lf %lf",&a,&b,&c);
    delta = (b*b) - (4*a*c);
    if (delta >= 0){
            if (a != 0){
                r1 = ((b*(-1)) + (sqrt(delta))) / (2 * a);
                r2 = ((b*(-1)) - (sqrt(delta))) / (2 * a);
                printf("R1 = %.5f\n",r1);
                printf("R2 = %.5f\n",r2);
            }
            else{
                printf("Impossivel calcular\n");
            }
    }
    else{
        printf("Impossivel calcular\n");
    }
    return 0;
}