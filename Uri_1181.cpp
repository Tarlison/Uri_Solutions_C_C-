#include <stdio.h>
int main(){
    int linha, i = 0, j = 0;
    float v[12][12],soma = 0,media = 0;
    char op;
    scanf("%d",&linha);
    scanf(" %c",&op);
    for (i = 0; i < 12; i++){
        for (j = 0; j < 12; j++){
            scanf("%f",&v[i][j]);
            if (i==linha){
                soma = soma + v[linha][j];
            }
        }
    }
    if (op == 'S'){
        printf("%.1f\n",soma);
    }
    else{
        media = soma / 12;
        printf("%.1f\n",media);
    }
    return 0;
}