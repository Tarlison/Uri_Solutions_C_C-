#include <stdio.h>
int main(){
    int p, j1, j2, r, a, ganhador, soma;
    scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);
    soma = j1 + j2;
    if((soma%2==0 && p==1) || (soma%2==1 && p==0)) ganhador = 1;
    else ganhador = 2;
    if((r==1 && a==0) || (r==0 && a==1)) ganhador = 1;
    else if(r==1 && a==1) ganhador=2;
    printf("Jogador %d ganha!\n", ganhador);

    return 0;
}