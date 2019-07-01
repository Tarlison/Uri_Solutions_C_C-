#include<stdio.h>
int main(){
    char nome;
    double salario,bonus,x;
    scanf("%s",&nome);
    scanf("%lf %lf",&salario, &bonus);
    x = salario + (15*bonus)/100;
    printf("TOTAL = R$ %.2lf\n",x);
    return 0;
}