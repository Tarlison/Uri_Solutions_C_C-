#include<stdio.h>
int main(){
    int numero,horas;
    float valor;
    scanf("%d %d %f",&numero, &horas, &valor);
    printf("NUMBER = %d\n",numero);
    printf("SALARY = U$ %.2f\n",horas*valor);
    return 0;

}