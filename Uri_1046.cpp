#include<stdio.h>
int main(){
    int a,b,duracao;
    scanf("%d %d",&a,&b);
    duracao=24 - a + b;
    if (duracao > 24)
        printf("O JOGO DUROU %d HORA(S)\n",duracao-24);
    else
        printf("O JOGO DUROU %d HORA(S)\n",duracao);

    return 0;

}
