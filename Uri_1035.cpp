#include <stdio.h>
int main(){
    int a,b,c,d,soma1,soma2,resto;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    soma1 = c + d;
    soma2 = a + b;
    resto = a%2;
    if (b > c){
            if (d > a){
                if (soma1 > soma2){
                    if (c > 0){
                        if (d > 0){
                            if (resto ==0){
                                printf ("Valores aceitos\n");
                            }
                        }
                        else{
                            printf("Valores nao aceitos\n");
                        }
                    }
                    else{
                        printf("Valores nao aceitos\n");
                    }
                }
                else{
                    printf("Valores nao aceitos\n");
                }
            }
            else{
                printf("Valores nao aceitos\n");
            }
    }
    else{
        printf("Valores nao aceitos\n");
    }
return 0;
}
